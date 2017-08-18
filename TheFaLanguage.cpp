#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class TheFaLanguaje{
	public:
		void execute(){
			ifstream archivo("archivo.txt", ios::in);
			string entrada;
			while(getline(archivo, entrada) != NULL)
			{
				for(int i = 0; i < entrada.size(); i++)
				{
					cout<< entrada[i];
					int isVowel = (entrada[i] == 'a' || entrada[i] == 'e' || entrada[i] == 'i' || entrada[i] == 'o' || entrada[i] == 'u' || 
						   	   entrada[i] == 'A' || entrada[i] == 'E' || entrada[i] == 'I' || entrada[i] == 'O' || entrada[i] == 'U');
					int isNextVowel = (entrada[i + 1] == 'a' || entrada[i + 1] == 'e' || entrada[i + 1] == 'i' || entrada[i + 1] == 'o' || entrada[i + 1] == 'u' || 
						           entrada[i + 1] == 'A' || entrada[i + 1] == 'E' || entrada[i + 1] == 'I' || entrada[i + 1] == 'O' || entrada[i + 1] == 'U');
					if(isVowel && !isNextVowel)
						cout<< "f" << entrada[i];
				}//for
				cout<<endl;
			}//while
			archivo.close();
		}//execute
};//class TheFaLanguaje

int main(){
	TheFaLanguaje obj;
	obj.execute();	
	return 0;
}//main
