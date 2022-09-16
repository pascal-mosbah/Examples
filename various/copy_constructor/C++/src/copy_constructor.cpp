#include <string.h>
#include <algorithm>
#include <iostream>

#include "copy_constructor.hpp"

// Warning memory allocation not checked

Very_simple_array::Very_simple_array(const size_t &size, const std::string &name)
{
        this->size = size;
        this->name = name;
        this->tab = new int[size];
}

Very_simple_array::~Very_simple_array()
{
        std::cout << "delete " << name << std::endl;
        this->size = 0;
        delete[] this->tab;
        std::cout << "deleted " << name << std::endl;
}

Very_simple_array::Very_simple_array(const Very_simple_array &other)
{
        this->size = other.size;
        this->name = other.name + "_copy";
        // buggy see below : this->tab = other.tab;
        tab = new int[size];
        std::copy(tab, tab + size, other.tab); // C++ copy
}

size_t Very_simple_array::get_size() const {
        return size;
}


const std::string &Very_simple_array::get_name() const { 
        return name;
}

int *Very_simple_array::get_relaxed_tab() const { // Not to do for purpose only !
        return tab;
}

Very_simple_array::Very_simple_array(){ // Not to do for purpose only !
        this->size = 0;
        this->tab = nullptr;
}

Very_simple_array_buggy::Very_simple_array_buggy(const size_t &size, const std::string &name) : Very_simple_array(size, name) {}

Very_simple_array_buggy::Very_simple_array_buggy(Very_simple_array &other) // Not to do for purpose only !
{
        this->name = other.get_name() + "_copy_buggy";
        this->size = other.get_size();
        this->tab  = other.get_relaxed_tab(); // Not to do for purpose only !
}