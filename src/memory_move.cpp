#include <dml/dml.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <numeric>
#include <vector>

constexpr auto size = 1024u;

template <typename path>
int execute_memory_move()
{
    std::cout << "Starting mem move" << std::endl;
    std::cout << "copy 1KB from source to destination" << std::endl;
    
    auto src = std::vector<std::uint8_t>(size);
    std::iota(src.begin(), src.end(), 0u);
    auto dst = std::vector<std::uint8_t>(size, 0u);


    auto result = dml::execute<path>(dml::mem_move, dml::make_view(src), dml::make_view(dst));


    if (result.status == dml::status_code::ok) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << "Incorrect result" << std::endl;
        return -1;
    }

    if (src != dst) {
        std::cout << "Wrong operation result" << std::endl;
        return -1;
    }

    return 0;
    
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Missing the execution path as the first parameter."
                  <<  "Use hardware_path, software_path or automatic_path." << std::endl;
        return 1;
    }

    std::string path = argv[1];
    if (path == "hardware_path")
    {
        std::cout << "Executing using dml::hardware path" << std::endl;
        return execute_memory_move<dml::hardware>();
    }
    else if (path == "software_path")
    {
        std::cout << "Executing using dml::software path" << std::endl;
        return execute_memory_move<dml::software>();
    }
    else if (path == "auto_path")
    {
        std::cout << "Executing using dml::automatic path" << std::endl;
        return execute_memory_move<dml::automatic>();
    }
    else
    {
        std::cout << "Unrecognized value for parameter."
                  << "Use hardware_path, software_path or automatic_path." << std::endl;
        return 1;
    }
}