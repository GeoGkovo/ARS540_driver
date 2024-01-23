#include <iostream>
#include <string>
#include <ARS540_driver.h>

int main(int argc, char **argv)
{
    std::string ip_d = "127.0.0.1";
    unsigned int port_d = 13;
    std::string ip_r = "127.0.0.1";
    unsigned int port_r = 46516;

    ARS540_d driver(ip_d, port_d, ip_r, port_r);
    std::cout << driver << std::endl;

    for (;;)
    {
        driver.receive_and_handle();
    }
    return 0;
}
