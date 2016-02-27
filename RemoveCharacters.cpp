#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

class RemoveCharacteres{
    public:
        void execute(){
            ifstream archivo("archivo.txt", ios::in);
            if(!archivo)
            {
                cout<<"File not found."<<endl;
                exit(1);
            }//if
            string entrada;
            while(getline(archivo, entrada) != NULL)
            {
                int index = entrada.find(",");
                string cadena = entrada.substr(0, index);
                string limits = entrada.substr(index + 2, entrada.size() - 1);
                for(int i = 0; i < cadena.size(); ++i)
                {
                    if(compara(cadena[i], limits)){ }//if
                    else
                        printf("%c", cadena[i]);                    
                }//for
                cout<<endl;
            }//while
        }//execute

        int compara(char c, string limits){
            if(limits.find(c) != -1)
                return true;
            else
                return false;
        }//compara
};//class RemoveCharacteres

int main(){
    RemoveCharacteres obj;
    obj.execute();
    return 0;
}//main
