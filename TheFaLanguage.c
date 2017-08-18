/*
Your parents developed an incredible ability to talk in a way so as to avoid your little brother
from understanding adult conversations. They named it the Fa language. After listening for a
while, you realized that what they do is to add an ‘f’ after each vowel, followed by the same
vowel.
The only exception to the rule is when a word contains diphthongs. Diphthongs are not separated
and the vowel used to create the ‘fa’ sound is the second vowel in the diphthongs. The possible
diphthongs are:

AI
AU
EI
EU
OI
UI
IE
IO
UA
UE
UO
IU

Your job is to create a program that will help you translate words into the Fa language.

Input
A line containing one number n, 1 ≤ n ≤ 100, that indicates the number of sentences to process.
Each of the following n lines contains a sentence which length is at least one character and is less
than 100 characters.

Output
The n sentences translated into Fa, one sentence per line.The output is case sensitive. If a letter is
in upper case, the same letter must be upper case. When adding a vowel in the f + vowel formula,
the case of the vowel must be respected. Each ‘f’ added in the translation must be in lower case.

Sample Input
3
Hola mi nOmbre es RicArdo
Esta Es Una frase A evaluar
Gracias por la ayuda

Sample Output
Hofolafa mifi nOfOmbrefe efes RificAfArdofo
EfEstafa EfEs UfUnafa frafasefe AfA efevafaluafar
Grafaciafas pofor lafa afayufudafa
*/

#include<stdio.h>
#include<string.h>

int main(){
	FILE * pFile;
	char entrada[512];
	char vowels[] = "aeiouAEIOU";
  	pFile = fopen ("archivo.txt", "r");
	if(pFile != NULL)
	{
    	while(fgets(entrada, 100, pFile) != NULL)
	   	{
			int i;
			char * pch;
			int arreglo[50];
			for(i = 0; i < strlen(entrada); i++)
			{
				printf("%c", entrada[i]);				
				int isVowel = (entrada[i] == 'a' || entrada[i] == 'e' || entrada[i] == 'i' || entrada[i] == 'o' || entrada[i] == 'u' || 
						   	   entrada[i] == 'A' || entrada[i] == 'E' || entrada[i] == 'I' || entrada[i] == 'O' || entrada[i] == 'U');
				int isNextVowel = (entrada[i + 1] == 'a' || entrada[i + 1] == 'e' || entrada[i + 1] == 'i' || entrada[i + 1] == 'o' || entrada[i + 1] == 'u' || 
						           entrada[i + 1] == 'A' || entrada[i + 1] == 'E' || entrada[i + 1] == 'I' || entrada[i + 1] == 'O' || entrada[i + 1] == 'U');
				if(isVowel && !isNextVowel)
					printf("%c%c", 'f', entrada[i]);
			}//for
		}//while
	    fclose(pFile);
	}//if
	else
		perror("Error opening file");
	return 0;
}//main
