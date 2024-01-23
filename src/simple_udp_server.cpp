#include <iostream>
#include <string>
#include <vector>

#include "boost/asio.hpp"
#include "boost/array.hpp"

using boost::asio::ip::udp;
std::string make_daytime_string()
{
    using namespace std; // For time_t, time and ctime;
    time_t now = time(0);
    return ctime(&now);
}

int main(int argc, char **argv)
{
    try
    {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 13));

        for (;;)
        {
            boost::array<char, 1> recv_buf;
            udp::endpoint remote_endpoint;
            size_t num_bytes;
            num_bytes = socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint);

            if (num_bytes != 0)
            {
                std::cout << "Received " << num_bytes << " bytes from "
                          << remote_endpoint.address().to_string() << ":" << remote_endpoint.port() << std::endl;
            }

            std::string message = make_daytime_string();

            boost::system::error_code ignored_error;
            socket.send_to(boost::asio::buffer(message),
                           remote_endpoint, 0, ignored_error);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}