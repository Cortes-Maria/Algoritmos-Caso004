//
// Created by ixel on 14/5/20.
//

#ifndef CASO4_POINT_H
#define CASO4_POINT_H
#include <iostream>
using namespace std;

class Point{
public:
    int x, y, xc, yc;
    //Color

    Point(){
        x = 0;
        y = 0;
        xc = yc = 0;
        //Color ?
    }
    Point(int px, int py){
        x = px;
        y = py;
    }

    Point(int px, int py, int pXC, int pYC){
        x = px;
        y = py;
        xc = pXC;
        yc = pYC;
    }

    void printPoint(){
        cout<<"X: "<<x<< " Y: "<<y;
    }
};

#endif //CASO4_POINT_H
