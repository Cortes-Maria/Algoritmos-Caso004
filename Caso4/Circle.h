//
// Created by ixel on 21/5/20.
//

#ifndef CASO4_CIRCLE_H
#define CASO4_CIRCLE_H
#include "Point.h"
#include <list>
#include <stdio.h>
#include <math.h>
#include <vector>

#define PI 3.14159265

using namespace std;

class Circle{
public:
    vector<Point*> coordinates;
    vector<float> angles;

    Circle(){
        coordinates = vector<Point*>();
        angles = vector<float>();
    }

    void insert(int px, int py){
        Point *newLight = new Point(px,py);
        coordinates.push_back(newLight);
    }

    void generateCircle(int xc, int yc, int radius, int circleSize){
        //circleSize = number of ellipses per circumference; radius = radius of the circumference
        for (int i = 0; i<circleSize; i++){
            float angle = ((2*PI)/circleSize)*i; //angle used to place the ellipse
            coordinates.push_back(new Point(xc+(sin(angle)*radius), yc+(cos(angle))*radius));
            angles.push_back(angle);
        }
    }

    void generateCircles(int numberCircles, int xc, int yc, int radius, int circleSize){
        //numberCircles = k circumferences; circleSize = number of ellipses per circumference
        //xc and yc = coordinates of the center
        int increaseCircles = 1;
        for (int i = 1; i<numberCircles+1; i++){
            generateCircle(xc, yc, radius*i, circleSize*increaseCircles);
            increaseCircles++; //Used to put more ellipses in the bigger circumference
        }
    }

    void generateSet(int numberSets, int numberCircles, int xc, int yc, int radius, int circleSize){
        for (int i=0; i<numberSets; i++){
            float angle = ((2*PI)/numberSets)*i;
            generateCircles(numberCircles, xc + (sin(angle)*circleSize/2), yc + (cos(angle)*circleSize/2), radius, circleSize);
        }

    }

    void printCoordinates(){
        for (int i=0; i<coordinates.size(); i++){
            coordinates[i]->printPoint();
            cout<<" Angle: "<<angles[i]<<endl;
        }
    }
};

#endif //CASO4_CIRCLE_H
