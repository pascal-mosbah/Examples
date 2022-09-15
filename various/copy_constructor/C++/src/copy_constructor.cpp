#include <string.h>
#include <algorithm>
#include <iostream>

#include "copy_constructor.hpp"

//Warning memory allocation not checked


Very_simple_array::Very_simple_array(const size_t &size, const std::string &name){
        this->size = size;
        this->name = name;
        this->tab  = new int[size];
}

Very_simple_array::~Very_simple_array(){
        std::cout<<"delete array "<<name<<std::endl;
        this->size = 0;
        delete [] this->tab;
}

Very_simple_array::Very_simple_array(const Very_simple_array &other){
        this->size = other.size;
        this->name = other.name + " Copied";
        // buggied tab = other.tab;
        tab = new int[size];
        std::copy(tab, tab+size, other.tab);
}
