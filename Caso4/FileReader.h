//
// Created by María José on 3/30/2020.
//
#ifndef CASO4_FILEREADER_H
#define CASO4_FILEREADER_H
#include <fstream>
#include <iostream>
#include<vector>
#include <map>
#include <cstring>
#include <sstream>
#include "Graph.h"

using namespace std;

class FileReader {
    vector<string> terminaciones = {"ar","er","ir","ando","endo","iendo", "ado", "ido","so","cho","ió","izó","eron","aban","aba","ó"};
    vector<string> typos = {",",";",":","<<",".",")","(","»","«"};
    vector<string> ignorar = {"como","para","eran","1806"};
public: Graph *graph;
public:
    ifstream texto;
    map<string,int> nouns;
    FileReader(){

        graph = new Graph();
       nouns =  map<string,int>();

        openFile();
        processText();
        graph->setUnderPowerWords();
        //llenar mi hash con la suma de pesos de cada nodo

        texto.close();
    }
    void openFile(){
        texto.open(R"(C:\Users\gollo\OneDrive - Estudiantes ITCR\Universidad\2020 Semestre I\Analisis de algoritmos\Caso 004\Algoritmos-Caso004\Caso4\El libro de Urantia.txt)");

        //Probar si el archivo se puede abrir
        if (!texto) {
            cerr << "Unable to open file El libro de Urantia.txt";
            exit(1);   // call system to stop
        }

    }
    void processText(){
        std::string currentParagraph;
        while (std::getline(texto, currentParagraph))
        {
            if(currentParagraph.compare("\r") == 0){
                continue;
            }
            processParagraph(currentParagraph);

        }
    }
    void processParagraph(string pParagraph){
        vector<Node*> currentNouns = vector<Node*>();
        string palabraActual;
        map<string,int>::iterator findItr;
        istringstream ss(pParagraph);
        while(ss >> palabraActual){
            eraseTypo(&palabraActual);
            if(palabraActual.size() <= 3 || isVerb(palabraActual) || mustIgnored(palabraActual)){
                continue;//descarta lo que no sea sustantivo
            }
            else{
                if(!graph->existNode(palabraActual)){
                    graph->AddNode(palabraActual);
                }
                currentNouns.push_back(graph->getNode(palabraActual));
            }
        }
        getRelatedWords(currentNouns);
    }

    void getRelatedWords(vector<Node*> pCurrentNouns){
        for(int i=0; i<pCurrentNouns.size(); i++){
            //Node *currentNode = graph->getNode(pCurrentNouns[i]->word);
            Node *currentNode = pCurrentNouns[i];
            if(currentNode == pCurrentNouns.back()){
                return;
            }
            for(int destiny=i+1;destiny<(i+4);destiny++){

                if(currentNode->hasAdjacency(pCurrentNouns[destiny])){
                    currentNode->updateAdjacencyWeight(pCurrentNouns[destiny],2);
                }
                else{
                    graph->AddAdjacency(currentNode, pCurrentNouns[destiny], 1);
                }
                if(pCurrentNouns[destiny]==pCurrentNouns.back()){
                    break;
                }
            }
        }
    }
    bool mustIgnored(string pPalabra){
        for(auto it=ignorar.begin();it!=ignorar.end();++it){
            if(pPalabra.compare(*it) == 0){
                return true;
            }
        }
        return false;
    }


    bool isVerb(string pPalabra){
        for(auto it = terminaciones.begin(); it != terminaciones.end(); it++){
            int refpos = (pPalabra.size()) - it->size();
            size_t found = pPalabra.find(*it, refpos);
            if (found!=string::npos){
                return true;
            }
        }
        return false;
    }

    void eraseTypo(string *pPalabra){
        for(auto it = typos.begin(); it != typos.end(); it++){
            size_t foundtypo = pPalabra->find(*it);
            if(foundtypo != string::npos){
                pPalabra->erase(foundtypo);
            }
        }
    }

};


#endif //CASO4_FILEREADER_H
