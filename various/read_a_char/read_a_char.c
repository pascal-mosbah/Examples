#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> // for isalnum

char read_a_char(){
	printf("Read a char\n");
	char c = '\0';
	size_t ret = scanf("%c",&c);
	if (ret && isalnum(c)){
		printf("Char read\n");
		return c;
	}
	printf("No char read\n");
	return c;
}

char read_a_char_modified(){
        char c = read_a_char();
	char test = getchar();
        while(test != '\n' && test != EOF) test = getchar();
	return c;
}



int main(){

	char c = read_a_char();
	printf("%c\n",c);
	c = read_a_char();
	printf("%c\n",c);
	c = read_a_char_modified();
	printf("%c\n",c);
	c = read_a_char_modified();
	printf("%c\n",c);
	return EXIT_SUCCESS;
}
