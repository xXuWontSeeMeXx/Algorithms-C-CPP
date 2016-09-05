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
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char * toUpperCase(char entrada[512]){
    int i;
    for(i = 0; i < strlen(entrada); ++i)
        entrada[i] = toupper(entrada[i]);
    return entrada;
}//toUpperCase

char * cryptCadena(char cadena[], int size){
    const char KEYWORD[] = "MURCIELAGO";
    const char DIGITS[]  = "0123456789";        
    char *strBytes = malloc( sizeof(char) );
    sprintf(strBytes, "(BYTE %i)", size);
    int i;
    int j;
    for(i = 0; cadena[i] != '\0'; i++)
    {
        for(j = 0; j < strlen(KEYWORD); j++)
            if(cadena[i] == KEYWORD[j])
                cadena[i] = DIGITS[j];
    }//for
    sprintf(strBytes,"%s%s",strBytes,cadena);
    return strBytes;
}//cryptCadena

void execute(){
    FILE *archivo;
    archivo = fopen("archivo.txt", "rt");
    char entrada[512] = {0};
    char *input = NULL;
    char* palabra = NULL;
    while(fgets(entrada, 512, archivo) != NULL) 
    {
        input = toUpperCase(entrada);
        palabra = strtok(input, " \n\r\0");
        while(palabra != NULL)
        {
            palabra = cryptCadena(palabra, strlen(palabra));
            printf("%s", palabra);
            palabra = strtok(NULL, " \n\r\0");
        }
        printf("\n");               
    }//while 
    fclose(archivo);
    free(palabra); 
}//execute

int main(void){
    execute();
    return 0;
}//main
