#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <cstdint>

int main()
{
    // Hexadecimal transmission string
    std::string hexTransmission = "01005e0002023806b438b38100001308004500007010ae00000311b94f0a0d0171e0000202a5a2a476005c18d0000017c0000004c03424ab400000086020548040000000000000000003f1c28f60000000000000000000000408bef9e3fe978d63fc00001402ae148012d01320a01000a0d0171a9fe7471000101010101010100000024";

    // Convert hex string to binary
    std::stringstream ss;
    for (size_t i = 0; i < hexTransmission.length(); i += 2)
    {
        std::string byteString = hexTransmission.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoul(byteString, nullptr, 16));
        ss << byte;
    }

    // Display the binary representation
    std::string binaryTransmission = ss.str();
    // for (const unsigned char &byte : binaryTransmission)
    // {
    //     std::cout << std::bitset<8>(byte) << ' ';
    // }
    int count = 0;
    for (const std::uint8_t &byte : binaryTransmission)
    {
        count++;
        std::cout << std::bitset<8>(byte) << ' ';
    }
    std::cout << "\n";
    std::cout << "Number of bytes: " << count << std::endl;
    return 0;
}