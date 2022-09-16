#include <stdio.h>

#include "copy_constructor.h"

int main()
{
	Very_simple_array array = init_Very_simple_array(100,"array_init");

	Very_simple_array array_new = copy_Very_simple_array(&array);

	Very_simple_array array_new_buggy = buggy_copy_Very_simple_array(&array);


	delete_Very_simple_array(&array);
	delete_Very_simple_array(&array_new);
	delete_Very_simple_array(&array_new_buggy);

	return (EXIT_SUCCESS);
}
