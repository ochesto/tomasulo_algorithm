
#include <iostream>
#include <vector>
#include "issue.hpp"

#include <limits>

#include "add_float.hpp"
#include "div_float.hpp"
#include "mult_float.hpp"
#include "alu_int.hpp"

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