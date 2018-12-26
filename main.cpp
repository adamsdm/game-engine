
#include <stdio.h>
#include <glm/glm.hpp>
#include <iostream>
#include <math.h>

#include "core.h"

int main(){

  GE::AppWindow appWindow(800, 600);  
  GE::Scene scene;
  GE::Renderer renderer(appWindow);
  
  float WindowRatio = (float)appWindow.Get_Width() / (float)appWindow.Get_Height();
  GE::Camera::PerspectiveCamera camera( 75, WindowRatio, 0.1, 1000);
  camera.Set_Position(glm::vec3(0.0f, 0.0f, 4.0f));
    
  renderer.Set_Clear_Color(0.1f, 0.1f, 0.1f, 1.0f);
  renderer.Set_Size( appWindow.Get_Width(), appWindow.Get_Height());

  GE::Geometry::BoxGeometry geometry( 1, 1, 1 );
  GE::Material::MeshBasicMaterial material(1.0f, 0.0f, 0.0f);

  GE::Mesh cube(geometry, material);

  scene.add(cube);

  /************************************/
  /************************************/
  /************************************/
  // TODO: MOVE
  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
  float vertices[] = {
       0.5f,  0.5f, 0.0f,  // top right
       0.5f, -0.5f, 0.0f,  // bottom right
      -0.5f, -0.5f, 0.0f,  // bottom left
      -0.5f,  0.5f, 0.0f   // top left 
  };
  unsigned int indices[] = {  // note that we start from 0!
      0, 1, 3,  // first Triangle
      1, 2, 3   // second Triangle
  };
  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
  glBindBuffer(GL_ARRAY_BUFFER, 0); 

  // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

  // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
  // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
  glBindVertexArray(0); 
  /************************************/
  /************************************/
  /************************************/

  // Game loop
  while(!appWindow.Should_Close()){

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // draw our first triangle
    glUseProgram(material.Get_Program_ID());
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0); // no need to unbind it every time 

    glfwSwapBuffers(appWindow.Get_Ref());
    glfwPollEvents();
    //renderer.Render();
  }

  return 0;
}