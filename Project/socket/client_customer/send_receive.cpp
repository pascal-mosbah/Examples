#include "send_receive.hpp"
#include "Customer.hpp"

template<typename _Data_type>
void receive_data_through_socket(tcp::socket &socket, _Data_type &data)
{
    boost::system::error_code error;
    boost::asio::streambuf buf;
    boost::asio::read(socket, buf,boost::asio::transfer_all(),  error);
    if (error && error != boost::asio::error::eof)
    {
        std::cout << "Read error: " << error.message() << "\n";
        return;
    }

    std::istream is(&buf);
    boost::archive::text_iarchive ia(is);
    ia >> data;
}

template<typename _Data_type>
void send_data_through_socket(tcp::socket &socket, _Data_type &data)
{
    boost::asio::streambuf buf;
    std::ostream os(&buf);
    boost::archive::text_oarchive ar(os);
    ar << data;
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

template
void receive_data_through_socket(tcp::socket &socket, Customer &customer);

template
void send_data_through_socket(tcp::socket &socket, Customer &customer);