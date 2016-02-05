#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

class RevesCuadrado{
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
                string s1 = "";
                string s2 = "";
                string final = "";
                float num;
                if(entrada.find(".") > -1)
                {                    
                    int index = entrada.find(".");
                    string n1 = entrada.substr(0, index);
                    index++;
                    string n2 = entrada.substr(index, entrada.size() - index);                    
 		    for(int i = n1.size() - 1; i >= 0; --i)
                        s1 += n1[i];
                    for(int i = n2.size() - 1; i >= 0; --i)
                        s2 += n2[i];
                    final = s2 + "." + s1;
	            num = stof(final, &st);
                    cout<<"jajajaj   "<<final<<endl;
                    //cout<<setw(10)<<entrada<<setw(10)<<final<<setw(10)<<num * num<<endl;
                    //cout<<"     "<<entrada<<"     "<<final<<"     "<<num * num<<endl;
                }//if
                else{
                    for(int i = entrada.size() - 1; i >= 0; --i)
                        final += entrada[i];
                    num = stof(final, &st);
                    //cout<<setw(10)<<entrada<<setw(10)<<final<<setw(10)<<num * num<<endl;
                    //cout<<"     "<<entrada<<"     "<<final<<"     "<<num * num<<endl;
                }//else
            }//while
        }//execute
    private:
        string::size_type st;
};//class RevesCuadrado

int main(){
    RevesCuadrado obj; 
    obj.execute();
    return 0;
}//main
