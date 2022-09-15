#include <stdio.h>

#include "copy_constructor.h"

int main()
{
	Very_simple_array array = init_Very_simple_array(100);

	Very_simple_array array_new = copy_Very_simple_array(&array);

	Very_simple_array array_new_buggy = buggy_copy_Very_simple_array(&array);


	printf("before array deleted\n");
	delete_Very_simple_array(&array);
	printf("after array deleted\n");

	printf("before array_new deleted\n");
	delete_Very_simple_array(&array_new);
	printf("after array_new deleted\n");

	printf("before array_new_buggy deleted\n");
	delete_Very_simple_array(&array_new_buggy);
	printf("after array_new_buggy deleted\n");

	return (EXIT_SUCCESS);
}
