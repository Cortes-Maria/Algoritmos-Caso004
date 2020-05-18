//
// Created by María José on 3/30/2020.
//
#ifndef CASO4_FILEREADER_H
#define CASO4_FILEREADER_H
#include <fstream>
#include <iostream>
#include<vector>
#include <map>

using namespace std;

class FileReader {
    vector<string> terminaciones = {"ar","er","ir","ando","endo","iendo", "ado", "ido","so","cho","ió","izó","eron","aban","aba","ó"};
    vector<string> typos = {",",";",":","<<",".",")","(","»","«"};
    //lista de palabras que ignorar {"cuando",
public:
    ifstream texto;
    string palabraActual;
    map<string,int> nouns;
    FileReader(){
        nouns =  map<string,int>();
        texto.open("\\home\\ixel\\Document\\Caso004\\Algoritmos-Caso004\\Caso4\\El libro de Urantia.txt");
        //texto.open("C:\\Users\\gollo\\OneDrive - Estudiantes ITCR\\Universidad\\2020 Semestre I\\Analisis de algoritmos\\Caso 004\\Algoritmos-Caso004\\Caso4\\El libro de Urantia.txt");
        //Probar si el archivo se puede abrir
        if (!texto) {
            cerr << "Unable to open file El libro de Urantia.txt";
            exit(1);   // call system to stop
        }

        getNouns();

        printNouns();



        //cout<<nouns.size()<<endl;
        texto.close();
    }

    void getNouns(){
        map<string,int>::iterator findItr;
        while(texto>>palabraActual){
            eraseTypo(&palabraActual);
            if(palabraActual.size() <= 3 || isVerb(palabraActual)){
                continue;
            }
            else{
                findItr = nouns.find(palabraActual);
                if(findItr == nouns.end()){
                    nouns.insert({palabraActual,1});
                }
                else{
                    nouns.at(palabraActual) += 1;
                }
            }
        }
    }
    void printNouns(){
        map<string,int>::iterator it;
        for(it=nouns.begin(); it!= nouns.end();it++){
            cout<<it->first+" : ";
            cout<<it->second<<endl;
        }
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
