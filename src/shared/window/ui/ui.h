#pragma once

#include <GLFW/glfw3.h>

class UI
{
public:
    void init(GLFWwindow *window);
    void newFrame(GLFWwindow *window);
    void renderDrawData();
    void destroy();
};