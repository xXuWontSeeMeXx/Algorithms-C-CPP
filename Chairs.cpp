#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

class{
    public:
        void execute(){
            ifstream archivo("C:\\Users\\PC11-104.CUTONALA\\Downloads\\archivo.txt", ios::in);
            while(getline(archivo, entrada) != NULL)
            {
                int m = stoi(entrada, &st);
                if(m == 1)
                    cout<<0<<endl;
                else{
                    int notUsed = 0;
                    for(int i = 0; i < m - 1; ++i)
                        notUsed += 2;
                    cout<<notUsed<<endl;
                }//else
            }//while
        }//execute
    private:
        string entrada;
        string::size_type st;
};//class Chairs

int main(){
    Chairs obj;
    obj.execute();
    return 0;
}//main
