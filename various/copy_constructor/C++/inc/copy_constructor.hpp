#pragma once
#include <string>
class Very_simple_array {
	private:
	size_t size;
	int *tab;
	std::string name;

	public:
	Very_simple_array(const size_t &size, const std::string &name);
	Very_simple_array(const Very_simple_array &other);
	~Very_simple_array();
};
