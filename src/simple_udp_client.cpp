#include <iostream>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <bitset>

using boost::asio::ip::udp;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage client <host> <port>" << std::endl;
        return 1;
    }
    try
    {
        boost::asio::io_context io_context;
        udp::resolver resolver(io_context);
        udp::endpoint receiver_endpoint =
            *resolver.resolve(udp::v4(), argv[1], argv[2]).begin();

        udp::socket socket(io_context);
        socket.open(udp::v4());

        // boost::array<char, 1> send_buf = {{0}};
        boost::array<std::uint8_t, 132> send_buf = {{0}};
        std::string bin_str = "000000010000000001011110000000000000001000000010001110000000011010110100001110001011001110000001000000000000000000010011000010000000000001000101000000000000000001110000000100001010111000000000000000000000001100010001101110010100111100001010000011010000000101110001111000000000000000000010000000101010010110100010101001000111011000000000010111000001100011010000000000000000000000010111110000000000000000000000000001001100000000110100001001001010101101000000000000000000000000001000011000000010000001010100100000000100000000000000000000000000000000000000000000000000000000000000000000000000001111110001110000101000111101100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000001000101111101111100111100011111111101001011110001101011000111111110000000000000000000001010000000010101011100001010010000000000100101101000000010011001000001010000000010000000000001010000011010000000101110001101010011111111001110100011100010000000000000001000000010000000100000001000000010000000100000001000000000000000000000000001000000100";
        std::size_t byteLength = bin_str.length() / 8;
        for (std::size_t i = 0; i < byteLength; ++i)
        {
            std::string chunk = bin_str.substr(i * 8, 8);
            send_buf[i] = static_cast<std::uint8_t>(std::bitset<8>(chunk).to_ulong());
        }

        socket.send_to(boost::asio::buffer(send_buf), receiver_endpoint);
        std::cout << "Data send" << std::endl;
        // boost::array<char, 128> recv_buf;
        // udp::endpoint sender_endpoint;
        // size_t len = socket.receive_from(
        //     boost::asio::buffer(recv_buf), sender_endpoint);
        // std::cout << "data received" << std::endl;
        // std::cout.write(recv_buf.data(), len);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}