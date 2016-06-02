#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>

using namespace std;

class HaciendoFacilSQL{
    public:
        void execute(){
            ifstream archivo("archivo.txt", ios::in);
            while(getline(archivo, entrada) != NULL)
            {
                cout<<"SELECT ";
                int parentesis = entrada.find("(");
                string table = entrada.substr(13, parentesis - 13);
                string columnas = entrada.substr(parentesis + 1, entrada.size() - parentesis - 2);
                columnas += ", ";
                int idxSpace;
                int idxComa;
                while(idxSpace != -1 || idxComa != -1)
                {                    
                    idxSpace = columnas.find(" ");
                    idxComa = columnas.find(", ");
                    if(idxSpace == -1 || idxComa == -1)
                        break;
                    idxComa += 2;
                    cout<<columnas.substr(idxSpace - idxSpace, idxSpace)<<", ";
                    columnas.erase(idxComa - idxComa, idxComa);                  
                }//while
                cout<<"FROM "<<table<<endl;
            }//while
        }//execute

    private:
        string entrada;
};//class HaciendoFacilSQL

int main(){
    HaciendoFacilSQL obj;
    obj.execute();
    return 0;
}//main
