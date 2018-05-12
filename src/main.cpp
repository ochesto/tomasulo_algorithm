
#include <iostream>
#include <vector>
#include "issue.hpp"

int main( int argc, char* argv[] ){
    std::cout << "INICIO" << std::endl;
    std::vector<Issue::instr_struct> instr_rom;
    Issue::instr_struct instr;
    std::cin >> instr.instr_name;
    instr_rom.push_back(instr);
    std::cout << "FIN" << std::endl;
    Issue issue;
    issue.create();
}
