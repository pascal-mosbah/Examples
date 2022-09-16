#include <string.h>
#include <stdio.h>

#include "copy_constructor.h"

// Warning memory allocation not checked

Very_simple_array init_Very_simple_array(size_t size, const char *name)
{
        Very_simple_array array;
        array.size = size;
        array.tab = (int *)malloc(array.size * sizeof(int));
        array.name = strdup(name);
        return array;
}

Very_simple_array buggy_copy_Very_simple_array(const Very_simple_array *old_array)
{
        const char add_suffix[] = "_copy_bugged";
        Very_simple_array array;
        array.size = old_array->size;
        array.tab = old_array->tab;
        array.name = strdup(old_array->name);
        array.name = (char *)realloc(array.name, (strlen(array.name) + strlen(add_suffix) + 1) * sizeof(char));
        strcat(array.name, add_suffix);
        return array;
}

Very_simple_array copy_Very_simple_array(const Very_simple_array *old_array)
{
        const char add_suffix[] = "_copy";
        Very_simple_array array = init_Very_simple_array(old_array->size, old_array->name);
        array.name = (char *)realloc(array.name, (strlen(array.name) + strlen(add_suffix) + 1) * sizeof(char));
        strcat(array.name, add_suffix);
        return array;
}

void delete_Very_simple_array(Very_simple_array *array)
{
        printf("Delete %s\n", array->name);
        fflush(stdout);
        free(array->tab);
        printf("Deleted %s\n", array->name);
        free(array->name);
}