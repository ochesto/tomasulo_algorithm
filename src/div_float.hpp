#ifndef _DIVFLOAT_HPP
#define _DIVFLOAT_HPP

class DivFloat {
    private:
        bool _busy;
        int _cycles;
        double _param_1;
        double _param_2;
        double _result;
    public:
        DivFloat();
        void set_parameters( double p_param_1, double p_param_2 );
        void div();
        double get_result();
        bool is_busy();
};

#include "div_float.cpp"
#endif