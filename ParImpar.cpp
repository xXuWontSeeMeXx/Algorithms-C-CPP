#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

class ParImpar{
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
                entrada += " ";
                string cadena = "";
                string n = "";
                for(int i = 0; i < entrada.size(); ++i)
                {                    
                    n += entrada[i];
                    if(entrada[i] == ' ')
                    { 
                        int num = stoi(n, &st);
                        cadena += verificaNum(num);
                        n = "";
                    }//if                  
                }//for
                if(cadena.find("11") == -1 && cadena.find("00") == -1)
                    cout<<"Correcto"<<endl;
                else
                    cout<<"Incorrecto"<<endl;          
            }//while
        }//execute

        string verificaNum(int num){
            if(num % 2 == 0)
                return "0";
            else
                return "1";
        }//verificaNum
    private:
        string::size_type st;
};//class ParImpar

int main(){
    ParImpar obj;
    obj.execute();
    return 0;
}//main
