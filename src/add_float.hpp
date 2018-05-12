#ifndef _ADDFLOAT_HPP
#define _ADDFLOAT_HPP

class AddFloat {
    private:
        bool _busy;
        int _cycles;
    public:
        AddFloat();
        double add( double p_p1, double p_p2 );
        double sub( double p_p1, double p_p2 );
        bool is_busy();
};

#include "add_float.cpp"
#endif