#include <iostream>
#include <string>
#include "StringChar.hpp"
#include <stdio.h>
#include <stdlib.h>

//int p = atoi(h);
using namespace std;
using namespace std;
char txt[1025][34];

struct generico{
    string cont = " ";
    string arquivo = " ";
};

typedef struct generico generico;

void zera(){
    for (int i = 0; i < 1025; i++) {
        for (int j = 0; j < 34; j++) {
            txt[i][j] = 32;
        }
    }
}

void salva(){
    FILE* arq;
    arq = fopen("HD1.txt", "w");
    for (int i = 0; i <= 1025 ; i++) {
        for (int j = 0; j <= 33; j++) {
            if(i == 0 && j != 0){
                fprintf(arq,"%i ", j);
                if(j == 33){
                    fprintf(arq,"\n");
                }
            }
            else if(j == 0 && i != 0){
                fprintf(arq,"%i", i);
            }
            else if(j == 0 && i == 0){
                fprintf(arq, "%c ", 32);
            }
            else{
                char ver = txt[i][j];
                if(j == 17){

                }
                fprintf(arq,"%c", txt[i][j]);
            }
        }
        //fprintf(arq,"\n");
    }
    fclose(arq);

}
/*
void estrutura(int op,generico rts) {
    if (op == 1) {
        for (int i = 0; i <= 1024; i++) {
            for (int j = 0; j <= 2; j++) {
                if (i >= 21 && j == 2) {
                    txt[i][j] = '1';
                } else {
                    txt[i][j] = '0';
                }

            }
        }
    } else if (op == 2) {
        StringChar bola;
        int i = 0;
        for (i = 1; (i <= 20) || (txt[i][1]) == 0; i++) {

        }
        if (txt[i][1] == 0) {
            txt[i][1] = 1;
            /*
            for (int k = 1; k < 20; k++) {
                for (int i = 5; i <= 8; i++) {

                }
            }
            for (int k = 1; k < 20; k++) {
                for (int i = 9; i <= 12; i++) {

                }
            }

            for (int k = 1; k < 20; k++) {
                for (int i = 13; i <= 16; i++) {

                }
            }

            for (int k = 1; k < 20; k++) {
                for (int i = 17; i <= 32; i++) {
                    txt[k][i] = bola.converte(rts.arquivo)[i];
                }
            }

        }
        *txt[33] = '\n';
    }
}
*/
void createhd(string str){
    FILE* arq;
    str = str + ".txt";
    StringChar go;
    cout<<go.converte(str);
    generico x;
    arq = fopen(go.converte(str), "w");
    //estrutura(1,x);
    for (int i = 0; i <= 1024 ; i++) {
        for (int j = 0; j <= 33; j++) {
            if(i == 0 && j < 33){
                fprintf(arq,"%i ", j);
            }
            else if(j == 0 ){
                fprintf(arq,"%i ", i);
            }
            if(i > 0 && j > 0) {
                fprintf(arq, "%c ", txt[i][j]);
            }
        }
        fprintf(arq,"\n");
    }
    puts("ok");
    fclose(arq);
}

void create(string str,generico gen) {
    int cCont = 0, cNome = 0;
    StringChar go, cont;
    //cin>>gen.cont;
    gen.cont = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";
    int tam = go.tamanho(gen.cont);
    //estrutura(2, gen);
    for (int i = 1; i <= 1024; i++) {
        for (int j = 1; j <= 33; j++) {
            if (j == 33) {
                txt[i][j] = '\n';
            }
                //diretorio
            else if (i < 21) {
                if (j > 16) {
                    char *qwe = const_cast<char *>(gen.arquivo.c_str());
                    if (cNome < gen.arquivo.size()) {
                        char ver = qwe[cNome];
                        txt[i][j] = qwe[cNome];
                        //fprintf(arq,"%c", qwe[cNome]);
                        cNome++;
                    }
                }
            }
                //arquivos
            else {
                if (j > 8) {
                    char *qwe = const_cast<char *>(gen.cont.c_str());
                    if (cCont < gen.cont.size()) {
                        txt[i][j] = qwe[cCont];
                        //fprintf(arq,"%c", qwe[cCont]);
                        cCont++;
                    }
                }
            }
        }
    }

}

int main() {
    string oi,io;
    string* pont;
    zera();
    cout<<"#";
    //cin>>oi;
    oi = "createhd";
    if("createhd"){
        //cin>>oi;
        oi = " oi";
        puts("ok");
        createhd(oi);
    }

    //cout<<"#" << oi << "> ";
     cout<<"#" << "oi" << "> ";

    if("create"){
        //cin>>io;
        io = "Arquivo_A";
        generico gen;
        gen.arquivo = io;
        create(oi,gen);
        //salva();
        //oi = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";
    }

    //estrutura();
    salva();

    return 0;
}