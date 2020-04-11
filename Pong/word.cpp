
#include <string>
#include <iostream>
#include <typeinfo>
#include "word.h"
#include "letters.h"
#include "vertices.h"

Word::Word(std::string wd, float lt, float btm, float ht, Vertices& v)
{
    left = lt;
    bottom = btm;
    height = ht;
    width = ht * 0.6f;
    space = ht * 0.1f;
    
    float leftSpace = 0.0f;
    
    for (char const &c: wd) {
        Letters let1(c, left + leftSpace, bottom, height, width, v);
        leftSpace = leftSpace + width + space;
    }
    
}
