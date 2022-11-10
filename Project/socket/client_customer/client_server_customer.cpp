
#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include "Customer.hpp"

using namespace boost::asio;
using ip::tcp;

void receive_data_through_socket(tcp::socket &socket, Customer &customer)
{
    // size_t header;
    // boost::asio::read(
    //     socket,
    //     boost::asio::buffer(&header, sizeof(header)));
    // // read body
    // boost::asio::streambuf buf;
    // const size_t rc = boost::asio::read(
    //     socket,
    //     buf.prepare(header));

    // buf.commit(header);
    // // deserialize
    // std::istream is(&buf);
    // boost::archive::binary_iarchive ar(is);
    // ar >> customer;

     boost::system::error_code ec;
     boost::asio::streambuf buf;
     asio::read(socket, buf, ec);
    if (ec && ec != asio::error::eof) {
        std::cout << "Read error: " << ec.message() << "\n";
        return 1;
    }

    Test response; // uninitialized
    {
        std::istream is(&buf);
        boost::archive::binary_iarchive ia(is);

        ia >> response;
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
        auto socket = std::make_unique<tcp::socket>(io_service);

        // waiting for connection
        acceptor.accept(*socket);

        receive_data_through_socket(*socket, customer);
        std::cout << "Server received\n"
                  << customer << std::endl;
    }
}

size_t send_data_through_socket(tcp::socket &socket, Customer &customer)
{
    boost::asio::streambuf buf;
    std::ostream os(&buf);
    boost::archive::binary_oarchive ar(os);
    ar << customer;
    std::cout << customer;

    const size_t header = buf.size();
    std::vector<boost::asio::const_buffer> buffers;
    buffers.push_back(boost::asio::buffer(&header, sizeof(header)));
    buffers.push_back(buf.data());
    return boost::asio::write(socket, buffers);
}

void client_server_client(Customer &customer)
{
    boost::asio::io_service io_service;
    // socket creation
    tcp::socket socket(io_service);
    // connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

    boost::asio::streambuf buf;
    std::ostream os(&buf);
    boost::archive::binary_oarchive ar(os);
    ar << customer;

    boost::asio::write(socket, buf);

    // if (send_data_through_socket(socket, customer))
    // {
    //     std::cout << "Customer sent " << std::endl;
    // }
    // else
    // {
    //     std::cout << "send failed: " << std::endl;
    // }

    // // getting response from server

    // boost::system::error_code error;
    // boost::asio::streambuf receive_buffer;
    // boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

    // if (error && error != boost::asio::error::eof)
    // {
    //     std::cout << "receive failed: " << error.message() << std::endl;
    // }
    // else
    // {
    //     const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
    //     std::cout << data << std::endl;
    // }
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
