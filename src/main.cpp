
#include <iostream>
#include <vector>
#include "bus.hpp"

int main( int argc, char* argv[] ){
    std::cout << "INICIO" << std::endl;
    /*std::vector<std::string> instr_rom;
    std::string instr;
    std::cin >> instr;
    instr_rom.push_back(instr);*/

    Bus _bus;
    _bus.write_to_reg_int( 2, 10 );

    std::cout << _bus.read_reg_int( 2 ) << std::endl;

    std::cout << "FIN" << std::endl;
}
