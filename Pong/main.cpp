
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"



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
}

int main(void)
{
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
           
    Shader shader("Pong/basic.shader");
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
    float r = 0.0f;
    float increment = 0.05f;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        renderer.Clear();

        shader.Bind();
        shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);
        
        Vertices v;

        v.AddVertData(ball.Xposition, ball.Yposition, ball.width, ball.height);
        v.AddVertData(paddle1.Xposition, paddle1.Yposition, paddle1.width, paddle1.height);
        v.AddVertData(paddle2.Xposition, paddle2.Yposition, paddle2.width, paddle2.height);
        v.AddVertData(0.0f, windowHeight - 60.0f, windowWidth, 5.0f);
        
        if (game.countDownToStart > 150.0f && game.countDownToStart <= 200.0f)
        {
            Word w("start", 570.0f, 400.0f, 50.0f, v);

        } else if (game.countDownToStart > 100.0f && game.countDownToStart <= 150.0f)
        {
            Word w("  3  ", 570.0f, 400.0f, 50.0f, v);

        } else if (game.countDownToStart > 50.0f && game.countDownToStart <= 100.0f)
        {
            Word w("  2  ", 570.0f, 400.0f, 50.0f, v);

        } else if (game.countDownToStart > 0.0f && game.countDownToStart <= 50.0f)
        {
            Word w("  1  ", 570.0f, 400.0f, 50.0f, v);
        }
        
        std::stringstream p1ScoreStr;
        p1ScoreStr << game.player1Score;
        Word scoreP1(p1ScoreStr.str(), 30.0f, game.windowHeight - 45.0f, 35.0f, v);
        
        std::stringstream p2ScoreStr;
        p2ScoreStr << game.player2Score;
        Word scoreP2(p2ScoreStr.str(), game.windowWidth - 50.0f, game.windowHeight - 45.0f, 35.0f, v);
        
        std::stringstream levelStr;
        levelStr << game.level;
        Word level("level " + levelStr.str(), (game.windowWidth/2) - 75.0f, game.windowHeight - 45.0f, 35.0f, v);


        Vertex vertices[v.m_vertData.size()];
        std::copy(v.m_vertData.begin(), v.m_vertData.end(), vertices);
        
        printf("size of vertices is %lu\n", sizeof(vertices[0]));

        int filler[1000];
        glBindBuffer(GL_ARRAY_BUFFER, 1); // Select the buffer to be drawn
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Add the data to the buffer
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(filler), filler);
        
        renderer.Draw(va, ib, shader);
        
        
        if (paddle2.isMovingUp)
        {
            game.MovePaddleUp(paddle2);
        } else if (paddle2.isMovingDown)
        {
            game.MovePaddleDown(paddle2);
        }
        
        
        game.OnUpdate(paddle1, paddle2, ball);
        
        
        // Animate the r value between 0.0 and 1.0
        if (r > 1.0f)
            increment = -0.05f;
        else if (r < 0.0f)
            increment = 0.05f;
        r += increment;

        glfwSwapBuffers(window); // Swap front and back buffers
        glfwPollEvents(); // Poll for and process events
        
        glBufferData(GL_ARRAY_BUFFER, 1000 * sizeof(Vertex), NULL, GL_STREAM_DRAW);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    glfwTerminate();
    return 0;
}
