#include <cstdlib>
#include <iostream>
#include <thread>
#include <utility>
#include <boost/asio.hpp>

#include "Customer.hpp"

using boost::asio::ip::tcp;

const int max_length = 1024;

void session(tcp::socket sock)
{
    try
    {
        for (;;)
        {
            char data[max_length];
            boost::system::error_code error;
            boost::asio::streambuf buf;

            // size_t length = sock.read_some(boost::asio::buffer(data), error);

             boost::asio::read(socket, buf,boost::asio::transfer_all(),  error);
            Customer customer;

            if (error && error != boost::asio::error::eof)
            {
                std::cout << "Read error: " << error.message() << "\n";
                return;
            }

            std::istream is(&buf);
            boost::archive::text_iarchive ia(is);
            ia >> customer;

            std::cout << customer << std::endl;
            // boost::asio::write(sock, boost::asio::buffer(data, length));
        }
        // for (;;)
        // {
        //     char data[max_length];

        //     boost::system::error_code error;
        //     size_t length = sock.read_some(boost::asio::buffer(data), error);
        //     std::cout << data << std::endl;
        //     if (error == boost::asio::error::eof)
        //         break; // Connection closed cleanly by peer.
        //     else if (error)
        //         throw boost::system::system_error(error); // Some other error.

        //     boost::asio::write(sock, boost::asio::buffer(data, length));
        // }
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception in thread: " << e.what() << "\n";
    }
}

void server(boost::asio::io_service &io_service, unsigned short port)
{
    tcp::acceptor a(io_service, tcp::endpoint(tcp::v4(), port));
    for (;;)
    {
        tcp::socket sock(io_service);
        a.accept(sock);
        std::thread(session, std::move(sock)).detach();
    }
}

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_service io_service;

        server(io_service, 1234);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
