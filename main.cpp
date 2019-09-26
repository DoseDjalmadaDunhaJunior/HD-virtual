#include <iostream>
#include <string>
#include <stdio.h>

//int p = atoi(h);
using namespace std;
using namespace std;
char txt[1025][34];

struct generico{
    string cont;
    string arquivo;
};

void teste(){
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            txt[i][j] = (65 + i);
        }
    }
    FILE* arq;
    arq = fopen("HD1.txt", "w");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fprintf(arq,"%c", txt[i][j]);
        }
        fprintf(arq, "%c", '\n');
    }
    fclose(arq);
}

typedef struct generico generico;

void zera(){
    for (int i = 0; i < 1025; i++) {
        for (int j = 0; j < 34; j++) {
            if((j == 0 || j == 1)&& i < 20){
                txt[i][0] = '0';
                txt[i][1] = '0';
            }
            else if ((j == 0 || j == 1)&& i >= 21){
                txt[i][0] = '0';
                txt[i][1] = '1';
            }
            else if(j == 33){
                txt[i][j] = '\n';
            }
            else{
                txt[i][j] = 32;
            }
        }
    }
}

void populaPrevio(){
    FILE* ler;
    ler = fopen("HD1.txt", "r");
    char oi;
    for (int i = 0; i < 1025; i++) {
        for (int j = 0; j < 34; j++) {
            fscanf(ler,"%c", &oi);
            txt[i][j] = oi;
        }
        //fgets(txt[i],100,ler);
    }
    cout<<txt[1][20]<<endl;
}

void apaga() {
    char kkk[16] = "Arquivo_B\0";
    int comp = 6;
    int ig = 0;

    int i,j;
    char v1,v2;
    int v3;
    int rept = 0;
    for (i = 0; i < 20; i++) {
        for (j = 16; (j < 33 && txt[i][j] != 0); j++) {
            v1 = kkk[j-16];
            v2 = txt[i][j];
            if(kkk[j-16] == txt[i][j]){
                ig++;
            }
        }
        j++;
        //int soma = j -16;
        v3 = j - 17;
        if((ig == (j - 17)) && rept == 0){
            txt[i][0] = '0';
            rept = 1;
        }
        else{
            ig = 0;
        }
    }
}

void salva2(){
    FILE* arq;
    arq = fopen("HD1.txt", "w");
    for (int i = 0; i <= 1025 ; i++) {
        for (int j = 0; j <= 33; j++) {
            fprintf(arq,"%c", txt[i][j]);
        }
    }
    fclose(arq);
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
    generico x;
    arq = fopen(str.c_str(), "w");
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
    char temp[5] = {'0', '0', '0', '0', 0};
    int garantia = 0;
    zera();
    populaPrevio();
    //cin>>gen.cont;
    //gen.cont = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";
    gen.cont = "ABACATE";
    int i = 0;
    cout<<txt[0][0]<<endl;
    for (i = 0; (i <= 1024) && (txt[i][0] == '1'); i++) {

    }

    cout<<txt[0][0]<<endl;
    txt[i][0] = '1';
    txt[i][1] = '0';
    txt[i][2] = '0';
    txt[i][3] = ' ';
    txt[i][4] = '0';
    txt[i][5] = '0';
    txt[i][6] = '0';
    txt[i][7] = '0';
    if(i == 0){
        txt[i][8] = '0';
        txt[i][9] = '0';
        txt[i][10] = '2';
        txt[i][11] = '1';
    }
    else {
        int mil = 0,cen = 0,dez = 0,uni = 0;
        if (txt[i-1][8] > '0') {
            char y = txt[i-1][8];
            mil = y - '0';
            mil = mil*1000;
        }
        if(txt[i-1][9] > '0'){
            char y = txt[i-1][9];
            cen = y - '0';
            cen = cen*100;
        }
        if(txt[i-1][10] > '0'){
            char y = txt[i-1][10];
            dez = y - '0';
            dez = dez*10;
        }
        if(txt[i-1][11] > '0'){
            char y = txt[i-1][11];
            uni = y - '0';
        }
        int soma = mil+cen+dez+uni;
        soma++;
        int ant;
        if (soma > 999) {
            ant = (soma / 1000);
            temp[0] = ant + '0';
            soma = soma - (ant * 1000);
        }
        if (soma > 99) {
            ant = (soma / 100);
            temp[1] = (soma / 100) + '0';
            soma = soma - (ant * 100);
        }
        if (soma > 9) {
            ant = (soma / 10);
            temp[2] = (soma / 10) + '0';
            soma = soma - (ant * 10);
        }
        soma = soma;
        temp[3] = soma + '0';
        txt[i][8] = temp[0];
        txt[i][9] = temp[1];
        txt[i][10] = temp[2];
        txt[i][11] = temp[3];
    }
    int tint = gen.cont.size();
    int ant = 0;
    if (tint > 999) {
        ant = (tint / 1000);
        temp[0] = ant + '0';
        tint = tint - (ant * 1000);
    }
    else{
        temp[0] = '0';
    }
    if (tint > 99) {
        ant = (tint / 100);
        temp[1] = (tint / 100) + '0';
        tint = tint - (ant * 100);
    }
    else{
        temp[1] = '0';
    }
    if (tint > 9) {
        ant = (tint / 10);
        temp[2] = (tint / 10) + '0';
        tint = tint - (ant * 10);
    }
    else{
        temp[2] = '0';
    }
    tint = tint;
    temp[3] = tint + '0';
    txt[i][12] = temp[0];
    txt[i][13] = temp[1];
    txt[i][14] = temp[2];
    txt[i][15] = temp[3];
    char *qwe = const_cast<char *>(gen.arquivo.c_str());
    for (int l = 16; l < 32; l++) {
        txt[i][l] = qwe[l - 16];
    }
    for (int k = i; k < 20; k++) {
        //txt[k][0] = '0';
        //txt[k][1] = '0';
    }
    //txt[i][32] = '\n';
    i = 20;
    int g = i;
    for (g; (g <= 1024) && (txt[g][0] == '1'); g++) {

    }
    txt[g][0] = '1';
    txt[g][1] = '1';
    txt[g][2] = ' ';
    txt[g][3] = ' ';
    txt[g][4] = '0';// deveria ter um zero a menos
    txt[g][5] = '0';
    txt[g][6] = '0';
    txt[g][7] = '2';
    txt[g][8] = '2';
    int Ctam = gen.cont.size();

    char *asd = const_cast<char *>(gen.cont.c_str());
    for (int l = 9; asd[l-9] != '\0'; l++) {
        if(Ctam > 23){
            Ctam = Ctam-23;
            txt[g][(23 -(l-9))] = asd[l-9];
        }
        else{
            txt[g][l] = asd[l-9];
        }
    }

    //txt[g][32] = '\n';
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
        //teste();
        io = "Arquivo_C";
        generico gen;
        gen.arquivo = io;
        populaPrevio();
        //create(oi,gen);

        //salva();
        //oi = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";
    }

    //zera();
    apaga();
    //estrutura();
    salva2();
    //salva();

    return 0;
}