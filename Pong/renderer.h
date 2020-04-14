  
#pragma once

#include "glew/include/GL/glew.h"
#include "vertexarray.h"
#include "indexbuffer.h"
#include "shader.h"

/**
Clear all (unrelated) previous errors.
*/
//void GLClearError();

/**
Check for an error and log the error to the console.
@param function The function where the error happend
@param file The file where the error happend
@param line The line number where the error happend
@return Whether there was an error
*/
//bool GLLogCall(const char* function, const char* file, int line);

class Renderer
{
public:
    void Clear() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};
