#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <iostream>

#include "my_reading.hpp"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

void print(ptree const &pt)
{
    ptree::const_iterator end = pt.end();
    for (ptree::const_iterator it = pt.begin(); it != end; ++it)
    {
        std::cout << it->first << ": " << it->second.get_value<std::string>() << std::endl;
        print(it->second);
    }
}

int main(int argc, char **argv)
{

    ptree pt_write;


    ptree pt;
    
    read_json("../examples/test2.json", pt);

    ptree::const_iterator end = pt.end();
    for (ptree::const_iterator it = pt.begin(); it != end; ++it)
    {
        std::cout << it->first << ": " << it->second.get_value<std::string>() << std::endl;
    }

    write_json(std::cout, pt);

    return EXIT_SUCCESS;
}
