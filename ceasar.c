#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void Ceasar(string str, int key);

int main(int argc, string argv[]){
	if (argc != 2){
		printf("Print the key next time! \n");
		return 1;
	}

	int key = atoi(argv[1]);
	if (key <= 0){
		return 1;
	}

	key %= 26;
	printf("Input your string: \n");
	string str;
	fgets(str, 1000, stdin);
	Ceasar(str, key);
	return 0;
}


void Ceasar(string str, int key){
	int n = strlen(str);
	char encryptedStr[n];
	for (int i; i < n-1; i++){
		if (isalpha(str[i])){
			if (isupper(str[i])){
				int next_char = str[i] + key;
				if (next_char <= 90){
					encryptedStr[i] = (char)next_char;
				}
				else{
					encryptedStr[i] = (char)(next_char - 26);
				}
			}
			else if (islower(str[i])){
				int next_char = str[i] + key;
				if (next_char <= 122){
					encryptedStr[i] = (char)next_char;
				}
				else{
					encryptedStr[i] = (char)(next_char - 26);
				}
			}
		}
		else{
			encryptedStr[i] = str[i];
		}
	}
	encryptedStr[n-1] = '\0';
	printf("Encrypted: %s \n", encryptedStr);
}
