#include <cstdlib>
#include <cstring>
#include <iostream>

#include "socket_tools.hpp"

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#include "Customer.hpp"

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
        // Customer customer;
        boost::asio::streambuf buf;
        std::ostream os(&buf);
        boost::archive::text_oarchive ar(os);
        ar << customer;

        std::cout << "The number of bytes taken for " << buf.size() << std::endl;
        auto data = to_string(buf);

               std::cout << "Data : " << data.c_str() <<" "<< strlen(data.c_str())<< std::endl;

        std::cout << customer << std::endl;
        boost::asio::write(s, boost::asio::buffer(to_string(buf).c_str(), buf.size()));




        char reply[max_length];
        boost::system::error_code error;
        // size_t reply_length = boost::asio::read(s,
        //                                         boost::asio::buffer(reply, buf1.size()));
        size_t length = s.read_some(boost::asio::buffer(reply), error);
        std::cout << "Data : " << reply <<" "<< strlen(reply)<< std::endl;
        // std::cout << "Reply is: ";
        // std::cout.write(reply, reply_length);
        // std::cout << "\n";
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
