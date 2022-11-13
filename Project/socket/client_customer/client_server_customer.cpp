
#include <iostream>
#include <thread>
#include <chrono>

#include "Customer.hpp"

#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

using namespace std::chrono_literals;

void send_message(tcp::socket &socket, const std::string &message)
{
    const std::string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(message));
}

void read_message(tcp::socket &socket)
{
    // getting response from server

    boost::system::error_code error;
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

    if (error && error != boost::asio::error::eof)
    {
        std::cout << "receive failed: " << error.message() << std::endl;
    }
    else
    {
        const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
        std::cout << data << std::endl;
    }
}

void receive_data_through_socket(tcp::socket &socket, Customer &customer)
{
    boost::system::error_code error;
    boost::asio::streambuf buf;
    boost::asio::read(socket, buf, error);
    if (error && error != boost::asio::error::eof)
    {
        std::cout << "Read error: " << error.message() << "\n";
        return;
    }

    std::istream is(&buf);
    boost::archive::text_iarchive ia(is);
    ia >> customer;
}

void send_data_through_socket(tcp::socket &socket, Customer &customer)
{
    boost::asio::streambuf buf;
    std::ostream os(&buf);
    boost::archive::text_oarchive ar(os);
    ar << customer;
    boost::system::error_code error;
    boost::asio::write(socket, buf);
    if (!error)
    {
        std::cout << "Client sent !" << std::endl;
    }
    else
    {
        std::cout << "Client sent failed: " << error.message() << std::endl;
    }
}

void client_server_server()
{
    boost::asio::io_service io_service;
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));

    while (true)
    {
        Customer customer;
        // socket creation
        auto socket = tcp::socket(io_service);

        // waiting for connection
        acceptor.accept(socket);

        std::cout << "Passage server begin" << std::endl;

        receive_data_through_socket(socket, customer);
        std::cout << "Server received\n"
                  << customer << std::endl;

        std::this_thread::sleep_for(2s);

        // send_data_through_socket(*socket, customer);
        send_message(socket, "Test");
        std::cout << "Passage server end" << std::endl;
    }
}

void client_server_client(Customer &customer)
{

    std::this_thread::sleep_for(1s);

    boost::asio::io_service io_service;
    // socket creation
    tcp::socket socket(io_service);
    // connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

    send_data_through_socket(socket, customer);

        std::this_thread::sleep_for(200s);

    read_message(socket);

    // std::this_thread::sleep_for(3s);
    // receive_data_through_socket(socket, customer);
}

int main(int argc, char *argv[])
{
    Customer customer1(1001, "Tartempion1",
                       {10000, 10001});

    std::thread server(client_server_server);
    client_server_client(customer1);
    server.join();

    exit(EXIT_SUCCESS);
}
