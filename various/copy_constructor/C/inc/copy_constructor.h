#pragma once
#include <stdlib.h>

typedef struct Very_simple_array {
	size_t size;
	int *tab;
} Very_simple_array;


Very_simple_array init_Very_simple_array(size_t size);

Very_simple_array buggy_copy_Very_simple_array(const Very_simple_array *old_array);

Very_simple_array copy_Very_simple_array(const Very_simple_array *old_array);

void delete_Very_simple_array(Very_simple_array *array);
