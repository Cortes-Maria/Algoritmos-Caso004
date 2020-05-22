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
#include <random>

using namespace std;
struct Node{
public:
    string word;
    bool visited;
    vector<pair<Node*,int>> adjList;//sort value
    map<string,int> adjMap;
    map<string,int> underPowerWords;
    int weightSum; // suma de los pesos de las palabras que soy más poderoso

    Node(){
        word = "";
        visited = false;
        adjList = vector<pair<Node*,int>>();
        adjMap = map<string,int>();
        underPowerWords = map<string,int>();
        weightSum =0;

    }
    Node(string pWord){
        word = pWord;
        visited = false;
        adjList =  vector<pair<Node*,int>>();
        adjMap = map<string,int>();
        underPowerWords = map<string,int>();
        weightSum =0;
    }


    void updateAdjacencyWeight(Node* destinyNode, int pWeightToAdd ){
        for(int i=0; i<adjList.size();i++){
            if(destinyNode == adjList[i].first){
                adjList[i].second += pWeightToAdd;
            }
        }
        string word = destinyNode->word;
        adjMap.find(word)->second += pWeightToAdd;
    }
    bool hasAdjacency(Node* pDestinyNode){
        for(auto it=adjList.begin();it!=adjList.end();++it){
            if(it->first == pDestinyNode){
                return true;
            }
        }
        return false;
    }

    // utility comparator function to pass to the sort() module
    static bool sortByVal(const pair<Node*, int> &a,
                   const pair<Node*, int> &b)
    {
        return (a.second > b.second);
    }
    void sortAdjList(){
        // sort the vector by increasing order of its pair's second value
        sort(adjList.begin(), adjList.end(),sortByVal);
    }
    int getWeight(string pWord){
        if(adjMap.find(pWord) != adjMap.end()){
            return adjMap.find(pWord)->second;
        }
        else return 0;
    }
    void printUnderPowerWords(){
        for(auto it=underPowerWords.begin();it!=underPowerWords.end();++it){
            cout<<it->first + " : ";
            cout<<it->second<<endl;
        }
    }
};

class Graph{
public:
    map<string,Node*> nodes;//map con todos los nodos, la key es la palabra que guarda
    int totalWords;
    map<int,string> wordsPower;

    Graph(){
        nodes = map<string,Node*>();
        wordsPower = map<int,string>();
    }
public:
    void AddNode(string pWord){
        Node *newNode = new Node(pWord);
        nodes.insert({pWord,newNode});
        totalWords +=1;
    }

    void AddAdjacency(Node* pOriginNode, Node* pDestinyNode, int pWeight){
        pair<Node*,int> pairToInsert = pair<Node*,int>(pDestinyNode,pWeight);
        pOriginNode->adjList.push_back(pairToInsert);
        pOriginNode->adjMap.insert({pDestinyNode->word,pWeight});

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
    void puntoA(int C){ // O(c)
        for(auto rit=wordsPower.rbegin();rit!=wordsPower.rend();++rit){
            if(C != 0){
                cout<<rit->second+" : ";
                cout<<rit->first<<endl;
                C--;
            }
            else{
                return;
            }
        }
    }
    void printWordsPower(){
        for(auto it=wordsPower.begin();it!=wordsPower.end();++it){
            cout<<it->second+" : ";
            cout<<it->first<<endl;
        }
    }
    void puntoB(string pWord){
        Node* currentNode = getNode(pWord);//lo busca en el hash segun el string de la palabra = O(1)
        currentNode->printUnderPowerWords();
    }
    void puntoC(int Kgrupos,string pPalabra){
        Node* currentNode = getNode(pPalabra);
        int wordsPerGroup = totalWords/Kgrupos;
        int groupNumber =1;
        cout<<"Grupo: ";
        cout<<groupNumber<<endl;
        for(auto it =currentNode->adjList.begin() ; it!=currentNode->adjList.end();++it){
            Node *adjNode = it->first;
                MakeGroup(adjNode,wordsPerGroup,wordsPerGroup);
                groupNumber++;
                if(groupNumber<=Kgrupos){
                    cout<<"Grupo: ";
                    cout<<groupNumber<<endl;
                }
                else{
                    break;
                }
        }
    }

    void MakeGroup(Node* currentNode, int WordsPerGroup, int wordCount){
        Node *temporal = currentNode;
      while(wordCount!=0){
          if(/*!temporal->visited &&*/ !temporal->adjList.empty()){
              cout<<temporal->word<<endl;
              temporal->visited = true;
              wordCount--;
              if(temporal->adjList.begin()->first->visited){
                 return;
              }
                  temporal = temporal->adjList.begin()->first;

          }
          else{
              return;
          }
      }
    }


    void setUnderPowerWords(){//O(n**2)
        for(auto it=nodes.begin();it!=nodes.end();++it){
            Node* currentNode = it->second;
            string currentWord = currentNode->word;
            for(auto adj=currentNode->adjList.begin();adj!=currentNode->adjList.end() ;++adj){
                string adjWord=adj->first->word;
                int forwardWeight = adj->second;
                int backwardWeight = adj->first->getWeight(currentWord);
                if(forwardWeight > backwardWeight){
                    currentNode->underPowerWords.insert({adjWord,forwardWeight});
                    currentNode->weightSum += forwardWeight;
                }
            }
            wordsPower.insert({currentNode->weightSum,currentWord});
        }
    }

};






#endif //CASO4_GRAPH_H
