
#include <iostream>
#include <vector>
#include <iomanip>
#include "issue.cpp"

#include <limits>

#include "add_float.hpp"
#include "div_float.hpp"
#include "mult_float.hpp"
#include "alu_int.hpp"

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

/*
double a = std::numeric_limits<double>::quiet_NaN();
    double b = std::numeric_limits<double>::quiet_NaN();

    a = 1;
    b = 14;

    AddFloat float_adder;

    float_adder.set_parameters(a,b);

    std::cout << "add float: ";
    do {
        float_adder.add();
        std::cout << float_adder.get_result() << std::endl;
    } while( float_adder.is_busy() );
    
    //
    DivFloat float_div;

    float_div.set_parameters(a,b);

    std::cout << "div float: ";
    do {
        float_div.div();
        std::cout << float_div.get_result() << std::endl;
    } while( float_div.is_busy() );

    //
    MultFloat float_mult;

    float_mult.set_parameters(a,b);

    std::cout << "mult float: ";
    do {
        float_mult.mult();
        std::cout << float_mult.get_result() << std::endl;
    } while( float_mult.is_busy() );

    //
    ALUInt int_alu;

    int_alu.set_parameters(a,b);

    std::cout << "add int: ";
    do {
        int_alu.add();
        std::cout << int_alu.get_result() << std::endl;
    } while( int_alu.is_busy() );
*/