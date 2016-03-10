#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

class CaraCruz{
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
                int mary = 0;
                int john = 0;
                for(int i = 0; i < entrada.size(); ++i)
                {
                    if(entrada[i] == ' '){ }//if
                    else{
                        if(entrada[i] == '0')
                            mary++;
                        else
                            john++;
                    }//else
                }//for
                cout<<"Mary won "<<mary<<" times and John won "<<john<<" times."<<endl;
            }//while
        }//execute
};//class CaraCruz

int main(){
    CaraCruz obj;
    obj.execute();
    return 0;
}//main
