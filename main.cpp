#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>


/**
 * no main tem uma funcao comentada chamada apagar, basta tirar o comentario para poder usa-la
 */
using namespace std;
using namespace std;
char txt[1025][34];
char nomedoarquivo[20];
int posicaoDaPasta = 0;

struct generico{
    string cont;
    string arquivo;
};

//8 ao 11
int posicaoConteudo(int po) {
    int mil = (txt[po][8] - '0');
    int centena = (txt[po][9] - '0');
    int dez = (txt[po][10] - '0');
    int unidade = (txt[po][11] - '0');
    int total = (1000*mil) + (100 * centena) + (10*dez) + unidade;
    return total;
}

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
    char oi;
    for (int i = 0; i < 1025; i++) {
        for (int j = 0; j < 34; j++) {
            fscanf(ler,"%c", &oi);
            txt[i][j] = oi;
        }
    }
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

int tamanho(char* gol){
    int i;
    for (i = 0; (gol[i] != 32) && (gol[i] != '\0') ; i++) {

    }
    return i;
}

//12 ao 15
int tamanhoSalvo(int po){
    int mil = (txt[po][12] - '0');
    int centena = (txt[po][13] - '0');
    int dez = (txt[po][14] - '0');
    int unidade = (txt[po][15] - '0');
    int total = (1000*mil) + (100 * centena) + (10*dez) + unidade;
    return total;
}

//busca a linha que tem o arquivo mandado
int buscaLinha(char* str){
    int i;
    int ver = 0;
    int ig = 0;
    for (i = 0; (txt[i][0] != '0') && i < 20 ; i++) {
        for (int j = 16; (j - 16) < tamanho(str); j++) {
            if(j == 22 && i == 3){

            }
            if (str[j-16] == txt[i][j]) {
                ig++;
            }
        }
        if(ig == tamanho(str)){
            return i;
        }
        else{
            ig = 0;
        }
    }
    return -1;
}

void apaga() {
    char kkk[16];
    puts("nome do arquivo");
    cin>>kkk;
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
    int i = 20;
    while(txt[i][0] != '0'){
        fscanf(ler,"%c", &oi);
        txt[i][0] = oi;
        i++;
    }
    return i;
}

void createhd(string str){
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
    txt[i][0] = '1';
    txt[i][1] = '0';
    txt[i][2] = '0';
    txt[i][3] = ' ';
    txt[i][4] = '0';
    txt[i][5] = '0';
    txt[i][6] = '0';
    txt[i][7] = (posicaoDaPasta + '0');
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
    txt[g][4] = '0';
    txt[g][5] = '0';
    txt[g][6] = '2';
    txt[g][7] = '2';
    int Ctam = gen.cont.size();
    int vet = 8;
    int poMat = 8;
    int contador = 1;
    int anterior = g;
    int acom = 8;
    char *asd = const_cast<char *>(gen.cont.c_str());
    for (int l = 8; asd[l-8] != '\0'; l++) {
        if(asd[vet - 8] == 32){
            vet++;
        }
        if(l > 50){

        }
        int x = contador;
        if(acom > 32){
            contador++;
            poMat = 8;
            g++;
            txt[g][0] = '1';
            txt[g][1] = '1';
            txt[g][2] = ' ';
            txt[g][3] = ' ';
            txt[g][4] = '0';
            txt[g][5] = '0';
            txt[g][6] = '0';
            txt[g][7] = '0';
            acom = 8;
        }
        if(x != contador){
            txt[g][poMat] = 0;

        }else {
            txt[g][poMat] = asd[vet - 8];
        }
        vet++;
        acom++;
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
    txt[i][7] = (posicaoDaPasta + '0');
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
    posicaoDaPasta = i;
}

void dir(char* victor){
    zera();
populaPrevio();
//nome comeca na posicao 16 e termina na 32
//4 a 7 qual pasta
//12 a 15 tamanho do arquivo
    int i = 0;
    char po[19];
    for (i = 0; (i <= 1024) && (txt[i][0] == '1'); i++) {
        po[i] = txt[i][7];
    }
    po[i] = '\0';
    int ver = buscaLinha(victor);//7
    int mil,cen,dez,uni,l;
    for (int j = 0; txt[j][0] != '0' ; j++) {
        if(txt[j][7] == (ver+'0')){
            for (l = 16; txt[j][l] != 32; l++) {

            }
            for (int k = 16; (k-16) < (l-16); k++) {
                if(txt[j][2] == '0' && txt[j][k] != 0) {
                    cout << txt[j][k];
                }else if(txt[j][2] == '1' && txt[j][k] != 0){
                    cout << txt[j][k];
                }

            }
            if(txt[j][2] == '0'){
                mil = (txt[j][12]) - '0';
                cen = (txt[j][13]) - '0';
                dez = (txt[j][14]) - '0';
                uni = txt[j][15] - '0';
                cout<<" "<<(mil+cen+dez+uni)<<" bytes"<<endl;
            }

        }
    }
}

void existe(char* hd){
    FILE* arq;
    arq = fopen(hd, "r");
    if(!arq) {
        FILE* temp;
        temp = fopen(hd, "w");
        strcpy(nomedoarquivo, hd);
        zera();
        salva2();
        fclose(temp);
    }
    else {
        fclose(arq);
    }
}

void imprimeConteudo(int po){
    for (int i = 8; txt[po][i] != 32; i++) {
        if(i == 31){
            po++;
            i = 8;
            cout<<endl;
        }
        cout<<txt[po][i];
    }
}

//basicamente imprime no proprio terminal o que tem no arquivo
void type(char* lucas) {
    zera();
    populaPrevio();
    int ig = 0;
    int i, j;
    int rept = 0;
    for (i = 0; i < 20; i++) {
        for (j = 16; (j < 33 && txt[i][j] != 0); j++) {
            if (lucas[j - 16] == txt[i][j]) {
                ig++;
            }
        }
        j++;
        if ((ig == (j - 17)) && rept == 0) {
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
            imprimeConteudo((ola2-1));
            rept = 1;
        } else {
            ig = 0;
        }
    }
}

//copia o conteudo de um arquivo a partir da sua linha
void copiaConteudo(char* cont, int linha) {
    int l = posicaoConteudo(linha) - 1;
    int gg = tamanhoSalvo(linha);
    for (int i = 8; i < gg; i++) {
        //inicialmente farei para apenas 1 linha
        if (txt[l][i] == 32) {
            cont[i-8] = 0;
        }
        cont[i-8] = txt[l][i];
    }
}

//para buscar itens numa pasta especifica
int buscaNpasta(int n, char* term){
    int i;
    int ver = 0;
    int ig = 0;
    for (i = 0; (txt[i][0] != '0') && i < 20 ; i++) {
    if(txt[i][7] == (n+'0')){

    }
        if(ig == tamanho(term)){
            return i;
        }
        else{
            ig = 0;
        }
    }
    return -1;
}

int contBarra(char* segurar){
    int c = 0;
    for (int i = 0; (segurar[i] != 0); i++) {
        if(segurar[i] == '/'){
            c++;
        }
    }
    return c;
}

/*basicamente essa função é para o copy, vai ver se a
 * logica das pastas ate o arquivo é permitida ou tem algum erro
 * ou seja ja vai direto para onde importa
 */
int logicaPode(char* vetor){
    int n = contBarra(vetor), c =0;
    int po = -1, poAnt = -1,j,i;
    char copia[100];
    for (i = 1; i < n ; i++) {
        for (j = i; (vetor[j] != '/') && (vetor[j] != 0); j++) {
            copia[j-i] = vetor[j];
        }
        if(vetor[j] == 0){
            copia[j-i] = 0;
        }
        i = j;
        poAnt = po;
        po = buscaLinha(copia);
        if(posicaoConteudo(po) != poAnt && poAnt != -1){
            return -1;
        }
    }
    cout<<po<<endl;
    return po;
}
// a variavel ultraFarma já esta praticamente certinha para gravar no lugar certo

void copy(char* seg) {
    populaPrevio();
    char termo2[100];
    char origem[100];
    int i = 0;
    cin >> termo2;
    //aqui é tudo relacionado a 1ª parcela
    logicaPode(seg);
    for (i = 1; seg[i] != '/'; i++) {
        origem[i - 1] = seg[i];
    }
    origem[i - 1] = 0;
    char tempo[100];
    int j;
    for (j = 0; (txt[j][7] != (buscaLinha(origem) + '0')) && (j < 20); j++) {

    }
    if (j < 20) {
        copiaConteudo(tempo, j);
        //a partir daqui é relacionado a 2ª parcela
        char arq[100];
        int c = contBarra(termo2), andado = 0,andandoMeio = 0;
        for (int k = 0; termo2[k] != 0; k++) {
            //aqui ele identifica quando vai chegar no nome do arquivo de copia
            if (c == 0) {
                int x = andado+andandoMeio;
                arq[k-x] = termo2[k];
            }
            else{
                andado++;
                if(termo2[k] == '/'){
                    c--;
                }
            }
        }
        generico ultraFarma;
        ultraFarma.arquivo = arq;
        ultraFarma.cont = tempo;
        cout<<arq<<endl;
    } else {
        cout << "alguma informação invalida" << endl;
    }

}

int main() {
    string oi, io, exit, seg, constante;
    string antigo = "";
    char gene[20] = " ";
    zera();
    //cin>>oi;
    //cin>>seg;
    oi = "createhd";
    seg = "HD1";
    //seg = "createhd";
    exit = oi;
    if ("createhd" == oi) {
        oi = "HD1.txt";
        strcpy(gene, seg.c_str());
        existe(gene);
        oi = gene;
        exit = oi;
        int i;
        for (i = 0; i < sizeof(oi); i++) {
            nomedoarquivo[i] = oi[i];
        }
        createhd(seg);
    }
    char *qwe = const_cast<char *>(oi.c_str());
    int j;
    for (j = 0; qwe[j] != '.'; j++) {

    }
    qwe[j] = 0;
    constante = qwe;
    int x = 0;
    cout << "#" << constante << ">";
    while ((oi != "exit") && (io != "exit") && (seg != "exit") && (exit != "exit")) {
        exit = io;
        if (x > 0) {
            cout << "\n#" << constante << antigo << ">";// mudar aqui
        }

        cin >> oi;
        if (oi != "dir") {
            cin >> seg;
        } else {
            seg = " ";
        }
        //oi = "create";
        if ("mkdir" == oi) {
            string dente;
            dente = seg;
            populaPrevio();
            createMK(oi, dente);
        } else if ("create" == oi) {
            generico gen;
            gen.arquivo = seg;
            cin >> oi;
            gen.cont = oi;
            populaPrevio();
            create(oi, gen);
        } else if ("cd" == oi) {
            if (seg == "..") {
                int i;
                int k;
                char *mko = const_cast<char *>(antigo.c_str());
                for (i = 0; mko[i] != '\0'; i++) {

                }
                for (k = (i - 1); mko[k] != '\\'; k--) {
                    mko[k] = 0;
                }
                mko[k - 1] = 0;
            } else {
                strcpy(gene, seg.c_str());
                populaPrevio();
                if (logCD(gene) > -1) {
                    x = -1;
                    antigo = antigo + "\\" + gene;
                    cout << "#" << constante << antigo << ">";

                } else {
                    puts("");
                    puts("pasta nao encontrada");
                }
            }
        } else if ("dir" == oi) {
            dir(gene);
        }else if ("type" == oi) {
            char temp[1024];
            strcpy(temp, seg.c_str());
            type(temp);
        }
        else if("copy" == oi){
            char temp[200];
            strcpy(temp, seg.c_str());
            copy(temp);
        }

        //zera();
        //apaga();
        salva2();
        x++;

        //system("pause");
    }
    return 0;
}