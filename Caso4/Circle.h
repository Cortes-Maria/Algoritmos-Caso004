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
    float increment;
    float incrementAngle;
    //int xc, yc;

    Circle(){
        coordinates = vector<Point*>();
        angles = vector<float>();
        increment = 0.3;
        incrementAngle = 0;
        //xc = yc = 0;
    }

    Circle (int pX, int pY){
        coordinates = vector<Point*>();
        angles = vector<float>();
        increment = 0.3;
        incrementAngle = 0;
//        xc = pX;
//        yc = pY;
    }

    Circle(float pIncrement, float pIncrementAngle, int pX, int pY){
        coordinates = vector<Point*>();
        angles = vector<float>();
        increment = pIncrement;
        incrementAngle = pIncrementAngle;
//        xc = pX;
//        yc = pY;
    }


    void generateCircle(int xc, int yc, int radius, int circleSize){
        //circleSize = number of ellipses per circumference; radius = radius of the circumference
        for (int i = 0; i<circleSize; i++){
            float angle = ((2*PI)/circleSize)*i; //angle used to place the ellipse
            coordinates.push_back(new Point(xc+(sin(angle)*radius), yc+(cos(angle))*radius, xc, yc));
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

    void generateSet(int numberSets, int xc, int yc, int numberCircles, int radius, int circleSize){
        for (int i=0; i<numberSets; i++){
            float angle = ((2*PI)/numberSets)*i;
            generateCircles(numberCircles, xc + (sin(angle)*circleSize), yc + (cos(angle)*circleSize), radius, circleSize);
        }

    }

    void moveCircle(int radius){

        if(incrementAngle>2*PI || incrementAngle<0){
            increment = -increment;
        }

        incrementAngle += increment;

        for(int i=0; i<this->coordinates.size(); i++){
            angles[i] = angles[i] + incrementAngle;
            coordinates[i]->x = coordinates[i]->xc + (sin(angles[i])*radius);
            coordinates[i]->y = coordinates[i]->yc + (cos(angles[i])*radius);
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