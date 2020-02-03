#include <stdio.h>
#include <ctype.h>

#define OUT 0
#define IN 1
#define MAX_WORD_LENGTH 25

int main(int argc, const char* argv[]){
    int c, nc;
    nc = OUT;
    
    int words[MAX_WORD_LENGTH];
    for(int i = 0; i < MAX_WORD_LENGTH; i++)
        words[i] = 0;
        
    while((c = getchar()) != EOF){
        if(isalpha(c) || c == '-')
            ++nc;
        else if(c == '\'')
            ++nc;
        if(c == ' ' || c == '\n' || c == '\t'){
            ++words[nc];
            nc = 0;
        }
    }
    
    printf("Word Lengths\n");
    for(int i = 0; i < MAX_WORD_LENGTH; i++){
        printf("%d: ", i);
        for(int j = 0; j < words[i]; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
