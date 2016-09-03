/*
 *    Bruce Wayne is known as BATMAN and a nocturnal peculiar mammal represents him; the word of that
 *    animal in Spanish consists of 5 consonants and the 5 vowels, from which none of them is repeated. This
 *    word must create an encryption code to transfer text files. These are the following rules:
 *    
 *    0
 *    1
 *    2
 *    3
 *    4
 *    5
 *    6
 *    7
 *    8
 *    9
 *
 *    Each letter of the mysterious word (animal’s name in Spanish) will become a number (0 to 9) and at the
 *    beginning of each word placed in the file should precede the indicator of the length of each word in byte
 *    format. The program must take a text file (WITH WORDS ONLY, NOT NUMBERS) as input and generate
 *    an output file.
 *
 *    The following example is shown for better comprehension:
 *
 *    Input
 *
 *        File name: TEXT.txt containing the following text:
 *
 *        HOLA
 *        QUIERO CONTARTE UN SECRETO
 *
 *    Output
 *
 *        File name: TEXT.crp (Encrypted)
 *
 *        (BYTE 4)H967
 *        (BYTE 6)Q14529(BYTE 8)39NT72T5(BYTE 2)1N(BYTE 7)S5325T0
 */

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

class Batcode{
    public:
        void execute(){
            ifstream archivo("archivo.txt", ios::in);
            while(getline(archivo, entrada) != NULL)
            {
                entrada = toUpperCase(entrada);
                entrada += " ";
                string cadena = "";
                for(int i = 0; i < entrada.size(); ++i)
                {
		    if(entrada[i] == ' ')
                    {
		        string crypt = cryptCadena(cadena);
                        cout<<crypt;
                        cadena = "";
                    }//if
                    else
                        cadena += entrada[i];
                }//for
                cout<<endl;
            }//while
        }//execute

        string cryptCadena(string cadena){
            const string KEYWORD = "MURCIELAGO";
            const string DIGITS  = "0123456789";
            string strByte = string("(BYTE ") + to_string(cadena.size()) + string(")");
            for(int i = 0; i < cadena.size(); ++i)
            {
                for(int j = 0; j < KEYWORD.size(); ++j)
                    if(cadena[i] == KEYWORD[j])
                        cadena[i] = DIGITS[j];
            }//for
            strByte += cadena;
            return strByte;
        }//cryptCadena

        string toUpperCase(string cadena){
	    for(int i = 0; i < cadena.size(); ++i)
                cadena[i] = toupper(cadena[i]);
            return cadena;
        }//toUpperCase
    private:
        string entrada;
};//class Batcode

int main(){
    Batcode obj;
    obj.execute();
    return 0;
}//main
