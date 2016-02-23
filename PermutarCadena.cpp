#include<iostream>
#include<string>

using namespace std;

void generarCadena(string cadenas[], string rnd, int n, int tam){
    if(n == 0)
        cout<<rnd<<endl;
    else{
        for(int i = 0; i < tam; ++i)
            if(rnd.find(cadenas[i]) == -1)
                generarCadena(cadenas, rnd + cadenas[i], n - 1, tam);
    }//else
}//generarCadena

int main(){
    string cadena = "abc";
    string cadenas[cadena.size()];
    for(int i = 0; i < cadena.size(); ++i)
        cadenas[i] = cadena[i];
    generarCadena(cadenas, "", cadena.size(), cadena.size());
    return 0;
}//main
