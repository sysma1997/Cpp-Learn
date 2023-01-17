#include <string>
#include <vector>

#include "./screenMain.h"

#include "../../../../../libs/imgui/imgui.h"
#include "../../../../../libs/imgui/imgui_impl_glfw.h"
#include "../../../../../libs/imgui/imgui_impl_opengl3.h"

#include "../../../global.h"

void screenMain()
{
    ImGui::SetNextWindowPos(ImVec2(0, 20));
    ImGui::SetNextWindowSize(ImVec2(Global::windowWidth / 100 * 20, Global::windowHeight - 20));
    ImGui::Begin("Contacts", nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse);

    ImGui::Text("Your contacts: %d", Global::contacts.size());

    if (Global::contacts.size() > 0)
    {
        ImGui::Text("Search");
        ImGui::InputText("##Search", Global::search, IM_ARRAYSIZE(Global::search));

        ImGui::NewLine();
        ImGui::BeginListBox("##Contacts");
        for (int i = 0; i < Global::contacts.size(); i++)
        {
            Contact contact{Global::contacts.at(i)};

            std::string search(Global::search);
            if (search != "")
            {
                // https://stackoverflow.com/questions/651497/how-to-do-stdstring-indexof-in-c-that-returns-index-of-matching-string
                std::string::size_type match = contact.getName().find(search, 0);
                if (match != std::string::npos)
                {
                    continue;
                }
            }

            if (ImGui::Selectable(contact.getName().c_str()))
            {
                Global::contact = contact;
                Global::showScreenContact = true;
            }
        }
        ImGui::EndListBox();
    }

    if (ImGui::Button("Create"))
    {
        Global::contact = Contact();
        Global::showScreenContact = true;
    }

    ImGui::End();
}