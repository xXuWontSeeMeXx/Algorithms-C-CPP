#include<iostream>
#include<cstdlib>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class GreatestCommonDivisor{
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
                entrada += " ";
                string cadena = "";
                int bandera = 0;
                for(int i = entrada.find("A") + 2; i < entrada.size(); ++i)
                {
                    if(entrada[i] == ' ' && bandera == 0)
                    {
                        A.push_back(toInteger(cadena));
                        cadena = "";
                    }//if
                    else if(entrada[i] == ' ' && bandera == 1){
                        B.push_back(toInteger(cadena));
                        cadena = "";
                    }//else if
                    else if(entrada[i] == 'B'){
                        bandera = 1;
                        i++;
                    }//else if
                    else{
                        cadena += entrada[i];
                    }//else
                }//for                
                printA();
                cout<<endl;
                printB();
                cout<<endl;
                for(int i = 0; i < A.size(); ++i)
                {
                    int mayor = max(A[i], B[i]);
                    int bandera = 1;
                    while(bandera == 1)
                    {                              
                        if(A[i] % mayor == 0 && B[i] % mayor == 0)
                        {
                            gcd = mayor;
                            bandera = 0;
                        }//if
                        else
                            mayor--;
                    }//while
                    cout<<"   "<<gcd;
                }//for
            }//while
            cout<<endl;
        }//execute

        int toInteger(string cadena){
            return stoi(cadena, &st);
        }//toInteger

        void printA(){
            cout<<"A: ";
            for(int i = 0; i < A.size(); ++i)
                cout<<A[i]<<"  ";
        }//printA

        void printB(){
            cout<<"B: ";
            for(int i = 0; i < B.size(); ++i)
                cout<<B[i]<<"  ";
        }//printA
    private:
        string entrada;
        string::size_type st;
        vector<int> A;
        vector<int> B;
        int gcd;
};//class GreatestCommonDivisor

int main(){
    GreatestCommonDivisor obj;
    obj.execute();
    return 0;
}//main
