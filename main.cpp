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

void populaPrevio(){
    FILE* ler;
    ler = fopen("HD1.txt", "r");
    char *oi = nullptr;
    for (int i = 0; i <= 1024 ; i++) {
        fgets(txt[i],34,ler);
    }
    fclose(ler);
    for (int i = 0; i < 1025; i++) {
            printf("%s ", txt[i]);
        }
        puts("");
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
                fprintf(arq,"%i ", i);
            }
            else if(j == 0 && i == 0){
                fprintf(arq, "%c", 32);
            }
            else{
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

//bolar estrategia para pegar posicao inicial certa no diretorio
void create(string str,generico gen) {
    int cCont = 0, cNome = 0;
    char temp[5] = {'0','0','0','0',0};
    int garantia = 0;
    //populaPrevio();
    //cin>>gen.cont;
    gen.cont = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";

    //estrutura(2, gen);
    for (int i = 1; i <= 1024; i++) {
        for (int j = 1; j <= 33; j++) {
            if (j == 33) {
                txt[i][j] = '\n';
            }
                //diretorio
            else if (i < 21) {
                //da posicao 17 ate 32
                if (j > 16) {
                    char *qwe = const_cast<char *>(gen.arquivo.c_str());
                    if (cNome < gen.arquivo.size()) {
                        txt[i][j] = qwe[cNome];
                        cNome++;
                    }
                }
                //da posicao 13 ate 16
                else if(j > 12 && garantia == 0){
                    int tint = gen.cont.size();
                    int ant;
                    if(tint > 999){
                        ant = (tint/1000);
                        temp[0] = ant + '0';
                        tint = tint - (ant*1000);
                    }
                    if(tint > 99){
                        ant = (tint/100);
                        temp[1] = (tint/100) + '0';
                        tint = tint - (ant*100);
                    }
                    if(tint > 9){
                        ant = (tint/10);
                        temp[2] = (tint/10) + '0';
                        tint = tint - (ant*10);
                    }
                    tint = tint;
                    temp[3] = tint + '0';
                    txt[i][13] = temp[0];
                    txt[i][14] = temp[1];
                    txt[i][15] = temp[2];
                    txt[i][16] = temp[3];
                    garantia++;
                }
                // posição 9 ate 12
                //deixar para completar depois
                else if(j > 8){
                    if(i == 1){
                        txt[i][9] = '0';
                        txt[i][10] = '0';
                        txt[i][11] = '2';
                        txt[i][12] = '1';
                    }
                    else if(i > 1){
                        int tam = gen.cont.size(), ok = 0;
                        int c = 0;
                        while(ok == 0){
                            if(tam > 24){
                                c++;
                                tam = tam - 24;
                            }
                            else{
                                ok++;
                            }
                        }
                        //aqui fazemos uma logica tipo txt[i][j] == tam
                    }

                }
                //de 5 a 8, nao entendi direito como funciona
                else if(j > 4){

                }
                //para uso futuro
                else if(j == 4){
                    txt[i][j] = 32;
                }
                else if(j == 3){
                    //se for arquivo = 0, se for pasta = 1
                    txt[i][j] = '0';
                }
                else if(j == 2){
                    txt[i][j] = 0;
                }
                /*
                else if(j == 1){
                    if(gen.arquivo.size() > 1){
                        if(txt[i][j] == '0'){

                        }
                    }
                    else{
                        txt[i][j] = '0';
                    }
                }
                 */
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
        //populaPrevio();
        salva();
        //oi = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";
    }

    //estrutura();
    salva();

    return 0;
}