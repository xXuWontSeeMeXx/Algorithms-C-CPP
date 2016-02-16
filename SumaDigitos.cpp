#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

int main(){
    ifstream archivo("archivo.txt", ios::in);
    string::size_type st;
    if(!archivo)
    {
        cout<<"File not found"<<endl;
        exit(1);
    }//if
    string entrada;
    int suma = 0;
    while(getline(archivo, entrada) != NULL)
    {
        int num = stoi(entrada, &st);
        cout<<num;
        while(num > 0)
        {
            suma += num % 10;
            num /= 10;
        }//while
    }//while
    cout<<" sum = "<<suma<<endl;
    return 0;
}//main
