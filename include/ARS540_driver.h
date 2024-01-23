#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <memory>

#include "ARS540_settings.h"

class ARS540_d
{
public:
    ARS540_d(const std::string &driver_ip, const unsigned int driver_port, const std::string &radar_ip, const unsigned int radar_port);

    ARS540_d(const ARS540_settings &settings);

    bool setup_socket();

    void setup_radar_endpoint();

    void receive_and_handle();

    friend std::ostream &operator<<(std::ostream &os, const ARS540_d &obj);

private:
    boost::asio::io_context io_context_;
    std::unique_ptr<boost::asio::ip::udp::endpoint> driver_endpoint_;
    std::unique_ptr<boost::asio::ip::udp::endpoint> radar_endpoint_;
    std::unique_ptr<boost::asio::ip::udp::socket> driver_socket_;

    std::string driver_ip_;
    unsigned int driver_port_;

    std::string radar_ip_;
    unsigned int radar_port_;
};