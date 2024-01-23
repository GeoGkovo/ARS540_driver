#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

int main(int argc, char **argv)
{

    std::ifstream hex_file{"../packet.txt"};
    if (hex_file.is_open())
    {
        std::string hex_string;

        hex_file >> hex_string;
        while (!hex_file.eof())
        { // keep reading until end-of-file
            std::cout << "The next number is " << hex_string << std::endl;
            hex_file >> hex_string; // sets EOF flag if no value found
        }

        std::cout << hex_string << std::endl;

        hex_file.close();

        if (!hex_string.empty())
        {
            std::vector<unsigned char> buffer;

            std::istringstream hex_string_stream(hex_string);

            unsigned char byte;
            while (hex_string_stream >> std::hex >> byte)
            {
                buffer.push_back(byte);
            }

            std::cout << "Buffer content: ";
            for (const auto &byte : buffer)
            {
                std::cout << std::hex << static_cast<int>(byte) << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cerr << "hex_string is empty." << std::endl;
        }
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
    return 0;
}