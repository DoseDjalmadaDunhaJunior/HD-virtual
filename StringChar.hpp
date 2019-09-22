//
// Created by djalma cunha on 2018-12-31.
//

#ifndef CONVERTE_STRING_CHAR_STRINGCHAR_HPP
#define CONVERTE_STRING_CHAR_STRINGCHAR_HPP
#include <iostream>
#include <string>
using namespace std;
///tanto char para string quanto o oposto basta chamar cenverte
class StringChar {
public:
    char* converte(const string &txt){
        vet = (char*) malloc((sizeof(char))*txt.size());
        strcpy(vet,txt.c_str());
        vet[txt.size()] = '\n';
        return vet;
    }

    string converte(char* txt){
        return txt;
    }

    string converte(int n){
        return to_string(n);
    }


    int tamanho(char* txt){
        int i = 0;
        for (i = 0; txt[i] != '\0' ; i++) {

        }
        return i;
    }

    int tamanho(const string &txt){
        return txt.size();
    }

    int converte(char n){
        return n-48;
    }


/*
~StringChar(){
        free(vet);
    }
    */
private:
    char *vet;
};


#endif //CONVERTE_STRING_CHAR_STRINGCHAR_HPP
