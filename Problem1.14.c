#include <stdio.h>

#define MAX_CHAR_LENGTH 128

int main(int argc, const char* argv[]){
    int c;
    
    int chars[MAX_CHAR_LENGTH];
    for(int i = 0; i < MAX_CHAR_LENGTH; i++)
        chars[i] = 0;
        
    while((c = getchar()) != EOF)
        ++chars[c];
    
    printf("Character Frequencies\n");
    for(int i = 0; i < MAX_CHAR_LENGTH; i++){
        putchar(i);
        
        for(int j = 0; j < chars[i]; j++){
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
