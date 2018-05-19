//Libs C++
#include <limits>

//Local libs
#include "constants.hpp"

AddFloat::AddFloat() {
    _busy = false;
    _cycles = FLOAT_CYCLES;
    _param_1 = std::numeric_limits<double>::quiet_NaN();
    _param_2 = std::numeric_limits<double>::quiet_NaN();
    _result = std::numeric_limits<double>::quiet_NaN();
}

void AddFloat::set_parameters( double p_param_1, double p_param_2 ) {
    _param_1 = p_param_1;
    _param_2 = p_param_2;
    _result = std::numeric_limits<double>::quiet_NaN();
    _busy = true;
}

void AddFloat::add() {
    if( _cycles > 1 && _cycles <= FLOAT_CYCLES ) {
        _cycles--;
        _busy = true;
    } else {
        _cycles = FLOAT_CYCLES;
        _busy = false;
        _result = _param_1 + _param_2;
    }
}

void AddFloat::sub() {
    if( _param_1 != std::numeric_limits<double>::quiet_NaN() &&
    _param_1 != std::numeric_limits<double>::quiet_NaN() &&
    _cycles > 1 && _cycles <= FLOAT_CYCLES ) {
        _cycles--;
        _busy = true;
    } else {
        _cycles = FLOAT_CYCLES;
        _busy = false;
        _result = _param_1 - _param_2;
    }
}

double AddFloat::get_result() {
    return _result;
}

bool AddFloat::is_busy() {
    return _busy;
}
