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
        Global::contactMessage = "Contact create success";
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

    std::string textButton = (Global::contact.getId() != 0) ? "Edit" : "Register";
    ImGui::NewLine();
    if (ImGui::Button(textButton.c_str()))
    {
        std::string name(Global::contactName);
        std::string email(Global::contactEmail);
        std::string phone(Global::contactPhone);

        if (Global::contact.getId() != 0)
        {
        }
        else
            contactRegister(name, email, phone);
    }

    textButton = (Global::contact.getId() != 0) ? "Remove" : "Clear";
    ImGui::SameLine();
    if (ImGui::Button(textButton.c_str()))
    {
        if (Global::contact.getId() != 0)
        {
        }
        else
            clearContact();
    }

    textButton = (Global::contact.getId() != 0) ? "Done" : "Cancel";
    ImGui::SameLine();
    if (ImGui::Button(textButton.c_str()))
    {
        clearContact();
        Global::showScreenContact = !Global::showScreenContact;
    }

    ImGui::End();
}