#pragma once
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

template<typename _Data_type>
void receive_data_through_socket(tcp::socket &socket, _Data_type &data);

template<typename _Data_type>
void send_data_through_socket(tcp::socket &socket, _Data_type &data);