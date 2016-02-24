#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class StringPermutation{
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
                generateCadena(entrada, "", entrada.size(), entrada.size());
                printVector();
                cout<<endl;
                vect.clear();
            }//while
        }//execute

        void generateCadena(string entrada, string rnd, int n, int tam){
            if(n == 0)
                vect.push_back(rnd);
            else{
                for(int i = 0; i < tam; ++i)
                    if(rnd.find(entrada[i]) == -1)
                        generateCadena(entrada, rnd + entrada[i], n - 1, tam);
            }//else
        }//generateCadena

        void printVector(){
            sort(vect.begin(), vect.end());
            for(int i = 0; i < vect.size(); ++i)
                cout<<vect[i]<<", ";
        }//printVector
    private:
        vector<string> vect;
};//class StringPermutation

int main(){
    StringPermutation obj;
    obj.execute();
    return 0;
}//main
