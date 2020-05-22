//
// Created by ixel on 14/5/20.
//

#ifndef CASO4_POINT_H
#define CASO4_POINT_H
#include <iostream>
#include <stdio.h>
#include <stdint.h>

using namespace std;

class Color{
public:
    int red, green, blue;

    Color(int pRed, int pGreen, int pBlue){
        red = pRed;
        green = pGreen;
        blue = pBlue;
    }

    void printColor(){
        cout<<"R: "<<red<<" G: "<<green<<" B: "<<blue;
    }
};

class Point{
public:
    int x, y, xc, yc;
    Color *color;

    Point(){
        x = 0;
        y = 0;
        xc = yc = 0;
        color = new Color(0,0,0);
    }
    Point(int px, int py, Color *pColor){
        x = px;
        y = py;
        color = pColor;
    }

    Point(int px, int py, int pXC, int pYC, Color *pColor){
        x = px;
        y = py;
        xc = pXC;
        yc = pYC;
        color = pColor;
    }

    void printPoint(){
        cout<<"X: "<<x<< " Y: "<<y;
    }
};

#endif //CASO4_POINT_H
