
#include <iostream>
#include <vector>

int main( int argc, char* argv[] ){
    std::cout << "INICIO" << std::endl;
    std::vector<std::string> instr_rom;
    std::string instr;
    std::cin >> instr;
    instr_rom.push_back(instr);
    std::cout << "FIN" << std::endl;
}
