
#include <iostream>
#include <string>
#include "vertices.h"

class Letters
{
public:
    float leftSide;
    float bottomSide;
    float fontWidth;
    float width;
    float height;
    char letter;
//    enum letter {
//        a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, one, two, three, four, five, six, seven, eight, nine, zero
//    };
    
    void CreateA(Vertices& v);
    void CreateB(Vertices& v);
    void CreateC(Vertices& v);
    void CreateD(Vertices& v);
    void CreateE(Vertices& v);
    void CreateF(Vertices& v);
    void CreateG(Vertices& v);
    void CreateH(Vertices& v);
    void CreateI(Vertices& v);
    void CreateJ(Vertices& v);
    void CreateK(Vertices& v);
    void CreateL(Vertices& v);
    void CreateM(Vertices& v);
    void CreateN(Vertices& v);
    void CreateO(Vertices& v);
    void CreateP(Vertices& v);
    void CreateQ(Vertices& v);
    void CreateR(Vertices& v);
    void CreateS(Vertices& v);
    void CreateT(Vertices& v);
    void CreateU(Vertices& v);
    void CreateV(Vertices& v);
    void CreateW(Vertices& v);
    void CreateX(Vertices& v);
    void CreateY(Vertices& v);
    void CreateZ(Vertices& v);
    void Create1(Vertices& v);
    void Create2(Vertices& v);
    void Create3(Vertices& v);
    void Create4(Vertices& v);
    void Create5(Vertices& v);
    void Create6(Vertices& v);
    void Create7(Vertices& v);
    void Create8(Vertices& v);
    void Create9(Vertices& v);
    void Create0(Vertices& v);
    void CreateSPC(Vertices& v);
    void CreateVertLeftFull(Vertices& v);
    void CreateVertMidFull(Vertices& v);
    void CreateVertLeftTopHalfShort(Vertices& v);
    void CreateVertLeftTopHalfFull(Vertices& v);
    void CreateVertLeftBottomHalfShort(Vertices& v);
    void CreateVertLeftBottomHalfFull(Vertices& v);
    void CreateVertLeftShort(Vertices& v);
    void CreateVertLeftBottomMini(Vertices& v);
    void CreateVertLeftTopMini(Vertices& v);
    void CreateVertRightFull(Vertices& v);
    void CreateVertRightTopHalfShort(Vertices& v);
    void CreateVertRightTopHalfFull(Vertices& v);
    void CreateVertRightBottomHalfShort(Vertices& v);
    void CreateVertRightBottomHalfFull(Vertices& v);
    void CreateVertRightShort(Vertices& v);
    void CreateVertRightBottomMini(Vertices& v);
    void CreateVertRightTopMini(Vertices& v);
    void CreateHorizBottomFull(Vertices& v);
    void CreateHorizBottomShort(Vertices& v);
    void CreateHorizMiddleFull(Vertices& v);
    void CreateHorizMiddleShort(Vertices& v);
    void CreateHorizMiddleMini(Vertices& v);
    void CreateHorizMiddleMiniRight(Vertices& v);
    void CreateHorizTopFull(Vertices& v);
    void CreateHorizTopShort(Vertices& v);
    void CreateDiagBottomLeftToTopMid(Vertices& v);
    void CreateDiagBottomRightToTopMid(Vertices& v);
    void CreateDiagBottomLeftToTopMidHalf(Vertices& v);
    void CreateDiagBottomRightToTopMidHalf(Vertices& v);
    void CreateDiagMidToTopRight(Vertices& v);
    void CreateDiagMidToTopLeft(Vertices& v);
    void CreateDiagMidToTopRightHalf(Vertices& v);
    void CreateDiagMidToTopLeftHalf(Vertices& v);
    void CreateDiagTopLeftToBottomRight(Vertices& v);
    void CreateDiagTopRightToBottomLeft(Vertices& v);

    Letters(const char lt, float left, float bottom, float h, float w, Vertices& v);
    ~Letters(){};
private:
    
};
