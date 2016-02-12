#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class Diamante{
    public:
    	void execute(){
            ifstream archivo("archivo.txt", ios::in);
            if(!archivo)
            {
            	cout<<"File not found"<<endl;
            }//if
            string entrada;
            while(getline(archivo, entrada) != NULL)
            {
                for(int i = 0; i < entrada.size(); ++i)
                {
                	espacios.push_back(" ");
                	cadena.push_back(entrada[i] + "");
                }//for
                espacios.pop_back();
                string palabra = "";
                while(!cadena.empty())
                {
                    printEspacios();
                    string c = cadena.back();
                    palabra += c;
                    cout<< c << palabra <<endl;
                    espacios.pop_back();
                    cadena.pop_back();
                }//while
            }//while
    	}//execute

        void printEspacios(){
            for(int i = 0; i < espacios.size(); ++i)
                cout<<espacios[i];
        }//printEspacios
    private:
        vector<string> espacios;
        vector<string> cadena;
        vector<string> reversa;
};//class Diamante

int main(){
	Diamante obj;
	obj.execute();
    return 0;
}//main
