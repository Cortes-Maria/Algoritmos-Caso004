//
// Created by María José on 5/12/2020.
//
#ifndef CASO4_GRAPH_H
#define CASO4_GRAPH_H
#include<string>
#include <list>
#include <map>
using namespace std;
struct Node{
    string word;
    bool visited;
    //  nodo   peso
    map<Node*,float> adjList;
    Node(){
        word = "";
        visited = false;
        adjList = map<Node*,float>();
    }
    Node(string pWord){
        word = pWord;
        visited = false;
        adjList =  map<Node*,float>();
    }
};
class Graph{
public:
    list<Node*> nodes; //lista con todos los nodos
    int totalWords;

    void addAdjacency(){

    }


};






#endif //CASO4_GRAPH_H
