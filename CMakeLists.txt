cmake_minimum_required(VERSION 3.22)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(packet_extractor
LANGUAGES CXX)

find_package(Boost 1.74.0 REQUIRED system)
find_package(yaml-cpp REQUIRED)
# find_package(Boost 1.74.0 REQUIRED COMPONENTS asio )

add_executable(example src/packet_extraction.cpp)
add_executable(hex_to_bin src/hex_to_bin.cpp)
# target_include_directories(example PUBLIC ${Boost_LIBRARIES})

add_executable(udp_server src/simple_udp_server.cpp)
add_executable(udp_client src/simple_udp_client.cpp)

add_library(ars540_d src/ARS540_driver.cpp)
target_include_directories(ars540_d PUBLIC "include/") 

add_executable(driver_testing src/main.cpp)
target_include_directories(driver_testing PUBLIC "include/")
target_link_libraries(driver_testing "ars540_d")
