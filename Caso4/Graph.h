//
// Created by María José on 5/12/2020.
//
#ifndef CASO4_GRAPH_H
#define CASO4_GRAPH_H
#include<string>
#include <list>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include "FileReader.h"

using namespace std;
struct Node{

    string word;
    bool visited;
    //map<int,Node*> adjList;
    vector<pair<Node*,int>> adjList;

    Node(){
        word = "";
        visited = false;
        adjList = vector<pair<Node*,int>>();
    }
    Node(string pWord){
        word = pWord;
        visited = false;
        adjList =  vector<pair<Node*,int>>();
    }


    void updateAdjacencyWeight(Node* destinyNode, int pWeightToAdd ){
        auto result = find_if(
                adjList.begin(),
                adjList.end(),
                [destinyNode](const auto& mo) {return mo.first == destinyNode; });

        //CHANGE VARIABLE IF FOUND
        if(result != adjList.end())
            result->second += pWeightToAdd;
    }
    bool hasAdjacency(Node* pDestinyNode){
        for(auto it=adjList.begin();it!=adjList.end();++it){
            if(it->first == pDestinyNode){
                return true;
            }
        }
        return false;
    }
};

class Graph{
public:
    map<string,Node*> nodes;//map con todos los nodos, la key es la palabra que guarda
    int totalWords;
    Graph(){
        nodes = map<string,Node*>();
    }
public:
    void AddNode(string pWord){
        Node *newNode = new Node(pWord);
        nodes.insert({pWord,newNode});
    }

    void AddAdjacency(Node* pOriginNode, Node* pDestinyNode, int pWeight){
        pOriginNode->adjList.push_back(make_pair(pDestinyNode,pWeight));

    }
    void updateAdjacencyWeight(string pWord, Node* pDestinyNode, int pWeightToAdd){
        Node* originNode = nodes.find(pWord)->second;
        originNode->updateAdjacencyWeight(pDestinyNode,pWeightToAdd);

    }
    Node *getNode(string pWord){
        return nodes.find(pWord)->second;
    }
    bool existNode(string pWord){
        return nodes.find(pWord) != nodes.end();
    }

    void printAdjacency(string pWord){
        if(existNode(pWord)){
            Node* node = getNode(pWord);
            if(node->adjList.empty()){
                cout<<"no hay relaciones"<<endl;
            }
            else{
                for(int i=0; i<node->adjList.size(); i++){
                    cout<<node->adjList[i].first->word + " : ";
                    cout<<node->adjList[i].second << endl;
                }
            }
        }
    }
};






#endif //CASO4_GRAPH_H
