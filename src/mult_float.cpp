
#define CYCLES 6

MultFloat::MultFloat(){
    _busy = false;
    _cycles = CYCLES;
}

double MultFloat::mult( double p_p1, double p_p2 ){
    double result;
    if( _cycles > 0 && _cycles <= CYCLES ) {
        _cycles--;
        _busy = true;
        result = 0;
    }
    else {
        _busy = false;
        _cycles = CYCLES;
        result = p_p1 * p_p2;
    }
    return result;  
}

bool MultFloat::is_busy(void) {
    return _busy;
}
