//
// Created by minky on 2024-01-19.
//

#include <iostream>
#include "GLFW/glfw3.h"

#include "Assert.h"
#include "Log.h"

static void glfw_error_callback( int error_code, const char* description ) noexcept
{
  // TODO: handle error
}

static void glfw_window_resize_callback( GLFWwindow* currentWindow, int width, int height )
{
  std::cout << "window resize\n";
}

static void glfw_window_close_callback( GLFWwindow* currentWindow )
{
  std::cout << "window close\n";
}

static void glfw_window_position_callback( GLFWwindow* currentWindow, int xpos, int ypos )
{
  std::cout << "window move\n";
}

static void glfw_mouse_scroll_callback( GLFWwindow* window, double xOffset, double yOffset )
{
  std::cout << "mouse scroll\n";
}

static void glfw_mouse_button_callback( GLFWwindow* window, int button, int action, int mode )
{
  std::cout << "mouse click\n";
}
static void glfw_mouse_cursor_pos_callback( GLFWwindow* window, double xPos, double yPos )
{
  std::cout << "mouse cursor pos\n";
}
static void glfw_key_button_callback( GLFWwindow* window, int key, int code, int action, int mode )
{
  std::cout << "keyboard button click\n";
}

int main( int argc, char** argv )
{
  // TODO
  // if you hover it, hold down the mouse button and drag it,
  // it adds the mouse pos drag delta to the window pos as long as it's not maximized.


  (void)argc;
  (void)argv;
  LOG_INFO( "Main start!" );

  glfwSetErrorCallback( glfw_error_callback );
  if ( glfwInit() == false )
  {
    // ... error! exit program with error message log
    return 1;
  }
  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );                // OpenGL major version
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );                // OpenGL minor version
  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );// Core profile = No Backwards Compatibility
  glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );          // Allow forward compatibility
  glfwWindowHint( GLFW_DECORATED, GLFW_FALSE );

  // 아래는 모든 윈도우에 대해 적용.
  GLFWwindow* windowPtr = glfwCreateWindow( 500, 500, "CUI", nullptr, nullptr );
  if ( !windowPtr )
  {
    // ... error! exit program with error message log
    glfwTerminate();
    return 1;
  }
  // window event
  glfwSetWindowSizeCallback( windowPtr, glfw_window_resize_callback );
  glfwSetWindowCloseCallback( windowPtr, glfw_window_close_callback );
  glfwSetWindowPosCallback( windowPtr, glfw_window_position_callback );

  // mouse & keyboard event
  glfwSetScrollCallback( windowPtr, glfw_mouse_scroll_callback );
  glfwSetMouseButtonCallback( windowPtr, glfw_mouse_button_callback );
  glfwSetCursorPosCallback( windowPtr, glfw_mouse_cursor_pos_callback );
  glfwSetKeyCallback( windowPtr, glfw_key_button_callback );

  // set window attribute
  glfwSetWindowAttrib( windowPtr, GLFW_RESIZABLE, GLFW_TRUE );
  glfwSetWindowPos( windowPtr, 100, 100 );

  // set glfw render context
  glfwSwapInterval( 1 );
  glfwMakeContextCurrent( windowPtr );

  while ( !glfwWindowShouldClose( windowPtr ) )
  {
    // 1. poll event
    glfwPollEvents();

    //    int x, y;
    //    glfwGetWindowPos( windowPtr, &x, &y );
    //    glfwSetWindowPos( windowPtr, x + 1, y );
    // 2. get event from event queue.

    // 3. if event, calculate 2d

    // 4. render 3d context on every loop (Model Viewer)

    // 5. finalize draw operation. (draw 2d screen)
    glfwSwapBuffers( windowPtr );
  }

  glfwTerminate();
  return 0;
}