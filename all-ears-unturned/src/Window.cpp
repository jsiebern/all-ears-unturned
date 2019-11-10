#include "Window.h"
#include <iostream>

Window::Window(int width, int height)
	:width_(width), height_(height)
{
	if (!glfwInit()) {
		std::cout << "Could not initialize GLFW";
	}

	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

	glfw_window_ = glfwCreateWindow(width_, height_, "All Ears Unturned", NULL, NULL);
	if (!glfw_window_) {
		glfwTerminate();
		std::cout << "Could not create window";
	}

	glfwSetWindowPos(glfw_window_, x_pos_, y_pos_);

	glfwMakeContextCurrent(glfw_window_);
}

void Window::Move(int x, int y)
{
	x_pos_ += x;
	y_pos_ += y;
	glfwSetWindowPos(glfw_window_, x_pos_, y_pos_);
}

void Window::ResizeHeight(int height)
{
	height_ = height;
	glfwSetWindowSize(glfw_window_, width_, height_);
}

void Window::UpdateSize()
{
	glfwSetWindowSize(glfw_window_, width_, height_);
}

