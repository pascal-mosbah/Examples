#include <cstdlib>

#include "copy_constructor.hpp"

int main()
{
	Very_simple_array array(100, "init");

	auto array_new = Very_simple_array(array);
	auto array_new_buggy = Very_simple_array_buggy(array);

	return (EXIT_SUCCESS);
}
