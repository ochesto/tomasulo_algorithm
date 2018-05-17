#ifndef _MEM_HPP
#define _MEM_HPP

class Mem {
    private:
        double _mem[1000];
    public:
        double readmem( int p_addr );
        void writemem( int p_addr, double p_value );
};

#include "mem.cpp"
#endif
