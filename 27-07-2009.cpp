/*
Il programma dovrà leggere i caratteri contenuti in un file di testo ed attraverso una apposita matrice di
conversione (fornita nel testo del programma) convertirli in altri caratteri. I caratteri non presenti nella matrice
non dovranno essere convertiti. I caratteri sostituiti e quelli non sostituiti dovranno essere tutti scritti su un altro
file di testo.
Il programma dovrà prendere da tastiera il nome del file di input (max 15 caratteri), il nome del file di output
(max 15 caratteri).
Dopo aver effettuato tale conversione di caratteri, dovrà stampare a video sia il contenuto del file di input che
quello del file di output ottenuto dalla conversione.
Il programma dovrà ciclare fino a quando si inserisce il carattere s o S ed uscire dal ciclo esclusivamente
inserendo il carattere n o N. Altri caratteri genereranno un messaggio di errore.
*/
#include <iostream>
#include <fstream>
using namespace std;
const int RIGHE = 2; // Numero delle righe della matrice x
const int COLONNE = 21; // Numero delle colonne della matrice x
// Questa matrice consente di criptare il testo attraverso la conversione dei caratteri.
char x[][COLONNE] = {{'a','b','c','d','e','f','g','h','i','l','m','n','o','p','q','r','s','t','u','v','z'},
{'d','v','u','l','g','q','c','p','t','e','n','s','m','z','o','h','b','a','f','r','i'}};
void leggi_nome_file(char a[]);
void converti(char in[], char out[]);
void stampa_file(char nome[]);
int main()
{
    char s;
    char file1[15],file2[15];
    do{
        cout<<"inserisci nome file 1"<<endl;
        leggi_nome_file(file1);
        cout<<"inserisci il nome del file2"<<endl;
        leggi_nome_file(file2);
        converti(file1,file2);
        stampa_file(file1);
        stampa_file(file2);
        do{
            cout<<"Vuoi continuare [s/n]"<<endl;
            cin>>s;
            if(s!='s'&&s!='n'){
                cout<<"lettera non consentita"<<endl;
            }
        }while(s!='s'&&s!='n');
    }while(s!='n');
    return 0;
}

void leggi_nome_file(char a[]){
    int i=0;
do{
    cin>>a;
    while(a[i]!='\0'){
        i++;
    }
    if(i>15){
        cout<<"lunghezza superata"<<endl;
    }
}while(i>15);
}

void converti(char in[], char out[]){
char c;
int i=0;
fstream input,output;
input.open(in,ios::in);
output.open(out,ios::out);
while(input.get(c)){//prende il carattere dal testo
    while(i<COLONNE&&c!=x[0][i])i++;
    if(i<COLONNE&&c==x[0][i])output<<x[1][i];
    if(i==COLONNE){
        output<<c;
        i=0;
    }
}
}

void stampa_file(char nome[]){
char c;
fstream input;
input.open(nome,ios::in);
while(input.get(c)){
        cout<<c;
}
cout<<endl<<endl;
}
