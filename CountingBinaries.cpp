#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<bitset>
#include<limits>

using namespace std;

class CountingBinaries{
    public:
        void execute(){
            ifstream archivo("archivo.txt", ios::in);
            while(getline(archivo, entrada) != NULL)
            {
                int counting = 0;
                int num = stoi(entrada, &st);
                for(int i = 1; i <= num; ++i)
                {
                    string binario = toBinary(i);
                    counting += countUnos(binario);
                }//for
                cout<<counting<<endl;
            }//while
        }//execute

        string toBinary(int num){
            string binary = bitset<numeric_limits<unsigned long long>::digits>(num).to_string();
            int index = binary.find("1");
            return binary.substr(index);
        }//toBinary

        int countUnos(string cadena){
            int sum = 0;
            for(int i = 0; i < cadena.size(); ++i)
                if(cadena[i] == '1')
                    sum++;
            return sum;
        }//countUnos
    private:
        string entrada;
        string::size_type st;
};//class CountingBinaries

int main(){
    CountingBinaries obj;
    obj.execute();
    return 0;
}//main
