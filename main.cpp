#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
using namespace std;
char txt[1025][34];
char nomedoarquivo[20];

struct generico{
    string cont;
    string arquivo;
};

typedef struct generico generico;

void zera(){
    for (int i = 0; i < 1025; i++) {
        for (int j = 0; j < 34; j++) {
            if((j == 0 || j == 1)&& i < 20){
                txt[i][0] = '0';
                txt[i][1] = '0';
            }
            else if ((j == 0 || j == 1)&& i >= 20){
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
    ler = fopen(nomedoarquivo, "r");
    char *ver = nomedoarquivo;
    char oi;
    for (int i = 0; i < 1025; i++) {
        for (int j = 0; j < 34; j++) {
            fscanf(ler,"%c", &oi);
            txt[i][j] = oi;
        }
    }
}

int ConteudoLocal(int i){
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
    return soma;
}

void apagaConteudo(int po) {
    txt[po][0] = '0';
    if (txt[(po + 1)][7] == '0') {
        txt[(po + 1)][0] = '0';
        if (txt[(po + 2)][7] == '0') {
            txt[(po + 2)][0] = '0';

        }
    }
}

void apaga() {
    char kkk[16] = "Arquivo_E\0";
    //cin>>kkk;
    int comp = 6;
    int ig = 0;
    int i, j;
    int rept = 0;
    for (i = 0; i < 20; i++) {
        for (j = 16; (j < 33 && txt[i][j] != 0); j++) {
            if (kkk[j - 16] == txt[i][j]) {
                ig++;
            }
        }
        j++;
        // aqui esta imprimindo apenas para o 1º caso, ver isso
        if ((ig == (j - 17)) && rept == 0) {
            txt[i][0] = '0';
            char ola[5];
            ola[0] = txt[i][8];
            ola[1] = txt[i][9];
            ola[2] = txt[i][10];
            ola[3] = txt[i][11];
            int ola2 = 0;
            ola2 = (ola[0] - '0') * 1000;
            ola2 = ola2 + ((ola[1] - '0') * 100);
            ola2 = ola2 + ((ola[2] - '0') * 10);
            ola2 = ola2 + ((ola[3] - '0'));
            apagaConteudo((ola2-1));
            rept = 1;
        } else {
            ig = 0;
        }
    }
}

void salva2(){
    FILE* arq;
    arq = fopen(nomedoarquivo, "w");
    for (int i = 0; i <= 1025 ; i++) {
        for (int j = 0; j <= 33; j++) {
            fprintf(arq,"%c", txt[i][j]);
        }
    }
    fclose(arq);
}

int primeiroVago(){
    FILE* ler;
    ler = fopen(nomedoarquivo, "r");
    char oi;
    char v1;
    char v2;
    v1 = txt[20][0];
    v2 = txt[21][0];
    int i = 20;
    while(txt[i][0] != '0'){
        fscanf(ler,"%c", &oi);
        txt[i][0] = oi;
        i++;
    }
    return i;
}

void createhd(string str){
    //zera();
    populaPrevio();
    salva2();
}

int logCD(char* pasta){
    int comp = -1;
    int i = 0;
    for (i = 0; (i <= 19) && (txt[i][0] == '1'); i++) {
        if(txt[i][2] == '1'){
            int ig = 0;
            int i,j;
            int rept = 0;
            for (i = 0; i < 20; i++) {
                for (j = 16; (j < 33 && txt[i][j] != 0); j++) {
                    if(pasta[j-16] == txt[i][j]){
                        ig++;
                    }
                }
                j++;
                if((ig == (j - 17)) && rept == 0){
                    comp = i;
                    rept = 1;
                }
                else{
                    ig = 0;
                }
            }
        }
    }
    return comp;
}

void create(string str,generico gen) {
    char temp[5] = {'0', '0', '0', '0', 0};
    int g = primeiroVago();
    zera();
    populaPrevio();
    int i = 0;
    for (i = 0; (i <= 1024) && (txt[i][0] == '1'); i++) {

    }
    cout << txt[0][0] << endl;
    txt[i][0] = '1';
    txt[i][1] = '0';
    txt[i][2] = '0';
    txt[i][3] = ' ';
    txt[i][4] = '0';
    txt[i][5] = '0';
    txt[i][6] = '0';
    txt[i][7] = '0';
    if (i == 0) {
        txt[i][8] = '0';
        txt[i][9] = '0';
        txt[i][10] = '2';
        txt[i][11] = '1';
    } else {
        int soma = g+1;
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
    } else {
        temp[0] = '0';
    }
    if (tint > 99) {
        ant = (tint / 100);
        temp[1] = (tint / 100) + '0';
        tint = tint - (ant * 100);
    } else {
        temp[1] = '0';
    }
    if (tint > 9) {
        ant = (tint / 10);
        temp[2] = (tint / 10) + '0';
        tint = tint - (ant * 10);
    } else {
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
    txt[g][0] = '1';
    txt[g][1] = '1';
    txt[g][2] = ' ';
    txt[g][3] = ' ';
    txt[g][4] = '0';// deveria ter um zero a menos
    txt[g][5] = '0';
    txt[g][6] = '2';
    txt[g][7] = '2';
    int Ctam = gen.cont.size();
    int vet = 8;
    int poMat = 8;
    int contador = 1;
    int anterior = g;
    char *asd = const_cast<char *>(gen.cont.c_str());
    for (int l = 8; asd[l-8] != '\0'; l++) {
        if(asd[vet - 8] == 32){
            vet++;
        }
        if((l/contador) > 32){
            contador++;
            poMat = 8;
            g++;
            txt[g][0] = '1';
            txt[g][1] = '1';
            txt[g][2] = ' ';
            txt[g][3] = ' ';
            txt[g][4] = '0';// deveria ter um zero a menos
            txt[g][5] = '0';
            txt[g][6] = '0';
            txt[g][7] = '0';
        }
            txt[g][poMat] = asd[vet-8];
        vet++;
        poMat++;
    }

    int aux = g;
    if (aux > 999) {
        ant = (anterior / 1000);
        txt[anterior][4] = ant + '0';
        aux = aux - (ant * 1000);
    } else {
        txt[aux][4] = '0';
    }
    if (aux > 99) {
        ant = (anterior / 100);
        txt[anterior][5] = (aux / 100) + '0';
        aux = aux - (ant * 100);
    } else {
        txt[aux][5] = '0';
    }
    if (aux > 9) {
        ant = (aux / 10);
        txt[anterior][6] = (aux / 10) + '0';
        aux = aux - (ant * 10);
    } else {
        txt[anterior][6] = '0';
    }
    txt[anterior][7] = aux + '0';
}

void createMK(string str,string gen) {
    zera();
    populaPrevio();
    int i = 0;
    for (i = 0; (i <= 19) && (txt[i][0] == '1'); i++) {

    }
    txt[i][0] = '1';
    txt[i][1] = '0';
    txt[i][2] = '1';
    txt[i][3] = ' ';
        txt[i][4] = '0';
        txt[i][5] = '0';
        txt[i][6] = '0';
        txt[i][7] = '0';
    txt[i][8] = '0';
    txt[i][9] = '0';
    txt[i][10] = '0';
    txt[i][11] = '0';
    txt[i][12] = '0';
    txt[i][13] = '0';
    txt[i][14] = '0';
    txt[i][15] = '0';
    char *qwe = const_cast<char *>(gen.c_str());
    for (int l = 16; l < 32; l++) {
        txt[i][l] = qwe[l - 16];
    }
}

int main() {
    string oi,io, exit,seg;
    string* pont;
    zera();
    cout<<"#";
    //cin>>oi;
    //cin>>seg;
    seg = "createhd";
    exit = oi;
    if("createhd" == seg){
        //oi = seg;
        //criar variavel fixa p/ oi
        oi = "HD1.txt";
        exit = oi;
        int i;
        for (i = 0; i < sizeof(oi); i++) {
            nomedoarquivo[i] = oi[i];
        }

        createhd(oi);
    }
    exit = io;
    //while(exit != "exit") {
        cout << "#" << oi << ">";
    //cin>>oi;
    //cin>>seg;
    oi = "create";
        if("mkdir" == oi){
            string dente;
            dente = seg;
            dente = "Pasta_B";
            populaPrevio();
            createMK(oi, dente);
        }else if ("create" == oi) {
        generico gen;
        gen.arquivo = "Arquivo_F";
        //gen.arquivo = seg;
        //cin >> gen.cont;
        //gen.cont = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";
        gen.cont = "A B";
        populaPrevio();
        //create(oi, gen);
    }
        else if("cd" == oi){
            char gen[20] = "Pasta_A";
            strcpy(gen,seg.c_str());
            populaPrevio();
            if(logCD(gen) > -1){
               cout<<"# "<<"HD1"<<"\\"<<gen<<">";
            }
            else{
                puts("");
                puts("pasta nao encontrada");
            }
        }

        //zera();
        apaga();
        salva2();
    //}
    //system("pause");

    return 0;
}