#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

vector<string> cadenas;

void insertaVector(string cadena){
    cadenas.push_back(cadena);
}//insertaVector

void printPalabra(){
    for(int i = cadenas.size() - 1; i >= 0; --i)
        cout<<cadenas[i]<<" ";
    cout<<endl;
}//printPalabra

int main(){
    fstream archivo("archvo.txt", ios::in);
    if(!archivo)
    {
        cout<<"file not found"<<endl;
        exit(1);
    }//if
    string entrada;
    while(getline(archivo, entrada) != NULL)
    {
        entrada += " .";
        string cadena = "";
        for(int i = 0; i < entrada.size(); ++i)
        {   
            if(entrada[i] == '.')
                insertaVector("\n");        
            else if(entrada[i] == ' ')
            {
                insertaVector(cadena);
                cadena = "";
            }//if
            else                
                cadena += entrada[i];
        }//for
    }//while
    printPalabra();
    return 0;
}//main
