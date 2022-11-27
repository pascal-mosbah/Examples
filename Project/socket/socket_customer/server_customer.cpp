//
// blocking_tcp_echo_server.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2008 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <boost/bind/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "Customer.hpp"
#include "socket_tools.hpp"

//Taken from "https://www.boost.org/doc/libs/1_80_0/doc/html/boost_asio/example/cpp11/echo/blocking_tcp_echo_server.cpp" with modifications

using boost::asio::ip::tcp;

const int max_length = 1024;

typedef boost::shared_ptr<tcp::socket> socket_ptr;

void session(socket_ptr sock)
{
    try
    {
        for (;;)
        {
            char data[max_size_data] = {};

            boost::system::error_code error;
            size_t length = sock->read_some(boost::asio::buffer(data), error);

            if (error == boost::asio::error::eof)
                break; // Connection closed cleanly by peer.
            else if (error)
                throw boost::system::system_error(error); // Some other error.

            Customer customer = get_data_from_string<Customer>(data);
            std::cout << "Customer received :" << std::endl
                      << customer << std::endl;

            Customer customer_back(1002, "Tartempion2",
                              {10002, 10003});

            std::cout << "Customer sent :" << std::endl
                      << customer_back << std::endl;
                      
            auto line = get_string_from_data(customer_back);

            boost::asio::write(*sock, boost::asio::buffer(line.c_str(), line.size()));
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void server(boost::asio::io_service &io_service, short port)
{
    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), port));
    for (;;)
    {
        socket_ptr sock(new tcp::socket(io_service));
        a.accept(*sock);
        boost::thread t(boost::bind(session, sock));
    }
}

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_service io_service;

        using namespace std; // For atoi.
        server(io_service, 1234);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
