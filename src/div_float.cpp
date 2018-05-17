//Libs C++
#include <limits>

//Local libs
#include "constants.hpp"

DivFloat::DivFloat(){
    _busy = false;
    _cycles = FLOAT_CYCLES;
    _param_1 = std::numeric_limits<double>::quiet_NaN();
    _param_2 = std::numeric_limits<double>::quiet_NaN();
    _result = std::numeric_limits<double>::quiet_NaN();
}

void DivFloat::set_parameters( double p_param_1, double p_param_2 ) {
    _param_1 = p_param_1;
    _param_2 = p_param_2;
    _result = std::numeric_limits<double>::quiet_NaN();
}

void DivFloat::div(){
    if( _cycles > 1 && _cycles <= FLOAT_CYCLES ) {
        _cycles--;
        _busy = true;
    } else {
        _cycles = FLOAT_CYCLES;
        _busy = false;
        if( _param_2 != double(0) )
            _result = _param_1 / _param_2;
        else
            _result = double(0);
    }
}

double DivFloat::get_result() {
    return _result;
}

bool DivFloat::is_busy(void) {
    return _busy;
}
