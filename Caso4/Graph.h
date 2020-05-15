//
// Created by María José on 5/12/2020.
//
#ifndef CASO4_GRAPH_H
#define CASO4_GRAPH_H
#include<string>
#include <list>
#include <map>
#include <iostream>
#include "FileReader.h"

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
    void printNode(){
        cout<<word<<endl;
    }
};

class Graph{
public:
    //list<Node*> nodes; //lista con todos los nodos
    map<string,Node*> nodes;//map con todos los nodos, la key es la palabra que guarda
    int totalWords;
    Graph(){
        nodes = map<string,Node*>();
    }
    void AddNode(string pWord){
        Node *newNode = new Node(pWord);
        nodes.insert({pWord,newNode});
    }

    void AddAdjacency(){

    }

    void fillGraphNodes(){
        l
    }
};






#endif //CASO4_GRAPH_H
