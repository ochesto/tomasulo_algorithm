#ifndef _MULTFLOAT_HPP
#define _MULTFLOAT_HPP

class MultFloat {
    private:
        bool _busy;
        int _cycles;
    public:
        MultFloat();
        double mult( double p_p1, double p_p2 );
        bool is_busy();
};

#include "mult_float.cpp"
#endif