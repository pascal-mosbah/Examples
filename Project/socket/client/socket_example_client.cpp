#include <iostream>
#include <boost/asio.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "some_defines.hpp"

using namespace boost::asio;
using ip::tcp;


// Plane_wrapping add_plane()
// {
//      default_random_engine generator;
//      uniform_int_distribution<int> distribution(100, 800);
//      Plane_wrapping plane("AF" + to_string(distribution(generator)));
//      return plane;
// }

size_t send_data_through_socket(tcp::socket &socket, Plane_wrapping &plane)
{
     boost::asio::streambuf buf;
     std::ostream os(&buf);
     boost::archive::text_oarchive ar(os);
     ar &plane;
     const size_t header = buf.size();
      std::vector<boost::asio::const_buffer> buffers;
     buffers.push_back(boost::asio::buffer(&header, sizeof(header)));
     buffers.push_back(buf.data());
     return boost::asio::write(socket, buffers);
}

int main(int argc, char *argv[])
{
     Plane_wrapping plane;

     if (argc > 1)
     {
          // if (argv[1] != "0")
          // {
               plane = Plane_wrapping(argv[1]);
          // }
     } else {
          cout<<"Name of the fligth must be sepcified"<<endl;
          return EXIT_FAILURE;
     }
     // else
     // {
     //      plane = add_plane();
     // }

     boost::asio::io_service io_service;
     // socket creation
     tcp::socket socket(io_service);
     // connection
     socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));

     if (send_data_through_socket(socket, plane))
     {
          cout << "Client sent " << plane.identification_ << endl;
     }
     else
     {
          cout << "send failed: " << endl;
     }


     // getting response from server

     boost::system::error_code error;
     boost::asio::streambuf receive_buffer;
     boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);

     if (error && error != boost::asio::error::eof)
     {
          cout << "receive failed: " << error.message() << endl;
     }
     else
     {
          const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
          cout << data << endl;
     }

     return 0;
}
