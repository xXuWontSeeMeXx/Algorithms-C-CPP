#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

class CountingPalindromesNumbers{
    public:
        void execute(){
            ifstream archivo("archivo.txt", ios::in);
            while(getline(archivo, entrada) != NULL)
            {
                int digitos = atoi(entrada.c_str());
                int limite = getLimite(digitos);
                cout<<getCounting(limite)<<endl;
            }//while
        }//execute

        int getLimite(int digitos){
            string limite = "";
            for(int i = 0; i < digitos; ++i)
                limite += "9";
            return atoi(limite.c_str());
        }//getLimite

        int getCounting(int limite){
            int conteo = 0;
            for(int i = 0; i <= limite; ++i)
                conteo += comparaDigito(to_string(i));
            return conteo;
        }//getCounting

        int comparaDigito(string num){
            string aux = num;
            int counting = 0;
            reverse(num.begin(), num.end());
            if(aux == num)
                counting = 1;
            return counting;
        }//comparaDigito
    private:
        string entrada;
};//class CountingPalindromesNumbers

int main(){
    CountingPalindromesNumbers obj;
    obj.execute();
}//main
