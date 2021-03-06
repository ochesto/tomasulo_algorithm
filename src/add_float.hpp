#ifndef _ADDFLOAT_HPP
#define _ADDFLOAT_HPP

class AddFloat {
    private:
        bool _busy;
        int _cycles;
        double _param_1;
        double _param_2;
        double _result;
    public:
        AddFloat();
        void set_parameters( double p_param_1, double p_param_2 );
        void add();
        void sub();
        double get_result(); 
        bool is_busy();
};

#include "add_float.cpp"
#endif