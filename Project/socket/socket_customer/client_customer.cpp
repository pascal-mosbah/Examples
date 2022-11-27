#include <cstdlib>
#include <cstring>
#include <iostream>

#include "Customer.hpp"
#include "socket_tools.hpp"

//Taken from "https://www.boost.org/doc/libs/1_80_0/doc/html/boost_asio/example/cpp11/echo/blocking_tcp_echo_client.cpp" with modifications

using boost::asio::ip::tcp;

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_service io_service;

        tcp::socket s(io_service);
        tcp::resolver resolver(io_service);
        boost::asio::connect(s, resolver.resolve({"127.0.0.1", "1234"}));

        Customer customer(1001, "Tartempion1",
                          {10000, 10001});

        auto line = get_string_from_data(customer);

        std::cout << "Customer sent :" << std::endl
                  << customer << std::endl;

        boost::asio::write(s, boost::asio::buffer(line.c_str(), line.size()));

        char reply[max_size_data];
        boost::system::error_code error;
        size_t length = s.read_some(boost::asio::buffer(reply), error);

        Customer customer_back = get_data_from_string<Customer>(reply);

         std::cout << "Customer received :" << std::endl
                  << customer_back << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
