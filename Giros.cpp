#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

class Giros{
    public:
        void execute(){
            ifstream archivo("archivo.txt", ios::in);
            if(!archivo)
            {
                cout<<"File not found"<<endl;
                exit(1);
            }//if
            string entrada;
            while(getline(archivo, entrada) != NULL)
            {
                int suma = 0;
                for(int i = 0; i < entrada.size(); ++i)
                {                    
                    suma += getPosicion(entrada[i]);
                    if(suma == 4 || suma == -4)
                        suma = 0;
                }//for
                if(suma == 0)
                    cout<<"N"<<endl;
                if(suma == 1 || suma == -3)
                    cout<<"E"<<endl;
                if(suma == 2 || suma == -2)
                    cout<<"S"<<endl;
                if(suma == 3 || suma == -1)
                    cout<<"W"<<endl;
            }//while
        }//execute

        int getPosicion(char c){
            if(c == 'R')
                return 1;
            else
                return -1;
        }//getPosicion
};//class Giros

int main(){
    Giros obj;
    obj.execute();
    return 0;
}//main
