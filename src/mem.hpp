#ifndef _MEM_HPP
#define _MEM_HPP

class Mem {
    private:
        double _mem[1000] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
    public:
        double readmem( int p_addr );
        void writemem( int p_addr, double p_value );
};

#include "mem.cpp"
#endif
