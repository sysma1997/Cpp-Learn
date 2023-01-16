#include <math.h>

#include "./screenMain.h"

#include "../../../../../libs/imgui/imgui.h"
#include "../../../../../libs/imgui/imgui_impl_glfw.h"
#include "../../../../../libs/imgui/imgui_impl_opengl3.h"

#include "../../../global.h"

void screenMain()
{
    ImGui::SetNextWindowPos(ImVec2(0, 20));
    ImGui::SetNextWindowSize(ImVec2(Global::windowWidth / 100 * 20, Global::windowHeight - 20));
    ImGui::Begin("Contacts", &Global::showScreenMain, ImGuiWindowFlags_AlwaysAutoResize);

    ImGui::Text("Your contacts: %d", 0);

    ImGui::End();
}