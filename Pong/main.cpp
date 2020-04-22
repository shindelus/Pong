
#include "glew/include/GL/glew.h"
#include "glfw/include/GLFW/glfw3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>

#include "renderer.h"
#include "vertexbuffer.h"
#include "vertexbufferlayout.h"
#include "indexbuffer.h"
#include "vertexarray.h"
#include "shader.h"

#include "ball.h"
#include "paddle.h"
#include "game.h"
#include "helpers.h"
#include "vertices.h"
#include "letters.h"
#include "word.h"
#include "transfer.h"

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"


#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>



//#define BUFLEN 2048
//#define MSGS 5


float windowHeight = 800.0f;
float windowWidth = 1300.0f;

Game game(windowHeight, windowWidth);
Paddle paddle1(50.0f, (windowHeight/2.0f) - 70.0f, true);
Paddle paddle2(windowWidth - 70.0f, (windowHeight/2.0f) - 70.0f, false);
Ball ball;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_DOWN)
    {
        if (action == GLFW_PRESS)// || action == GLFW_REPEAT)
        {
            paddle2.isMovingDown = true;
        } else if (action == GLFW_RELEASE)
        {
            paddle2.isMovingDown = false;
        }
    } else if (key == GLFW_KEY_UP)
    {
        if (action == GLFW_PRESS)// || action == GLFW_REPEAT)
        {
            paddle2.isMovingUp = true;
        } else if (action == GLFW_RELEASE)
        {
            paddle2.isMovingUp = false;
        }
    }
    
    if (key == GLFW_KEY_1 && game.online == 0)
        game.online = 1;
    if (key == GLFW_KEY_2 && game.online == 0)
        game.online = 2;
}

int main(void)
{
    
    Transfer transfer;

    GLFWwindow* window;
    
    // Initialize the library
    if (!glfwInit())
        return -1;

    // Use the core profile to enforce our own implementation of a vertex array
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Synchronize the refresh rate with our native refresh rate
    glfwSwapInterval(1);
    
    // Initialize Glew
    if (glewInit() != GLEW_OK)
        std::cout << "glewInit error!" << std::endl;

    // Log the OpenGL version used because we can
    std::cout << glGetString(GL_VERSION) << std::endl;
    
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // The indexes of the vertices we want to draw
    unsigned int indices[1500];
    int x = 0;
    int y = 0;
    while (x < 1500)
    {
        indices[x] = y;
        indices[x + 1] = y + 1;
        indices[x + 2] = y + 2;
        indices[x + 3] = y + 2;
        indices[x + 4] = y + 3;
        indices[x + 5] = y;
        x = x + 6;
        y = y + 4;
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    VertexArray va; // Initialize our vertex array
    VertexBuffer vb(nullptr, 1000 * sizeof(float)); // Create and bind a buffer for the vertices
    VertexBufferLayout layout; // Create a layout for the buffer we created
    layout.Push<float>(2);

    va.AddBuffer(vb, layout);
    
    IndexBuffer ib(indices, 1500); // Create and bind a buffer for the indices
    
    glm::mat4 proj = glm::ortho(0.0f, windowWidth, 0.0f, windowHeight, -1.0f, 1.0f);
//    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
//    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));
//    glm::mat4 mvp = proj * view * model;
           
    Shader shader("basic.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
    shader.SetUniformMat4f("u_MVP", proj);
    
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

    Renderer renderer;
    
    
    glfwSetKeyCallback(window, key_callback);

    // Animation stuff

    // Loop until the user closes the window
    int change = 150;
    bool p1Text = true;
    
    while (!glfwWindowShouldClose(window))
    {
        
        renderer.Clear();

        shader.Bind();
        shader.SetUniform4f("u_Color", game.red, game.green, game.blue, 1.0);
        
        Vertices v;
        
        if (game.online == 0)
        {
            Word a("pong", 400.0f, 450.0f, 150.0f, v);
            if (change == 0){
                p1Text = !p1Text;
                change = 150;
            }
            if (p1Text)
            {
                Word b("press 1 for player vs computer", 200.0f, 380.0f, 40.0f, v);
            } else {
                Word c(" press 2 for 2 player online  ", 200.0f, 380.0f, 40.0f, v);
            }
            change--;
        } else {
            game.CreateBall(ball.Xposition, ball.Yposition, ball.width, ball.height, v);
            v.AddVertData(paddle1.Xposition, paddle1.Yposition, paddle1.width, paddle1.height);
            v.AddVertData(paddle2.Xposition, paddle2.Yposition, paddle2.width, paddle2.height);
            v.AddVertData(0.0f, windowHeight - 60.0f, windowWidth, 5.0f);
                
            if (game.online == 1)
                game.AddTextForOffline(v);
            else if (game.online == 2)
                game.AddTextForOnline(v);
        }
        
        Vertex vertices[v.m_vertData.size()];
        std::copy(v.m_vertData.begin(), v.m_vertData.end(), vertices);
        
        int filler[2000] = {0};
        glBindBuffer(GL_ARRAY_BUFFER, 1); // Select the buffer to be drawn
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Add the data to the buffer
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(filler), filler);
        renderer.Draw(va, ib, shader);
        
        game.OnUpdate(paddle1, paddle2, ball, transfer);
        
        glfwSwapBuffers(window); // Swap front and back buffers
        glfwPollEvents(); // Poll for and process events
        
        glBufferData(GL_ARRAY_BUFFER, 3000 * sizeof(Vertex), NULL, GL_STREAM_DRAW);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    glfwTerminate();
    return 0;
}
