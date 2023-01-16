#include <string>

#include "./screenContact.h"

#include "../../../../../libs/imgui/imgui.h"
#include "../../../../../libs/imgui/imgui_impl_glfw.h"
#include "../../../../../libs/imgui/imgui_impl_opengl3.h"

#include "../../../global.h"

void screenContact()
{
    ImGui::Begin("Learning", &Global::showScreenContact);
    ImGui::Text("New contact");

    ImGui::End();
}