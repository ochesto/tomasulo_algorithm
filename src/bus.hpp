#ifndef _BUS_HPP
#define _BUS_HPP

#include "mem.hpp"
#include "reg_bank_int.hpp"
#include "reg_bank_float.hpp"

class Bus {
    private:
        Mem _mem;
        RegBankInt _reg_bank_int;
        RegBankFloat _reg_bank_float;
    public:
        double read_mem( int p_addr );
        int read_reg_int( int p_addr );
        double read_reg_float( int p_addr );

        void write_to_mem( int p_addr, double p_value );
        void write_to_reg_int( int p_addr, int p_value );
        void write_to_reg_float( int p_addr, double p_value );
};

#include "bus.cpp"
#endif