#include <stdio.h>

#define MAXLINE 1000 // Max input line size

int gline(char line[], int maxline);
int removeBlanks(char line[]);

// Remove Blanks from line
int main() {
	int len; // Current line length
	char line[MAXLINE]; // Current input line
	
	while ((len = gline(line, MAXLINE)) > 0) {
		if (removeBlanks(line) > 0) {
			printf("%s", line);
		}
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

// removes blanks, taps, and blank lines
int removeBlanks(char s[]) {
	int i;
	
	for(i = 0; s[i] != '\n'; i++)
	    ;
	
	i--; // take into account line without '\n'
	
	for(i > 0; ((s[i] == ' ') || (s[i] == '\t')); --i)
	    ;
	  
	if(i > 0){
	    ++i;
	    s[i] = '\n';
	    ++i;
	    s[i] = '\0';
	}
	return i;
}
