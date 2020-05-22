#include <iostream>
#include "FileReader.h"
#include "Circle.h"
using  namespace std;
int main() {
    //FileReader prueba1 = FileReader();
    Circle circle = Circle();
    circle.generateSet(2,2,0,0,10,2);
    circle.printCoordinates();
    return 0;
}
