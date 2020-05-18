#include <iostream>
#include "FileReader.h"
using  namespace std;
int main() {
    FileReader prueba1 = FileReader();
    //prueba1.graph->printAdjacency("sobre");
    //cout<<prueba1.graph->nodes.size();
    prueba1.graph->printAdjacency("curanderos");
    /*
    Graph* graph = new Graph();
    graph->AddNode("Hola");
    graph->AddNode("Como");
    Node* node1 = graph->nodes.find("Hola")->second;
    Node* node2 = graph->nodes.find("Como")->second;
    graph->AddAdjacency(node1,node2,12);
    cout<<node1->adjList.front().second<<endl;
    node1->updateAdjacencyWeight(node2,8);
    cout<<node1->adjList.front().second<<endl;*/

    return 0;
}
