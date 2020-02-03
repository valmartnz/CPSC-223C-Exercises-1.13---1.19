#include <stdio.h>

#define MAXLINE 1000 // Max input line size

int gline(char line[], int maxline);
void copy(char to[], char from[]);

// Print longest input line
int main() {
	int len; // Current line length
	int max; // Maximum length seen so far
	char line[MAXLINE]; // Current input line
	char longest[MAXLINE]; // Longest line saved here
	
	max = 0;
	while ((len = gline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	
	if(max > 80) { 
		printf("Length: %i\nLine: %s\n", max, longest);
	} else {
		printf("There weren't any lines.\n");
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

// copy: copy `from` into `to`; assume `to` is big enough
void copy(char to[], char from[]) {
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
