#ifndef _ALU_INT_HPP
#define _ALU_INT_HPP

class ALUInt {
    public:
        int add( int p_p1, int p_p2 );
        int sub( int p_p1, int p_p2 );
        int mult( int p_p1, int p_p2 );
        int div( int p_p1, int p_p2 );
};

#include "alu_int.cpp"
#endif