#include <stdio.h>
#include <cs50.h>

int mario_tower(int num);

int main(void){
    int i =0;

    do
    {
        i = get_int("Height: ");
    }
    while (i <= 0 || i > 8);

    mario_tower(i);
}

int mario_tower(int num){
    char hashtag = '#';
    char space = ' ';
    char dot = '.';

    for (int i = 0; i < num; i++){

        // space maker
        for (int k = num-i-1; k > 0; k--){
                printf("%c", space);
        }

        // left hash maker
        for (int j = 0; j < (i+1); j++){

            printf("%c", hashtag);
        }

        // two spaces inbetween
        printf("%c", space);
        printf("%c", space);

        // right hash maker
        for (int l = 0; l < (i+1); l++){
            printf("%c", hashtag);
        }

        // move to next line
        printf("\n");
    }

    return 0;
}