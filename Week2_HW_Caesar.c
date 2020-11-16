#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int cipherText(char letter, string shift);

// argv is argument vector
// argc is argument count

int main(int argc, string argv[]){

    // warn user that we need command-line argument
    if (argc != 2){
        printf("Failure, please input a number\n");
        return 1;
    }

    // if any of the characters of the command-line argument is not a decimal digit...
    for (int i = 0; i < strlen(argv[1]); i++){
        if isalpha(argv[1][i]){
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //printf("%s\n", argv[1]);

    // get the text from the user
    string plaintext = get_string("plaintext: ");
    char new_text[strlen(plaintext)-1];

    // cipher text
    for (int i = 0; i < strlen(plaintext); i++){
        new_text[i] = cipherText(plaintext[i], argv[1]);
    }

    printf("ciphertext: %s\n", new_text);
    //printf("%lu characters long", strlen(new_text));

    return 0;
}

int cipherText(char letter, string shift){
    int shifted = letter+ atoi(shift);

    if isalpha(letter){
        // converting string argv[1] to an int using atoi, found in stdlib.h
        // printf("You want to shift %c by %i positions\n", letter, atoi(shift));

        // printf("The letter %c is %i in ascii\n", letter, letter);

        // lowercase
        if ((97 <= letter) && (letter <= 122)){
            // printf("New letter is %c which has an ascii value of %i\n", shifted, shifted);
            // int new_letter = 97+ ((letter + atoi(shift))%26);
            // printf("do you see me and this %c and %i\n", new_letter, new_letter);

            if (letter + atoi(shift) > 122){
                //printf("%c, ascii %i\n", 97 + ((shifted-97)%26), 97 + ((shifted-97)%26));
                return 97 + ((shifted-97)%26);
            } else {
                // printf("%c, ascii %i\n", shifted, shifted);
                return shifted;
            }

        }

        // uppercase
        if ((65 <= letter) && (letter <= 90)){
            // printf("New letter is %c which has an ascii value of %i\n", shifted, shifted);
            if (letter + atoi(shift) > 90){
                //printf("%c, ascii %i\n", 65 + ((shifted-65)%26), 65 + ((shifted-65)%26));
                return 65 + ((shifted-65)%26);
            } else {
                // printf("%c, ascii %i\n", shifted, shifted);
                return shifted;
            }
        }
    } else {
        return letter;
    }
    return 0;
}