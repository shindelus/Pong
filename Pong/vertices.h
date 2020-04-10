
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <vector>

struct Vec2
{
    float x, y;
};
#pragma once

struct Vec3
{
    float x, y, z;
};

struct Vec4
{
    float x, y, z, w;
};

struct Vertex
{
    Vec2 position;
//    Vec4 color;
};

class Vertices
{
public:
    std::vector<Vertex> m_vertData;
    Vertices(){};
    ~Vertices(){};
    void AddVertData(float x, float y, float w, float h);
};



