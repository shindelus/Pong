#include <vector>
#include "vertices.h"

void Vertices::AddVertData(float x, float y, float w, float h)
{
    Vertex v0;
    v0.position = { x, y };
    
    m_vertData.push_back(v0);
    
    Vertex v1;
    v1.position = { x + w, y };
    
    m_vertData.push_back(v1);
    
    Vertex v2;
    v2.position = { x + w, y + h };
    
    m_vertData.push_back(v2);
    
    Vertex v3;
    v3.position = { x, y + h };
    
    m_vertData.push_back(v3);
}
