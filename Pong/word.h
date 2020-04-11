#include <iostream>
#include "vertices.h"

class Word

{
public:
    float height;
    float width;
    float left;
    float bottom;
    float space;
    Word(std::string wd, float lt, float btm, float ht, Vertices& v);
    ~Word(){};
private:

};
