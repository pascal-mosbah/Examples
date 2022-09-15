#include <cstdlib>

#include "copy_constructor.hpp"

int main()
{
	Very_simple_array array(100, "init");

	auto array_new = Very_simple_array(array);

	return (EXIT_SUCCESS);
}
