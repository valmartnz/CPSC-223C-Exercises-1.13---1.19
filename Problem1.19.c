#include <stdio.h>

#define MAXLINE 1000 // Max input line size

int gline(char line[], int maxline);
void reverse(char line[]);

int main() {
	int len; // Current line length
	char line[MAXLINE]; // Current input line
	
	while ((len = gline(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
	}

	return 0;	
}

// getline: read a line into `s`, return length
int gline(char s[], int lim) {
	int c, i;
	
	for (i= 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim - 1) {
			s[i] = c;
		}
	}
	if (c == '\n') {
		if (i < lim - 1) {
			s[i] = c;
		}
		++i;
	}
	s[i] = '\0';
	return i;
}

// reverse a line
void reverse(char s[]) {
	int i, j;
	char temp;
	
	for(i = 0; s[i] != '\0'; i++)
	    ;
	
	i--; // take into account line without '\n'
	
	if(s[i] == '\n')
	    --i;
	    
	j = 0;
	
	while(j < i){
	    temp = s[j];
	    s[j] = s[i];
	    s[i] = temp;
	    --i;
	    ++j;
	}
}
