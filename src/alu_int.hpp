#ifndef _ALU_INT_HPP
#define _ALU_INT_HPP

class ALUInt {
    private:
        bool _busy;
        int _cycles;
    public:
        ALUInt();
        int add( int p_p1, int p_p2 );
        int sub( int p_p1, int p_p2 );
        int mult( int p_p1, int p_p2 );
        int div( int p_p1, int p_p2 );
        bool is_busy();
};

#include "alu_int.cpp"
#endif