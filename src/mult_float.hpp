#ifndef _MULTFLOAT_HPP
#define _MULTFLOAT_HPP

class MultFloat {
    private:
        bool _busy;
        int _cycles;
        double _param_1;
        double _param_2;
        double _result;
    public:
        MultFloat();
        void set_parameters( double p_param_1, double p_param_2 );
        void mult();
        double get_result();
        bool is_busy();
};

#include "mult_float.cpp"
#endif