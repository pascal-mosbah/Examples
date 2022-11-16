
#include <iostream>
#include <thread>
#include <chrono>

#include "Customer.hpp"
#include "send_receive.hpp"

#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

using namespace std::chrono_literals;

auto client_server_client(Customer &customer)
{

    boost::asio::io_service io_service;
    // socket creation
    // tcp::socket socket(io_service);
    auto socket = std::make_unique<tcp::socket>(io_service);
    // connection
    socket->connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

    send_data_through_socket(*socket, customer);

    //  // getting response from server

    // boost::system::error_code error;
    // boost::asio::streambuf receive_buffer;
    // boost::asio::read(*socket, receive_buffer, boost::asio::transfer_all(), error);

    // if (error && error != boost::asio::error::eof)
    // {
    //     std::cout << "receive failed: " << error.message() << std::endl;
    // }
    // else
    // {
    //     const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
    //     std::cout << data << std::endl;
    // }
    return socket;
}

// receive_data_through_socket(socket, customer);

int main(int argc, char *argv[])
{
    Customer customer1(1001, "Tartempion1",
                       {10000, 10001});

    auto socket = client_server_client(customer1);
    std::cout << "Passage client begin" << std::endl;
    receive_data_through_socket(*socket, customer1);
    std::cout << "Passage client end" << std::endl;

    exit(EXIT_SUCCESS);
}
