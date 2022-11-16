
#include <iostream>
#include <thread>
#include <chrono>

#include "Customer.hpp"
#include "send_receive.hpp"

#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

using namespace std::chrono_literals;

auto client_server_server()
{
    boost::asio::io_service io_service;
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));

    // auto socket = tcp::socket(io_service);

    // // waiting for connection
    // acceptor.accept(socket);

    std::cout << "Passage server begin" << std::endl;

    // while (true)
    // {
        Customer customer;
        // socket creation
        auto socket = std::make_unique<tcp::socket>(io_service);

        // waiting for connection
        acceptor.accept(*socket);

        receive_data_through_socket(*socket, customer);
        std::cout << "Server received\n"
                  << customer << std::endl;

  
    // }
    std::cout << "Passage server end" << std::endl;
    std::this_thread::sleep_for(2s);
    return socket;
}

int main(int argc, char *argv[])
{
    Customer customer1(1001, "Tartempion1",
                       {10000, 10001});

    // boost::asio::io_context io;
    // boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
    //   std::cout << "Hello, world!" << std::endl;
    // std::thread server(client_server_server);
    auto socket = client_server_server();
    // std::this_thread::sleep_for(2s);
      send_data_through_socket(*socket, customer1);
    // server.join();

    exit(EXIT_SUCCESS);
}
