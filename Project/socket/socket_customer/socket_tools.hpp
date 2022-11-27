#pragma once
#include <string>

#include <boost/asio.hpp>

constexpr size_t max_size_data = 1<<16;

std::string to_string(boost::asio::streambuf &buffer);

template <typename _Data_type>
_Data_type get_data_from_string(const char *s);

template <typename _Data_type>
std::string get_string_from_data(const _Data_type &data);