#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

class CostalesAzucar{
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
                int index = entrada.find(" ");
                string n1 = entrada.substr(0, index);
                index++;
                string n2 = entrada.substr(index, entrada.size() - index);
                int cantidad = stoi(n1, &st);
                int toneladas = stoi(n2, &st);
                cout<<"Bags of sugar full: "<<cantidad / toneladas<<endl;
                cout<<"Tonnes left: "<<cantidad % toneladas<<endl;
            }//while
        }//execute
    private:
        string:: size_type st;
};//class CostalesAzucar

int main(){
    CostalesAzucar obj;
    obj.execute();
    return 0;
}//main
