#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class StatisticalMethods{
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
                int num = stoi(entrada, &st);
                vect.push_back(num);
            }//while
            int media = preparaElementos();
            int opc;
            do{
                printMenu();               
                cin>>opc;
                switch(opc)
                {
                    case 1: printElements(); break;
                    case 2: cout<<media<<endl; break;
                    case 3: cout<<printMedian()<<endl; break;
                    case 4: cout<<printMode()<<endl; break;
                    case 5: cout<<printRange()<<endl; break;
                    case 6: cout<<printVariance(media)<<endl; break;
                    case 7: cout<<printMeanDeviation(media)<<endl; break;
                    case 8: cout<<sqrt(printVariance(media))<<endl; break;
                }//switch
            }while(opc != 9);
        }//execute

        void printMenu(){
            cout<<"1. Print elements."<<endl;
            cout<<"2. Print Mean."<<endl;
            cout<<"3. Print Median."<<endl;
            cout<<"4. Print Mode."<<endl;           
            cout<<"5. Print Range."<<endl;
            cout<<"6. Print Variance."<<endl;
            cout<<"7. Print Mean Deviation."<<endl;
            cout<<"8. Print Standard Deviation."<<endl;
            cout<<"9. Terminate."<<endl;
            cout<<"Selection... ";
        }//printMenu
   
        int preparaElementos(){
            sort(vect.begin(), vect.end());
            int media = 0;
            for(int i = 0; i < vect.size(); ++i)
                media += vect[i];
            return media / vect.size();
        }//preparaElementos

        void printElements(){
            cout<<"Size: "<<vect.size()<<" --> { ";
            for(int i = 0; i < vect.size(); ++i)
                cout<<vect[i]<<"  ";
            cout<<"}"<<endl;
        }//printElements

        int printMedian(){
            if(vect.size() % 2 == 0)
            {
                int medio = vect.size() / 2;
                medio--;
                int mediana = (vect[medio] + vect[medio + 1]) / 2;
                return mediana;
            }//if
            else{
                int mediana = vect.size() / 2;                
                return vect[mediana];
            }//else
        }//printMedian

        int printMode(){
            int count = 1;
            int max = 0;
            int moda = vect[0];
            for(int i = 0; i < vect.size() - 1; ++i)
            {
                if(vect[i] == vect[i + 1])
                {
                    count++;
                    if(count > max)
                    {
                        max = count;
                        moda = vect[i];
                    }//if
                }//if
                else
                    count = 1;
            }//for
            return moda;
        }//printMode

        int printRange(){
            return vect[vect.size() - 1] - vect[0];
        }//printRange

        int printVariance(int media){
            int suma = 0;
            for(int i = 0; i < vect.size(); ++i)
                suma += (vect[i] - media) * (vect[i] - media);
            return suma / vect.size();
        }//printVariance

        int printMeanDeviation(int media){
            int suma = 0;
            for(int i = 0; i < vect.size(); ++i)
                suma += abs(vect[i] - media);
            return suma / vect.size();
        }//printMeanDeviation
    private:
        vector<int> vect;
        string:: size_type st;
};//StatisticalMethods

int main(){
    StatisticalMethods obj;
    obj.execute();
    return 0;
}//main
