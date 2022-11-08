#pragma once
#include <string>
class Very_simple_array
{
protected:
	size_t size;
	int *tab;
	std::string name;

public:
	Very_simple_array(const size_t &size, const std::string &name);
	Very_simple_array(const Very_simple_array &other);
	size_t get_size() const;
	const std::string &get_name() const;
	int *get_relaxed_tab() const; // Not to do for purpose only !
	Very_simple_array();		  
	~Very_simple_array();
};

class Very_simple_array_buggy : public Very_simple_array // Not to do for purpose only !
{ 

public:
	Very_simple_array_buggy(const size_t &size, const std::string &name);
	Very_simple_array_buggy(Very_simple_array &other); // Not to do for purpose only !
};
