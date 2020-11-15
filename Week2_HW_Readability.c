#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <math.h>

int colemanLiau(double S, double L);

int main()
{
    // get string input from user
    string text = get_string("Text: ");

    // count the number of  letters
    int letters = 0;
    int words = 1;
    int sentences = 0;


    for (int i = 0; i < strlen(text); i++){

        // count the number of letters
        if (('A' <= text[i] && text[i] <= 'Z') || ('a' <= text[i] && text[i] <= 'z')){
            letters++;
        }

        // split the string into words
        if (text[i] == ' '){
            words++;
        }

        // split the string into sentences; need to count number of occurrences of ., ?, !
        if (text[i] == '.' || text[i] == '?' || text[i] == '!'){
            sentences++;
        }
    }

    printf("There are %i letters\n", letters);
    printf("There are %i words\n", words);
    printf("There are %i sentences\n", sentences);

    // calculate per 100 averages to get L and S

    float L = ((float) letters/ (float) words)*100.0;
    float S = ((float) sentences/(float) words)*100.0;

    printf("L: %f \n", L);
    printf("S: %f \n", S);


    // implement Coleman-Liau Index
    int reading_index = colemanLiau(L, S);

    if (reading_index >= 1 && reading_index <= 16){
        printf("Grade %i\n", reading_index);
    } else if (reading_index < 1){
        printf("Before Grade 1\n");
    } else if (reading_index > 16){
        printf("Grade 16+\n");
    }

    return 0;
}

int colemanLiau(double L, double S){
    // calculates the reading grade level is based on L and S
    // L is the average number of letters per 100 words in the text
    // S is the number of sentence per 100 words in the text

    return round(0.0588*L - 0.296*S - 15.8);
}