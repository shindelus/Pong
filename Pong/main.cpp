
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

#include "glm/glm/glm.hpp"
#include "glm/glm/gtc/matrix_transform.hpp"


#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>



#define BUFLEN 2048
#define MSGS 5


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

    int fd;
    
    float buf[BUFLEN];
    
    int recvlen;
    
    short int myport = 8888;

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("cannot create socket");
        return 1;
    }
    
    struct sockaddr_in myaddr;

    /* bind to an arbitrary return address */
    /* because this is the client side, we don't care about the address */
    /* since no application will initiate communication here - it will */
    /* just send responses */
    /* INADDR_ANY is the IP address and 0 is the socket */
    /* htonl converts a long integer (e.g. address) to a network representation */
    /* htons converts a short integer (e.g. port) to a network representation */

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(myport);

//        if (bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0) {
//            perror("bind failed");
//            return 1;
//        }
    
    
    
    int port = 1153;
    
    struct hostent *hp;     /* host information */
    struct sockaddr_in servaddr;    /* server address */

    /* fill in the server's address and data */
    memset((char*)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    
    char *host = "192.168.0.20";
    /* look up the address of the server given its name */
    hp = gethostbyname(host);
    if (!hp) {
        fprintf(stderr, "could not obtain address of %s\n", host);
    }

    /* put the host's address into the server address structure */
    memcpy((void *)&servaddr.sin_addr, hp->h_addr_list[0], hp->h_length);

    socklen_t slen = sizeof(servaddr);

    /* send a message to the server */
    float my_message[5] = { 10.0f, 20.0f, 30.0f, 40.0f , 50.0f };
    if (sendto(fd, &my_message, sizeof(my_message), 0, (struct sockaddr *)&servaddr, slen) < 0) {
        perror("sendto failed");
    }
    recvlen = recvfrom(fd, buf, BUFLEN, 0, (struct sockaddr *)&servaddr, &slen);
    if (recvlen >= 0) {
            buf[recvlen] = 0;
            printf("%f\n", (float)buf[0]);
            printf("%f\n", (float)buf[1]);
            printf("%f\n", (float)buf[2]);
            printf("%f\n", (float)buf[3]);
            printf("%f\n", (float)buf[4]);
    }
//
        
    
    
    
    
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
    
    while (!glfwWindowShouldClose(window))
    {
        
        renderer.Clear();

        shader.Bind();
        shader.SetUniform4f("u_Color", game.red, game.green, game.blue, 1.0);

        Vertices v;

        game.CreateBall(ball.Xposition, ball.Yposition, ball.width, ball.height, v);
        v.AddVertData(paddle1.Xposition, paddle1.Yposition, paddle1.width, paddle1.height);
        v.AddVertData(paddle2.Xposition, paddle2.Yposition, paddle2.width, paddle2.height);
        v.AddVertData(0.0f, windowHeight - 60.0f, windowWidth, 5.0f);
            
        game.AddText(v);
        
        Vertex vertices[v.m_vertData.size()];
        std::copy(v.m_vertData.begin(), v.m_vertData.end(), vertices);
        
//        if (paddle2.isMovingUp)
//        {
//            char *my_message = "MOVING UP!!!";
//            if (sendto(fd, my_message, strlen(my_message), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
//                perror("sendto failed");
//            }
//            recvlen = recvfrom(fd, buf, BUFLEN, 0, (struct sockaddr *)&servaddr, &slen);
//            if (recvlen >= 0) {
//        //                buf[recvlen] = 0;    /* expect a printable string - terminate it */
//                    printf("received message: \"%s\"\n", buf);
//            }
//        } else if (paddle2.isMovingDown)
//        {
//            char *my_message = "MOVING DOWN!!!";
//            if (sendto(fd, my_message, strlen(my_message), 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
//                perror("sendto failed");
//            }
//            recvlen = recvfrom(fd, buf, BUFLEN, 0, (struct sockaddr *)&servaddr, &slen);
//            if (recvlen >= 0) {
//        //                buf[recvlen] = 0;    /* expect a printable string - terminate it */
//                printf("received message: \"%s\"\n", buf);
//            }
//        }
        
        int filler[1000];
        glBindBuffer(GL_ARRAY_BUFFER, 1); // Select the buffer to be drawn
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Add the data to the buffer
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(filler), filler);
        renderer.Draw(va, ib, shader);
        
        game.OnUpdate(paddle1, paddle2, ball);
        
        glfwSwapBuffers(window); // Swap front and back buffers
        glfwPollEvents(); // Poll for and process events
        
        glBufferData(GL_ARRAY_BUFFER, 1000 * sizeof(Vertex), NULL, GL_STREAM_DRAW);
        
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    glfwTerminate();
    return 0;
}
