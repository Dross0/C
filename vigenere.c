#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

void PrintEnctyptVigenere(string str, string keyword);
void PrintDectyptVigenere(string str, string keyword);

int main(int argc, string argv[]){
        if (argc != 2){
            printf("Enter the keyword!\n");
            return 1;
        }
        string keyword = argv[1];
        printf("String: ");
        string str;
        fgets(str, 1000, stdin);
        PrintEnctyptVigenere(str, keyword);
        PrintDectyptVigenere(str, keyword);
        return 0;
}


void PrintEnctyptVigenere(string str, string keyword){
    int strLen = strlen(str);
    int keywordLen = strlen(keyword);
    char encryptedStr[strLen];
    int j = 0;
    for (int i = 0; i < strLen-1; i++){
        if (isalpha(str[i])){
            int index = j % keywordLen;
            j++;
            int key = keyword[index] - 97;
            if (islower(str[i])){
                encryptedStr[i] = (str[i] - 97 + key) % 26 + 97;
            }
            else{
                encryptedStr[i] = (str[i] - 65 + key) % 26 + 65;
            }
        }
        else{
            encryptedStr[i] = str[i];
        }
    }
    encryptedStr[strLen-1] = '\0';
    printf("Encrypted: %s\n", encryptedStr);
}


void PrintDectyptVigenere(string str, string keyword){
    int strLen = strlen(str);
    int keywordLen = strlen(keyword);
    char decryptedStr[strLen];
    int j = 0;
    for (int i = 0; i < strLen-1; i++){
        if (isalpha(str[i])){
            int index = j % keywordLen;
            j++;
            int key = keyword[index] - 97;
            if (islower(str[i])){
                decryptedStr[i] = (str[i] - 97 - key + 26) % 26 + 97;
            }
            else{
                decryptedStr[i] = (str[i] - 65 - key + 26) % 26 + 65;
            }
        }
        else{
            decryptedStr[i] = str[i];
        }
    }
    decryptedStr[strLen-1] = '\0';
    printf("Decrypted: %s\n", decryptedStr);
}
