
#include <iostream>
#include <vector>
#include "issue.cpp"

int main( int argc, char* argv[] ){
    std::cout << "INICIO" << std::endl;
    std::string exit = "";
    std::vector<work::Issue::instr_struct> instr_rom;
    while(exit != "exit") {
        work::Issue::instr_struct instr;
        std::getline(std::cin, instr.instr_name);
        exit = instr.instr_name;
        if(exit == "exit") break;
        instr_rom.push_back(instr);

    }
    std::cout << "FIN" << std::endl;
    work::Issue issue;
    issue.check_issue(instr_rom);

    for (int i = 0; i < issue.reservation_table.size(); ++i) {
        work::Issue::reservation_slot test = issue.reservation_table.at(i);
        std::cout << test.name << " " << test.busy << " " << test.op << " " << test.vj << " " << test.vk << " " << test.qj << " " << test.qk << " " << test.a << std::endl;
    }

    for (int j = 0; j < issue.register_status.size(); ++j) {
        work::Issue::float_register tmp= issue.register_status.at(j);
        std::cout << tmp.reg_value << " " << tmp.reg_name << std::endl;
    }
}
