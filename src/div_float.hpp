#ifndef _DIVFLOAT_HPP
#define _DIVFLOAT_HPP

class DivFloat {
    private:
        bool _busy;
        int _cycles;
    public:
        DivFloat();
        double div( double p_p1, double p_p2 );
        bool is_busy();

};

#include "div_float.cpp"
#endif