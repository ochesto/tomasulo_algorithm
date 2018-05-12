#ifndef _MEM_HPP
#define _MEM_HPP

class Mem {
    private:
        double _mem[1000];
    public:
        double read_mem( int p_addr );
        void write_mem( int p_addr, double p_value );
};

#include "mem.cpp"
#endif
