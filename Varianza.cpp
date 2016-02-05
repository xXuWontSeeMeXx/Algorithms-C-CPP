#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class Varianza{
    public:
        void execute(){
            fstream archivo("archivo.txt", ios::in);
            if(!archivo)
            {
                cout<<"File not found"<<endl;
                exit(1);
            }//if
            string entrada;
            while(getline(archivo, entrada) != NULL)
            {
                int num = stoi(entrada, &st);
                inserta(num);
            }//while
            int n = arreglo.size();
            int suma = 0;
            for(int i = 0; i < n; ++i)
                suma += arreglo[i];
            int media = suma / n;
            int vrz = 0;
            for(int i = 0; i < n; ++i)
                vrz += getVarianza(arreglo[i], media);            
            cout<<"Variance: "<<vrz / n<<endl;
        }//execute

        void inserta(int num){
            arreglo.push_back(num);
        }//inserta

        int getVarianza(int num, int media){
            return (num - media) * (num - media);
        }//getVarianza
    private:
        vector<int> arreglo;
        string::size_type st;
};//class Varianza

int main(){
    Varianza obj;
    obj.execute();
    return 0;
}//main
