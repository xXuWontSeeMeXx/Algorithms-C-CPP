#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;

class InicialesNombre{
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
                printf("%c", toupper(entrada[0]));
                for(int i = 1; i < entrada.size(); ++i)
                {
                    if(entrada[i] == ' ')
                    {
                        printf("%c%c",entrada[i], toupper(entrada[i + 1])); 
                        ++i; 
                    }//if
                    else
                        printf("%c", entrada[i]);
                }//for
                cout<<endl;
            }//while
        }//execute
};//class InicialesNombre

int main(){
    InicialesNombre obj;
    obj.execute();
}//main
