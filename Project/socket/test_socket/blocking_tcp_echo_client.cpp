#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include "Customer.hpp"

using boost::asio::ip::tcp;

class counter_streambuf : public std::streambuf {
public:
    using std::streambuf::streambuf;

    size_t size() const { return m_size; }

protected:
    std::streamsize xsputn(const char_type* __s, std::streamsize __n) override 
    { this->m_size += __n; return __n; }

private:
    size_t m_size = 0;
};

enum
{
    max_length = 1024
};

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_service io_service;

        tcp::socket s(io_service);
        tcp::resolver resolver(io_service);
        boost::asio::connect(s, resolver.resolve({"127.0.0.1", "1234"}));

        std::cout << "Enter message: ";
        char request[max_length];
        std::cin.getline(request, max_length);
        size_t request_length = std::strlen(request);

        Customer customer(1001, "Tartempion1",
                       {10000, 10001});

        boost::asio::streambuf buf;

        // counter_streambuf buf;

        std::ostream os(&buf);
        // boost::archive::text_oarchive ar(os);
        boost::archive::binary_oarchive ar(os, boost::archive::no_header);
        ar << customer;

        std::cout << "The number of bytes taken for " << buf.size() << std::endl;

        boost::system::error_code error;
        boost::asio::write(s, buf);
        // boost::asio::write(s, boost::asio::buffer(buf, 10000));
        if (!error)
        {
            std::cout << "Client sent !" << std::endl;
        }
        else
        {
            std::cout << "Client sent failed: " << error.message() << std::endl;
        }

        // boost::asio::write(s, boost::asio::buffer(request, request_length));

        char reply[max_length];
        size_t reply_length = boost::asio::read(s,
                                                boost::asio::buffer(reply, request_length));
        std::cout << "Reply is: ";
        std::cout.write(reply, reply_length);
        std::cout << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
