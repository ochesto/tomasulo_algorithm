
#include <iostream>
#include <vector>
#include <iomanip>
#include "issue.cpp"

int main( int argc, char* argv[] ){
    std::string exit = "";
    std::vector<work::Issue::instr_struct> instr_rom;
    /*while(exit != "exit") {
        work::Issue::instr_struct instr;
        std::getline(std::cin, instr.instr_name);
        exit = instr.instr_name;
        if(exit == "exit") break;
        instr_rom.push_back(instr);

    }*/
    work::Issue::instr_struct instr;
    instr.instr_name = "LD.D F6 0 R2";
    instr_rom.push_back(instr);
    instr.instr_name = "LD.D F2 0 R3";
    instr_rom.push_back(instr);
    instr.instr_name = "MUL.D F0 F2 F4";
    instr_rom.push_back(instr);
    instr.instr_name = "SUB.D F8 F2 F6";
    instr_rom.push_back(instr);
    instr.instr_name = "ST.D F6 0 R1";
    instr_rom.push_back(instr);
    instr.instr_name = "ADD.D F10 F6 F6";
    instr_rom.push_back(instr);
    instr.instr_name = "ADD.D F4 F2 F6";
    instr_rom.push_back(instr);
    work::Issue issue;
    issue.check_issue(instr_rom);
    const char separator = ' ';
    const int nameWidth     = 10;
    const int numWidth      = 10;
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Name";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Operation";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Busy?";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Vj";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Vk";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Qj";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Qk";
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "A" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < issue.reservation_table.size(); ++i) {
        work::Issue::reservation_slot test = issue.reservation_table.at(i);
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.name;
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.op;
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.busy;
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.vj;
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.vk;
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.qj;
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.qk;
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.a << std::endl;
    }
    std::cout << std::endl;
    for (int j = 0; j < issue.register_status.size(); ++j) {
        work::Issue::float_register tmp= issue.register_status.at(j);
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << tmp.reg_value;
        std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << tmp.reg_name << std::endl;
    }
}
