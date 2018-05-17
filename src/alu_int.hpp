#ifndef _ALU_INT_HPP
#define _ALU_INT_HPP

class ALUInt {
    private:
        bool _busy;
        int _cycles;
        int _param_1;
        int _param_2;
        int _result;
    public:
        ALUInt();
        void set_parameters( int p_param_1, int p_param_2 );
        void add();
        void sub();
        void mult();
        void div();
        int get_result();
        bool is_busy();
};

#include "alu_int.cpp"
#endif