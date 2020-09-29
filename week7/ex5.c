#include <stdio.h>
int main() {
	char **s;
	char foo[] = "Hello World";
	s = (char**)malloc(sizeof(char*));
	*s = foo;
	printf("s is %s\n",*s);//pointed value of s
	s[0] = foo;
	printf("s[0] is %s\n",s[0]);//same as *s
	return(0);
}
