#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

class WordToDigit{
    public:
        void execute(){
            ifstream archivo("archivo.txt", ios::in);
            if(!archivo)
            {
                cout<<"File not Found"<<endl;
                exit(1);
            }//if
            string entrada;
            while(getline(archivo, entrada) != NULL)
            {
                entrada += ";";
                string numero = "";
                for(int i = 0; i < entrada.size(); ++i)
                {
                    if(entrada[i] == ';')
                    {
                        printDigit(numero);
                        numero = "";
                    }//if
                    else
                        numero += entrada[i];
                }//for
                cout<<endl;
            }//while
        }//execute

        void printDigit(string numero){
            if(numero == "zero") cout<<"0";
            if(numero == "one") cout<<"1";
            if(numero == "two") cout<<"2";
            if(numero == "three") cout<<"3";
            if(numero == "four") cout<<"4";
            if(numero == "five") cout<<"5";
            if(numero == "six") cout<<"6";
            if(numero == "seven") cout<<"7";
            if(numero == "eight") cout<<"8";
            if(numero == "nine") cout<<"9";
        }//printDigit
};//class WordToDigit

int main(){
    WordToDigit obj;
    obj.execute();
    return 0;
}//main
