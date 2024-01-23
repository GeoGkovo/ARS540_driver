#include <iostream>
#include <string>
#include "yaml-cpp/yaml.h"

class ARS540_settings
{
public:
    ARS540_settings() {}
    void load_params_from_file(std::string filename)
    {
        YAML::Node node;
        try
        {
            node = YAML::LoadFile(filename);

            driver_ip_ = node[0]["driver_ip"].as<std::string>();
            driver_port_ = node[0]["driver_port"].as<uint>();
            radar_ip_ = node[0]["radar_ip_"].as<std::string>();
            radar_port_ = node[0]["radar_port"].as<uint>();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            std::cerr << "Parameters not set properly!" << std::endl;
            return;
        }
    }
    std::string driver_ip_;
    unsigned int driver_port_;
    std::string radar_ip_;
    unsigned int radar_port_;
};