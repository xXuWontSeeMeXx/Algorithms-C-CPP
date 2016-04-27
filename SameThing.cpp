#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<algorithm>

using namespace std;

class SameThing{
    public:
        void execute(){
            ifstream archivo("archivo.txt", ios::in);
            if(!archivo)
            {
                cout<<"File not found"<<endl;
                exit(1);
            }//if
            while(getline(archivo, entrada) != NULL)
            {
                int index = entrada.find(".");
                string cadena1 = entrada.substr(0, index);
                string cadena2 = entrada.substr(index + 1, entrada.size());
                cout<<procesaCadenas(cadena1, cadena2)<<endl;
            }//while
        }//execute

        int procesaCadenas(string cadena1, string cadena2){
            int salida = 0;
            if(cadena1 == cadena2)
                salida = 1;
            else{
                reverse(cadena2.begin(), cadena2.end());
                if(cadena1 == cadena2)
                    salida = 1;
            }//else
            return salida;
        }//procesaCadenas
    private:
        string entrada;
};//class SameThing

int main(){
    SameThing obj;
    obj.execute();
    return 0;
}//main
