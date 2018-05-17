//Libs C++
#include <limits>

//Local libs
#include "constants.hpp"

ALUInt::ALUInt() {
    _busy = false;
    _cycles = INT_CYCLES;
    _param_1 = std::numeric_limits<int>::quiet_NaN();
    _param_2 = std::numeric_limits<int>::quiet_NaN();
    _result = std::numeric_limits<int>::quiet_NaN();
}

void ALUInt::set_parameters( int p_param_1, int p_param_2 ) {
    _param_1 = p_param_1;
    _param_2 = p_param_2;
    _result = std::numeric_limits<int>::quiet_NaN();
}

void ALUInt::add(){
    if( _cycles > 1 && _cycles <= INT_CYCLES ) {
        _cycles--;
        _busy = true;
    } else {
        _cycles = INT_CYCLES;
        _busy = false;
        _result = _param_1 + _param_2;
    }
}

void ALUInt::sub(){
    if( _cycles > 1 && _cycles <= INT_CYCLES ) {
        _cycles--;
        _busy = true;
    } else {
        _cycles = INT_CYCLES;
        _busy = false;
        _result = _param_1 - _param_2;
    }
}

void ALUInt::mult(){
    if( _cycles > 1 && _cycles <= INT_CYCLES ) {
        _cycles--;
        _busy = true;
    } else {
        _cycles = INT_CYCLES;
        _busy = false;
        _result = _param_1 * _param_2;
    }
}

void ALUInt::div(){
    if( _cycles > 1 && _cycles <= INT_CYCLES ) {
        _cycles--;
        _busy = true;
    } else {
        _cycles = INT_CYCLES;
        _busy = false;
        if( _param_2 != int(0) )
            _result = _param_1 / _param_2;
        else
            _result = int(0);
    }
}

int ALUInt::get_result() {
    return _result;
}

bool ALUInt::is_busy(void) {
    return _busy;
}
