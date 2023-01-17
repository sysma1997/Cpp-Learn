#include <string>
#include <vector>

#include "./screenContact.h"

#include "../../../../../libs/imgui/imgui.h"
#include "../../../../../libs/imgui/imgui_impl_glfw.h"
#include "../../../../../libs/imgui/imgui_impl_opengl3.h"

#include "../../../global.h"

#include "../../../../contact/domain/contact.h"
#include "../../../../contact/application/create/contactCreate.h"
#include "../../../../contact/infrastructure/create/contactCreateSqlite.h"
#include "../../../../contact/application/edit/contactEdit.h"
#include "../../../../contact/infrastructure/edit/contactEditSqlite.h"
#include "../../../../contact/application/remove/contactRemove.h"
#include "../../../../contact/infrastructure/remove/contactRemoveSqlite.h"

void clearContact()
{
    memset(Global::contactName, 0, 100);
    memset(Global::contactEmail, 0, 100);
    memset(Global::contactPhone, 0, 20);

    Global::contactMessage = "";
}
void contactRegister(std::string name, std::string email, std::string phone)
{
    if (name == "" || phone == "")
    {
        std::string message;

        if (name == "")
            message += "Name is required.";
        if (phone == "")
            message += std::string((name == "") ? "\n" : "") + "Email is required.";

        Global::contactMessage = message;

        return;
    }

    Global::contactMessage = "";
    int id = Global::contacts.size() + 1;
    Contact contact{id, name, email, phone};

    ContactCreateSqlite repository(Global::db);
    ContactCreate create(&repository);

    try
    {
        create.init(contact);

        Global::contact = contact;
        Global::contacts.push_back(contact);

        clearContact();
    }
    catch (std::string error)
    {
        Global::contactMessage = error;
    }
}
void contactEdit(Contact contact)
{
    if (contact.getId() == 0 ||
        contact.getName() == "" ||
        contact.getPhone() == "")
    {
        std::string message;

        if (contact.getId() == 0)
            message += "Id not valid.";
        if (contact.getName() == "")
            message += std::string((contact.getId() == 0) ? "\n" : "") + "Name is required.";
        if (contact.getPhone() == "")
            message +=
                std::string((contact.getId() == 0 || contact.getName() == "") ? "\n" : "") +
                "Email is required.";

        Global::contactMessage = message;

        return;
    }

    Global::contactMessage = "";

    ContactEditSqlite repository(Global::db);
    ContactEdit edit(&repository);

    try
    {
        edit.init(contact);

        Global::contact = contact;

        int index = 0;
        for (int i = 0; i < Global::contacts.size(); i++)
        {
            if (Global::contacts[i].getId() == contact.getId())
            {
                index = i;
                break;
            }
        }
        Global::contacts[index] = contact;

        clearContact();
        Global::editContact = false;
    }
    catch (std::string error)
    {
        Global::contactMessage = error;
    }
}
void contactRemove(int id)
{
    if (id == 0)
    {
        std::string message;

        if (id == 0)
            message += "Id not valid.";

        Global::contactMessage = message;

        return;
    }

    ContactRemoveSqlite repository(Global::db);
    ContactRemove remove(&repository);

    try
    {
        remove.init(id);

        int index = 0;
        for (int i = 0; i < Global::contacts.size(); i++)
        {
            if (Global::contacts[i].getId() == id)
            {
                index = i;
                break;
            }
        }
        Global::contacts.erase(Global::contacts.begin() + index);

        clearContact();
        Global::contact = Contact();
        Global::showScreenContact = false;
    }
    catch (std::string error)
    {
        Global::contactMessage = error;
    }
}

void screenContact()
{
    std::string title = (Global::contact.getId() == 0) ? "Create contact" : Global::contact.getName();

    ImGui::Begin(title.c_str(), &Global::showScreenContact, ImGuiWindowFlags_AlwaysAutoResize);

    if (Global::contact.getId() == 0 ||
        Global::editContact)
    {
        ImGui::Text("Name*");
        ImGui::InputText("##Name", Global::contactName, IM_ARRAYSIZE(Global::contactName));
        ImGui::Text("Email");
        ImGui::InputText("##Email", Global::contactEmail, IM_ARRAYSIZE(Global::contactEmail));
        ImGui::Text("Phone*");
        ImGui::InputText("##Phone", Global::contactPhone, IM_ARRAYSIZE(Global::contactPhone));

        if (Global::contactMessage != "")
        {
            ImGui::NewLine();
            ImGui::Text(Global::contactMessage.c_str());
        }
    }
    else
    {
        ImGui::Text("Name");
        ImGui::Text(Global::contact.getName().c_str());
        ImGui::Text("Email");
        ImGui::Text(Global::contact.getEmail().c_str());
        ImGui::Text("Phone");
        ImGui::Text(Global::contact.getPhone().c_str());
    }

    std::string textButton = (Global::contact.getId() != 0) ? "Edit" : "Create";
    if (Global::editContact)
        textButton = "Update";
    ImGui::NewLine();
    if (ImGui::Button(textButton.c_str()))
    {
        std::string name(Global::contactName);
        std::string email(Global::contactEmail);
        std::string phone(Global::contactPhone);

        if (Global::contact.getId() != 0 && !Global::editContact)
        {
            strcpy(Global::contactName, Global::contact.getName().c_str());
            strcpy(Global::contactEmail, Global::contact.getEmail().c_str());
            strcpy(Global::contactPhone, Global::contact.getPhone().c_str());
            Global::editContact = true;
        }
        else if (Global::contact.getId() != 0 && Global::editContact)
        {
            Contact contact{
                Global::contact.getId(),
                Global::contactName,
                Global::contactEmail,
                Global::contactPhone};

            contactEdit(contact);
        }
        else
            contactRegister(name, email, phone);
    }

    textButton = (Global::contact.getId() != 0 && !Global::editContact) ? "Remove" : "Clear";
    ImGui::SameLine();
    if (ImGui::Button(textButton.c_str()))
    {
        if (Global::contact.getId() != 0 && !Global::editContact)
            ImGui::OpenPopup("Remove contact?");
        else
            clearContact();
    }

    textButton = (Global::contact.getId() != 0 && !Global::editContact) ? "Done" : "Cancel";
    ImGui::SameLine();
    if (ImGui::Button(textButton.c_str()))
    {
        if (Global::editContact)
            Global::editContact = false;
        else
        {
            clearContact();
            Global::showScreenContact = !Global::showScreenContact;
        }
    }

    /* MODAL REMOVE */
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    if (ImGui::BeginPopupModal("Remove contact?", NULL, ImGuiWindowFlags_AlwaysAutoResize))
    {
        std::string text = "Remove contact " + Global::contact.getName() + "?";
        ImGui::Text(text.c_str());
        ImGui::Separator();

        if (ImGui::Button("Yes", ImVec2(120, 0)))
        {
            contactRemove(Global::contact.getId());
            ImGui::CloseCurrentPopup();
        }
        ImGui::SetItemDefaultFocus();
        ImGui::SameLine();
        if (ImGui::Button("No", ImVec2(120, 0)))
            ImGui::CloseCurrentPopup();

        ImGui::EndPopup();
    }
    /* END MODAL REMOVE */

    ImGui::End();
}