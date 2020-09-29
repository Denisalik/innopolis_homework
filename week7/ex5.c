#include <stdio.h>
int main() {
	char **s;
	char foo[] = "Hello World";
	s = (char**)malloc(sizeof(char*));
	*s = foo;
	printf("s is %p\n",s);//pointer of s
	s[0] = foo;
	printf("s[0] is %s\n",s[0]);//pointed value of s
	return(0);
}
