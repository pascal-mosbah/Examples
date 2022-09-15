#include <string.h>

#include "copy_constructor.h"

//Warning memory allocation not checked

Very_simple_array init_Very_simple_array(size_t size){
	Very_simple_array array;
	array.size = size;
	array.tab = (int *) malloc(array.size * sizeof(int));
	return array;
}

Very_simple_array buggy_copy_Very_simple_array(const Very_simple_array *old_array){
        Very_simple_array array;
        array.size = old_array->size;
        array.tab = old_array->tab;
        return array;
}

Very_simple_array copy_Very_simple_array(const Very_simple_array *old_array){
        Very_simple_array array = init_Very_simple_array(old_array->size);
        memcpy(array.tab, old_array->tab, array.size * sizeof(int));
        return array;
}

void delete_Very_simple_array(Very_simple_array *array){
        free(array->tab);
}