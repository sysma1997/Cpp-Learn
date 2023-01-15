#include "window.h"

#include "../../libs/imgui/imgui.h"
#include "../../libs/imgui/imgui_impl_glfw.h"
#include "../../libs/imgui/imgui_impl_opengl3.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

using namespace glm;

void initWindow()
{
    if (!glfwInit())
    {
        std::cout << "Error to init GLFW" << std::endl;

        return;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;
    window = glfwCreateWindow(1024, 640, "Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Error to open window with GLFW, if use old GPU, it's not compatible with OpenGL 3.3"
                  << std::endl;
        glfwTerminate();

        return;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewExperimental = true;

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error to init GLEW" << std::endl;

        return;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    ImVec4 background = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    int counter = 0;

    while (glfwWindowShouldClose(window) == 0)
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Hello Window in C++ with GLEW, GLFW and ImGui");

        ImGui::Text("This is some useful text.");
        ImGui::ColorEdit4("Backgorund", (float *)&background);

        if (ImGui::Button("Button"))
            counter++;
        ImGui::SameLine();
        ImGui::Text("Counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
                    1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(background.x * background.w,
                     background.y * background.w,
                     background.z * background.w,
                     background.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}