#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<locale>

using namespace std;

class CamelCase{
    public:
        void execute(){
            ifstream archivo("archvo.txt", ios::in);
            if(!archivo)
            {
                cout<<"File not found"<<endl;
                exit(1);
            }//if
            string entrada;
            while(getline(archivo, entrada) != NULL)
            {   
                for(int i = 0; i < entrada.size(); ++i)
                    entrada[i] = tolower(entrada[i]);
                entrada[0] = toupper(entrada[0]);
                for(int i = 1; i < entrada.size(); ++i)
                    if(entrada[i] == ' ')
                        entrada[i + 1] = toupper(entrada[i + 1]);
                while(entrada.find(" ") != -1)
                {
                    int spc = entrada.find(" ");
                    entrada.erase(spc, 1);
                }//while
                cout<<entrada<<endl;
            }//while
        }//execute
    private:
};//class CamelCase

int main(){
    CamelCase obj;
    obj.execute();
    return 0;
}//main
