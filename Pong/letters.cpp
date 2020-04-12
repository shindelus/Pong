#include <iostream>
#include "letters.h"

void Letters::CreateA(Vertices& v)
{
    CreateDiagBottomLeftToTopMid(v);
    CreateDiagBottomRightToTopMid(v);
    CreateHorizMiddleMini(v);
}

void Letters::CreateB(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateVertRightTopHalfShort(v);
    CreateVertRightBottomHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizMiddleShort(v);
    CreateHorizBottomShort(v);
}

void Letters::CreateC(Vertices& v)
{
    CreateVertLeftShort(v);
    CreateVertRightTopMini(v);
    CreateVertRightBottomMini(v);
    CreateHorizBottomShort(v);
    CreateHorizTopShort(v);
    
}

void Letters::CreateD(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateVertRightShort(v);
    CreateHorizTopShort(v);
    CreateHorizBottomShort(v);
}

void Letters::CreateE(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateHorizBottomFull(v);
    CreateHorizMiddleShort(v);
    CreateHorizTopFull(v);
}

void Letters::CreateF(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateHorizMiddleShort(v);
    CreateHorizTopFull(v);
}

void Letters::CreateG(Vertices& v)
{
    CreateVertLeftShort(v);
    CreateVertRightTopMini(v);
    CreateVertRightBottomHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizBottomShort(v);
    CreateHorizMiddleMiniRight(v);
}

void Letters::CreateH(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateVertRightFull(v);
    CreateHorizMiddleFull(v);
}

void Letters::CreateI(Vertices& v)
{
    CreateVertMidFull(v);
    CreateHorizTopShort(v);
    CreateHorizBottomShort(v);
}

void Letters::CreateJ(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide + fontWidth, fontWidth, height - fontWidth);
    CreateVertLeftBottomMini(v);
    CreateHorizBottomShort(v);
}

void Letters::CreateK(Vertices& v)
{
    CreateVertLeftFull(v);
    v.AddVertData(leftSide + width - fontWidth, bottomSide + (height/2) + (fontWidth/2), fontWidth, (height/2) - (fontWidth/2));
    v.AddVertData(leftSide + width - fontWidth, bottomSide, fontWidth, (height/2) - (fontWidth/2));
    CreateHorizMiddleShort(v);
}

void Letters::CreateL(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateHorizBottomFull(v);
}

void Letters::CreateM(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateVertRightFull(v);
    CreateDiagMidToTopLeft(v);
    CreateDiagMidToTopRight(v);
}

void Letters::CreateN(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateVertRightFull(v);
    CreateDiagTopLeftToBottomRight(v);
}

void Letters::CreateO(Vertices& v)
{
    CreateVertLeftShort(v);
    CreateVertRightShort(v);
    CreateHorizTopShort(v);
    CreateHorizBottomShort(v);
}

void Letters::CreateP(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateVertRightTopHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizMiddleShort(v);
}

void Letters::CreateQ(Vertices& v)
{
    CreateVertLeftShort(v);
    v.AddVertData(leftSide + width - fontWidth, bottomSide + fontWidth + (fontWidth/2), fontWidth, height - (2 * fontWidth) - (fontWidth/2));
    CreateHorizTopShort(v);
    v.AddVertData(leftSide + fontWidth, bottomSide, width - (2 * fontWidth) - (fontWidth/2), fontWidth);
    float full = width - fontWidth;
    float blockHeight = (height - fontWidth)/10;
    v.AddVertData(leftSide + (full * 0.8), bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.9), bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + full, bottomSide, fontWidth, height/10);
}

void Letters::CreateR(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateVertRightTopHalfShort(v);
    v.AddVertData(leftSide + width - fontWidth, bottomSide, fontWidth, (height - fontWidth)/2);
    CreateHorizTopShort(v);
    CreateHorizMiddleShort(v);
}

void Letters::CreateS(Vertices& v)
{
    CreateVertLeftTopHalfShort(v);
    CreateVertRightBottomHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizMiddleShort(v);
    CreateHorizBottomShort(v);
    CreateVertLeftBottomMini(v);
    CreateVertRightTopMini(v);
}

void Letters::CreateT(Vertices& v)
{
    CreateVertMidFull(v);
    CreateHorizTopFull(v);
}

void Letters::CreateU(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide + fontWidth, fontWidth, height - fontWidth);
    CreateHorizBottomShort(v);
    v.AddVertData(leftSide, bottomSide + fontWidth, fontWidth, height - fontWidth);

}

void Letters::CreateV(Vertices& v)
{
    CreateDiagMidToTopLeft(v);
    CreateDiagMidToTopRight(v);
}

void Letters::CreateW(Vertices& v)
{
    CreateVertLeftFull(v);
    CreateVertRightFull(v);
    CreateDiagBottomLeftToTopMidHalf(v);
    CreateDiagBottomRightToTopMidHalf(v);
}

void Letters::CreateX(Vertices& v)
{
    CreateDiagTopLeftToBottomRight(v);
    CreateDiagTopRightToBottomLeft(v);
}

void Letters::CreateY(Vertices& v)
{
    CreateDiagMidToTopLeftHalf(v);
    CreateDiagMidToTopRightHalf(v);
    v.AddVertData(leftSide + (width/2) - (fontWidth/2), bottomSide, fontWidth, height/2);
}

void Letters::CreateZ(Vertices& v)
{
    CreateHorizTopFull(v);
    CreateHorizBottomFull(v);
    CreateDiagTopRightToBottomLeft(v);
}

void Letters::Create1(Vertices& v)
{
    CreateVertMidFull(v);
    v.AddVertData(leftSide + fontWidth, bottomSide + height - fontWidth, 2 * fontWidth, fontWidth);
    CreateHorizBottomShort(v);
}

void Letters::Create2(Vertices& v)
{
    CreateVertLeftBottomHalfShort(v);
    CreateVertLeftTopMini(v);
    CreateVertRightTopHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizMiddleShort(v);
    CreateHorizBottomFull(v);
}

void Letters::Create3(Vertices& v)
{
    CreateVertLeftTopMini(v);
    CreateVertRightTopHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizMiddleShort(v);
    CreateVertRightBottomHalfShort(v);
    CreateVertLeftBottomMini(v);
    CreateHorizBottomShort(v);
}

void Letters::Create4(Vertices& v)
{
    CreateVertLeftTopHalfFull(v);
    CreateVertRightFull(v);
    CreateHorizMiddleFull(v);
}

void Letters::Create5(Vertices& v)
{
    CreateVertLeftTopHalfShort(v);
    CreateVertRightBottomHalfShort(v);
    CreateHorizTopFull(v);
    CreateHorizMiddleShort(v);
    CreateHorizBottomShort(v);
    CreateVertLeftBottomMini(v);
}

void Letters::Create6(Vertices& v)
{
    CreateVertLeftShort(v);
    CreateVertRightTopMini(v);
    CreateVertRightBottomHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizBottomShort(v);
    CreateHorizMiddleShort(v);
}

void Letters::Create7(Vertices& v)
{
    CreateDiagMidToTopRight(v);
    CreateHorizTopFull(v);
}

void Letters::Create8(Vertices& v)
{
    CreateVertLeftTopHalfShort(v);
    CreateVertRightBottomHalfShort(v);
    CreateVertLeftBottomHalfShort(v);
    CreateVertRightTopHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizMiddleShort(v);
    CreateHorizBottomShort(v);
}

void Letters::Create9(Vertices& v)
{
    CreateVertLeftTopHalfShort(v);
    CreateHorizTopShort(v);
    CreateHorizMiddleShort(v);
    CreateHorizBottomShort(v);
    CreateVertLeftBottomMini(v);
    CreateVertRightShort(v);
}

void Letters::Create0(Vertices& v)
{
    CreateVertLeftShort(v);
    CreateVertRightShort(v);
    CreateHorizTopShort(v);
    CreateHorizBottomShort(v);
}

void Letters::CreateSPC(Vertices& v)
{

}

void Letters::CreateVertMidFull(Vertices& v)
{
    v.AddVertData(leftSide + (width/2) - (fontWidth/2), bottomSide, fontWidth, height);
}

void Letters::CreateVertLeftFull(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide, fontWidth, height);
}

void Letters::CreateVertLeftTopHalfShort(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide + (height/2) + (fontWidth/2), fontWidth, (height/2) - fontWidth - (fontWidth/2));
}

void Letters::CreateVertLeftTopHalfFull(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide + (height/2), fontWidth, height/2);
}

void Letters::CreateVertLeftBottomHalfShort(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide + fontWidth, fontWidth, (height/2) - fontWidth - (fontWidth/2));
}

void Letters::CreateVertLeftBottomHalfFull(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide, fontWidth, height/2);
}

void Letters::CreateVertLeftShort(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide + fontWidth, fontWidth, height - (2 * fontWidth));
}

void Letters::CreateVertLeftBottomMini(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide + fontWidth, fontWidth, height/6);
}

void Letters::CreateVertLeftTopMini(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide + (height * 0.75f), fontWidth, height/6);
}




void Letters::CreateVertRightFull(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide, fontWidth, height);
}

void Letters::CreateVertRightTopHalfShort(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide + (height/2) + (fontWidth/2), fontWidth, (height/2) - fontWidth - (fontWidth/2));
}

void Letters::CreateVertRightTopHalfFull(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide + (height/2), fontWidth, height/2);
}

void Letters::CreateVertRightBottomHalfShort(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide + fontWidth, fontWidth, (height/2) - fontWidth - (fontWidth/2));
}

void Letters::CreateVertRightBottomHalfFull(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide, fontWidth, height/2);
}

void Letters::CreateVertRightShort(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide + fontWidth, fontWidth, height - (2 * fontWidth));
}

void Letters::CreateVertRightBottomMini(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide + fontWidth, fontWidth, height/6);
}

void Letters::CreateVertRightTopMini(Vertices& v)
{
    v.AddVertData(leftSide + width - fontWidth, bottomSide + (height * 0.75f), fontWidth, height/6);
}





void Letters::CreateHorizBottomFull(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide, width, fontWidth);
}

void Letters::CreateHorizBottomShort(Vertices& v)
{
    v.AddVertData(leftSide + fontWidth, bottomSide, width - (2 * fontWidth), fontWidth);
}

void Letters::CreateHorizMiddleFull(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide + (height/2) - (fontWidth/2), width, fontWidth);
}

void Letters::CreateHorizMiddleShort(Vertices& v)
{
    v.AddVertData(leftSide + fontWidth, bottomSide + (height/2) - (fontWidth/2), width - (2 * fontWidth), fontWidth);
}

void Letters::CreateHorizMiddleMini(Vertices& v)
{
    v.AddVertData(leftSide + (width/3), bottomSide + (height/2) - fontWidth, width/3, fontWidth);
}

void Letters::CreateHorizMiddleMiniRight(Vertices& v)
{
    v.AddVertData(leftSide + (width/2), bottomSide + (height/2) - fontWidth, width/2, fontWidth);
}

void Letters::CreateHorizTopFull(Vertices& v)
{
    v.AddVertData(leftSide, bottomSide + height - fontWidth, width, fontWidth);
}

void Letters::CreateHorizTopShort(Vertices& v)
{
    v.AddVertData(leftSide + fontWidth, bottomSide + height - fontWidth, width - (2 * fontWidth), fontWidth);
}



void Letters::CreateDiagBottomLeftToTopMid(Vertices& v)
{
    float mid = (width/2) - (fontWidth/2);
    float blockHeight = (height - fontWidth)/10;
    v.AddVertData(leftSide, bottomSide, fontWidth, height/10);
    v.AddVertData(leftSide + (mid * 0.1), bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.2), bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.3), bottomSide + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.4), bottomSide + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.5), bottomSide + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.6), bottomSide + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.7), bottomSide + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.8), bottomSide + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.9), bottomSide + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + mid, bottomSide + height - fontWidth, fontWidth, height/10);
}

void Letters::CreateDiagBottomRightToTopMid(Vertices& v)
{
    float mid = (width/2) - (fontWidth/2);
    float blockHeight = (height - fontWidth)/10;
    v.AddVertData(leftSide + width - fontWidth, bottomSide, fontWidth, height/10);
    v.AddVertData(leftSide + width - (mid * 0.1) - fontWidth, bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.2) - fontWidth, bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.3) - fontWidth, bottomSide + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.4) - fontWidth, bottomSide + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.5) - fontWidth, bottomSide + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.6) - fontWidth, bottomSide + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.7) - fontWidth, bottomSide + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.8) - fontWidth, bottomSide + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.9) - fontWidth, bottomSide + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - mid - fontWidth, bottomSide + height - fontWidth, fontWidth, height/10);
}

void Letters::CreateDiagBottomLeftToTopMidHalf(Vertices& v)
{
    float mid = (width/2) - (fontWidth/2);
    float blockHeight = (height - fontWidth)/20;
    v.AddVertData(leftSide, bottomSide, fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.1), bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.2), bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.3), bottomSide + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.4), bottomSide + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.5), bottomSide + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.6), bottomSide + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.7), bottomSide + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.8), bottomSide + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.9), bottomSide + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + mid, bottomSide + ((height - fontWidth)/2), fontWidth, blockHeight);
}

void Letters::CreateDiagBottomRightToTopMidHalf(Vertices& v)
{
    float mid = (width/2) - (fontWidth/2);
    float blockHeight = (height - fontWidth)/20;
    v.AddVertData(leftSide + width - fontWidth, bottomSide, fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.1) - fontWidth, bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.2) - fontWidth, bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.3) - fontWidth, bottomSide + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.4) - fontWidth, bottomSide + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.5) - fontWidth, bottomSide + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.6) - fontWidth, bottomSide + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.7) - fontWidth, bottomSide + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.8) - fontWidth, bottomSide + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - (mid * 0.9) - fontWidth, bottomSide + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + width - mid - fontWidth, bottomSide + ((height - fontWidth)/2), fontWidth, blockHeight);
}

void Letters::CreateDiagMidToTopRight(Vertices& v)
{
    float mid = (width/2) - (fontWidth/2);
    float blockHeight = (height - fontWidth)/10;
    v.AddVertData(leftSide + mid, bottomSide, fontWidth, height/10);
    v.AddVertData(leftSide + (mid * 1.1), bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.2), bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.3), bottomSide + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.4), bottomSide + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.5), bottomSide + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.6), bottomSide + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.7), bottomSide + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.8), bottomSide + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.9), bottomSide + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 2), bottomSide + height - fontWidth, fontWidth, height/10);
}

void Letters::CreateDiagMidToTopLeft(Vertices& v)
{
    float mid = (width/2) - (fontWidth/2);
    float blockHeight = (height - fontWidth)/10;
    v.AddVertData(leftSide, bottomSide + height - fontWidth, fontWidth, height/10);
    v.AddVertData(leftSide + (mid * 0.1), bottomSide + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.2), bottomSide + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.3), bottomSide + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.4), bottomSide + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.5), bottomSide + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.6), bottomSide + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.7), bottomSide + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.8), bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.9), bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + mid, bottomSide, fontWidth, height/10);
}

void Letters::CreateDiagMidToTopRightHalf(Vertices& v)
{
    float mid = (width/2) - (fontWidth/2);
    float blockHeight = (height - fontWidth)/20;
    v.AddVertData(leftSide + mid, bottomSide + (height/2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.1), bottomSide + ((height - fontWidth)/2) + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.2), bottomSide + ((height - fontWidth)/2) + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.3), bottomSide + ((height - fontWidth)/2) + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.4), bottomSide + ((height - fontWidth)/2) + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.5), bottomSide + ((height - fontWidth)/2) + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.6), bottomSide + ((height - fontWidth)/2) + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.7), bottomSide + ((height - fontWidth)/2) + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.8), bottomSide + ((height - fontWidth)/2) + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 1.9), bottomSide + ((height - fontWidth)/2) + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 2), bottomSide + height - fontWidth, fontWidth, blockHeight);
}

void Letters::CreateDiagMidToTopLeftHalf(Vertices& v)
{
    float mid = (width/2) - (fontWidth/2);
    float blockHeight = (height - fontWidth)/20;
    v.AddVertData(leftSide, bottomSide + height - fontWidth, fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.1), bottomSide + ((height - fontWidth)/2) + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.2), bottomSide + ((height - fontWidth)/2) + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.3), bottomSide + ((height - fontWidth)/2) + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.4), bottomSide + ((height - fontWidth)/2) + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.5), bottomSide + ((height - fontWidth)/2) + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.6), bottomSide + ((height - fontWidth)/2) + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.7), bottomSide + ((height - fontWidth)/2) + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.8), bottomSide + ((height - fontWidth)/2) + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (mid * 0.9), bottomSide + ((height - fontWidth)/2) + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + mid, bottomSide + (height/2), fontWidth, blockHeight);
}

void Letters::CreateDiagTopLeftToBottomRight(Vertices& v)
{
    float full = width - fontWidth;
    float blockHeight = (height - fontWidth)/10;
    v.AddVertData(leftSide, bottomSide + height - fontWidth, fontWidth, height/10);
    v.AddVertData(leftSide + (full * 0.1), bottomSide + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.2), bottomSide + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.3), bottomSide + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.4), bottomSide + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.5), bottomSide + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.6), bottomSide + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.7), bottomSide + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.8), bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.9), bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + full, bottomSide, fontWidth, height/10);
}

void Letters::CreateDiagTopRightToBottomLeft(Vertices& v)
{
    float full = width - fontWidth;
    float blockHeight = (height - fontWidth)/10;
    v.AddVertData(leftSide, bottomSide, fontWidth, height/10);
    v.AddVertData(leftSide + (full * 0.1), bottomSide + (blockHeight * 1), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.2), bottomSide + (blockHeight * 2), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.3), bottomSide + (blockHeight * 3), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.4), bottomSide + (blockHeight * 4), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.5), bottomSide + (blockHeight * 5), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.6), bottomSide + (blockHeight * 6), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.7), bottomSide + (blockHeight * 7), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.8), bottomSide + (blockHeight * 8), fontWidth, blockHeight);
    v.AddVertData(leftSide + (full * 0.9), bottomSide + (blockHeight * 9), fontWidth, blockHeight);
    v.AddVertData(leftSide + full, bottomSide + height - fontWidth, fontWidth, height/10);
}


Letters::Letters(const char lt, float left, float bottom, float ht, float wd, Vertices& vt)
{
    letter = lt;
    height = ht;
    width = wd;
    leftSide = left;
    bottomSide = bottom;
    fontWidth = ht / 10.0f;
    switch (letter)
    {
        case 'a' : CreateA(vt);
            break;
        case 'b' : CreateB(vt);
            break;
        case 'c' : CreateC(vt);
            break;
        case 'd' : CreateD(vt);
            break;
        case 'e' : CreateE(vt);
            break;
        case 'f' : CreateF(vt);
            break;
        case 'g' : CreateG(vt);
            break;
        case 'h' : CreateH(vt);
            break;
        case 'i' : CreateI(vt);
            break;
        case 'j' : CreateJ(vt);
            break;
        case 'k' : CreateK(vt);
            break;
        case 'l' : CreateL(vt);
            break;
        case 'm': CreateM(vt);
            break;
        case 'n' : CreateN(vt);
            break;
        case 'o' : CreateO(vt);
            break;
        case 'p' : CreateP(vt);
            break;
        case 'q' : CreateQ(vt);
            break;
        case 'r' : CreateR(vt);
            break;
        case 's' : CreateS(vt);
            break;
        case 't' : CreateT(vt);
            break;
        case 'u' : CreateU(vt);
            break;
        case 'v' : CreateV(vt);
            break;
        case 'w' : CreateW(vt);
            break;
        case 'x' : CreateX(vt);
            break;
        case 'y' : CreateY(vt);
            break;
        case 'z' : CreateZ(vt);
            break;
        case '1' : Create1(vt);
            break;
        case '2' : Create2(vt);
            break;
        case '3' : Create3(vt);
            break;
        case '4' : Create4(vt);
            break;
        case '5' : Create5(vt);
            break;
        case '6' : Create6(vt);
            break;
        case '7' : Create7(vt);
            break;
        case '8' : Create8(vt);
            break;
        case '9' : Create9(vt);
            break;
        case '0' : Create0(vt);
            break;
        case ' ' : CreateSPC(vt);
            break;
    };
}

