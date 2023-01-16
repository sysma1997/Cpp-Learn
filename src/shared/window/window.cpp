#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <sqlite3.h>

#include "./window.h"

#include "../global.h"
#include "./ui/ui.h"
#include "./ui/screens/screenMain.h"

Window::Window(sqlite3 *db)
{
    this->db = db;
}
void Window::init(UI *ui)
{
    if (!glfwInit())
    {
        throw "Error to init GLFW";
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;
    window = glfwCreateWindow(Global::windowWidth, Global::windowHeight, "Window", NULL, NULL);
    if (window == NULL)
    {
        throw "Error to open window with GLFW, if use old GPU, it's not compatible with OpenGL 3.3";
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewExperimental = true;

    if (glewInit() != GLEW_OK)
    {
        throw "Error to init GLEW";
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    ui->init(window);

    while (glfwWindowShouldClose(window) == 0)
    {
        glfwPollEvents();

        try
        {
            ui->newFrame(window);
        }
        catch (std::string error)
        {
            throw error;
        }

        glfwGetFramebufferSize(window, &Global::windowWidth, &Global::windowHeight);
        glViewport(0, 0, Global::windowWidth, Global::windowHeight);
        glClear(GL_COLOR_BUFFER_BIT);

        ui->renderDrawData();

        glfwSwapBuffers(window);
    }

    ui->destroy();

    glfwDestroyWindow(window);
    glfwTerminate();
}