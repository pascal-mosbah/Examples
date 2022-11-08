#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <boost/asio.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;
using std::unique;
using std::unique_ptr;
using std::vector;

#include "some_defines.hpp"

constexpr auto buffer_size = sizeof(Plane);

void receive_data_through_socket(tcp::socket &socket, Plane_wrapping &plane)
{
      size_t header;
      boost::asio::read(
          socket,
          boost::asio::buffer(&header, sizeof(header)));
      // read body
      boost::asio::streambuf buf;
      const size_t rc = boost::asio::read(
          socket,
          buf.prepare(header));

      buf.commit(header);
      // deserialize
      std::istream is(&buf);
      boost::archive::text_iarchive ar(is);
      ar & plane;
}

void send(tcp::socket &socket, const string &message)
{
      const string msg = message + "\n";
      boost::asio::write(socket, boost::asio::buffer(message));
}

struct Connected_plane
{
      Connected_plane(std::unique_ptr<tcp::socket> &socket, const Plane_wrapping &plane) : socket_(std::move(socket)), plane_(plane) {}
      unique_ptr<tcp::socket> socket_;
      Plane_wrapping plane_;
};

int main()
{
      boost::asio::io_service io_service;

      vector<Connected_plane> connected_planes;

      // listen for new connection
      tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));

      while (true)
      {
            Plane_wrapping plane;
            // socket creation
            auto socket = std::make_unique<tcp::socket>(io_service);

            // waiting for connection
            acceptor.accept(*socket);

            receive_data_through_socket(*socket, plane);
            if (plane.identification_ == "0")
            {
                  cout << "Server received ending command" << endl;
                  break;
            }
            cout << "Server received " << plane.identification_ << endl;

            connected_planes.emplace_back(socket, plane);
      }

      for (auto &connected_plane : connected_planes)
      {
            cout <<  "To client, " + connected_plane.plane_.identification_ + ", it's time to stop!"<<endl;
            string msg = "From Server, " + connected_plane.plane_.identification_ + " it's time to stop!";
            send(*(connected_plane.socket_), msg);
      }
      return 0;
}
