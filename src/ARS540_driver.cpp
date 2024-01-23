#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <bitset>
#include <boost/array.hpp>
#include <boost/endian/conversion.hpp>

#include "ARS540_driver.h"
#include "ARS540_types.h"

ARS540_d::ARS540_d(const std::string &driver_ip, const unsigned int driver_port, const std::string &radar_ip, const unsigned int radar_port) : driver_ip_(driver_ip), driver_port_(driver_port), radar_ip_(radar_ip), radar_port_(radar_port)
{
    setup_radar_endpoint();
    if (!setup_socket())
    {
        throw std::runtime_error("Error setting up driver socket");
    }
}

ARS540_d::ARS540_d(const ARS540_settings &settings) : ARS540_d::ARS540_d(settings.driver_ip_, settings.driver_port_, settings.radar_ip_, settings.radar_port_)
{
}

bool ARS540_d::setup_socket()
{
    driver_endpoint_ = std::make_unique<boost::asio::ip::udp::endpoint>(boost::asio::ip::make_address(driver_ip_), driver_port_);
    try
    {
        driver_socket_ = std::make_unique<boost::asio::ip::udp::socket>(io_context_, *driver_endpoint_);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    return 1;
}

void ARS540_d::setup_radar_endpoint()
{
    radar_endpoint_ = std::make_unique<boost::asio::ip::udp::endpoint>(boost::asio::ip::make_address(radar_ip_), radar_port_);
}

void ARS540_d::receive_and_handle()
{
    // boost::array<char, 1> recv_buf;
    boost::array<std::uint8_t, 132>
        recv_buf = {};
    try
    {
        size_t len = driver_socket_->receive_from(
            boost::asio::buffer(recv_buf), *radar_endpoint_);
        std::cout << "Data received!" << std::endl;

        // DEBUG
        //  for (const auto &byte : recv_buf)
        //  {
        //      std::bitset<8> bits(byte);
        //      std::cout << bits << ' ';
        //  }
        //  std::cout << "\n";

        std::cout << "Number of bytes: " << len << std::endl;
        std::uint16_t radar_method_bytes = (static_cast<std::uint16_t>(recv_buf[3]) << 8) | recv_buf[2]; // includes change in endianess

        switch (static_cast<ARS540::RadarMethodID>(radar_method_bytes))
        {
        case ARS540::RadarMethodID::STATUS:
            std::cout << "Radar method: STATUS." << std::endl;
            break;
        case ARS540::RadarMethodID::OBJECTLIST:
            std::cout << "Radar method: OBJECTLIST." << std::endl;
            break;
        default:
            std::cout << "Radar method ID invalid!" << std::endl;
        }
        std::cout << "Radar method: " << radar_method_bytes << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return;
}

std::ostream &operator<<(std::ostream &os, const ARS540_d &obj)
{
    os << "Displaying driver configuration: \n"
       << "Driver IP: " << obj.driver_ip_ << "\n"
       << "Driver port: " << obj.driver_port_ << "\n"
       << "Radar IP: " << obj.radar_ip_ << "\n"
       << "Radar port: " << obj.radar_port_;
    return os;
}
