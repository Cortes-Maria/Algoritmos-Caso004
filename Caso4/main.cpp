#include <iostream>
#include "FileReader.h"
#include "Circle.h"
using  namespace std;
int main() {

    FileReader prueba1 = FileReader();
 // prueba1.graph->puntoA(5);
 // prueba1.graph->puntoB("chamanes");
 // prueba1.graph->puntoC(20,"espíritus");
 //cout<<prueba1.graph->totalWords;
 //prueba1.graph->printAdjacency("colocarse");
  
    Circle circle = Circle();
    circle.generateSet(2,2,0,0,10,2);
    circle.printCoordinates();

    return 0;
}
