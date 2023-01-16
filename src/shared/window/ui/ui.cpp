#include <string>
#include <GLFW/glfw3.h>

#include "ui.h"

#include "../../../../libs/imgui/imgui.h"
#include "../../../../libs/imgui/imgui_impl_glfw.h"
#include "../../../../libs/imgui/imgui_impl_opengl3.h"

#include "../../global.h"
#include "./screens/screenMain.h"

void UI::init(GLFWwindow *window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();
}
void UI::newFrame(GLFWwindow *window)
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (!ImGui::BeginMainMenuBar())
    {
        throw "ImGui error to begin main menu bar.";
    }

    if (ImGui::BeginMenu("Window"))
    {
        if (ImGui::MenuItem((!Global::showScreenMain) ? "Contacts: Show" : "Contacts: Hide"))
            Global::showScreenMain = !Global::showScreenMain;
        if (ImGui::MenuItem("exit"))
            glfwSetWindowShouldClose(window, true);

        ImGui::EndMenu();
    }

    ImGui::EndMainMenuBar();

    if (Global::showScreenMain)
        screenMain();

    ImGui::Render();
}
void UI::renderDrawData()
{
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void UI::destroy()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}