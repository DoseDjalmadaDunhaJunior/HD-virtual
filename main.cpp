#include <iostream>
#include <string>
#include <stdio.h>

//int p = atoi(h);
using namespace std;
using namespace std;
char txt[1025][34];
char nomedoarquivo[20];

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

void apaga() {
    char kkk[16] = "Arquivo_B\0";
    int comp = 6;
    int ig = 0;

    int i,j;
    int rept = 0;
    for (i = 0; i < 20; i++) {
        for (j = 16; (j < 33 && txt[i][j] != 0); j++) {
            if(kkk[j-16] == txt[i][j]){
                ig++;
            }
        }
        j++;
        if((ig == (j - 17)) && rept == 0){
            txt[i][0] = '0';
            txt[ConteudoLocal(i)][0] = '0';
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


int primeiroVago(){
    FILE* ler;
    ler = fopen("HD1.txt", "r");
    char oi;
    int i;
    for (i = 20; txt[i][0] != '0'; i++) {
            fscanf(ler,"%c", &oi);
            txt[i][0] = oi;
        }
    return i;
}

void createhd(string str){
    //zera();
    salva2();
}

void create(string str,generico gen) {
    char temp[5] = {'0', '0', '0', '0', 0};
    zera();
    populaPrevio();
    int i = 0;
    cout << txt[0][0] << endl;
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
        /*
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
        */
        int soma = (primeiroVago() + 1);
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
    for (int k = i; k < 20; k++) {

    }

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
}

int main() {
    string oi,io;
    string* pont;
    zera();
    cout<<"#";
    cin>>oi;
    if("createhd"){
        cin>>oi;
        for (int i = 0; i < sizeof(oi); i++) {
            nomedoarquivo[i] = oi[i];
        }
        cout<<nomedoarquivo<<endl;
        createhd(oi);
    }

    cout<<"#" << oi << ">";
    cin>>io;
    if("create"){
        generico gen;
        cin>>gen.arquivo;
        //io = "Arquivo_C";
        cin>>gen.cont;
        //gen.cont = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";
        populaPrevio();
        create(oi,gen);

        //salva();
        //oi = "AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX AAAAAAAAAX";
    }

    //zera();
    //apaga();
    //estrutura();
    salva2();
    //salva();

    //system("pause");
    return 0;
}