#define CYCLES 6

AddFloat::AddFloat() {
    _busy = false;
    _cycles = CYCLES;
}

double AddFloat::add( double p_p1, double p_p2 ) {
    double result;
    if( _cycles > 0 && _cycles <= CYCLES ) {
        _cycles--;
        _busy = true;
        result = 0;
    }
    else {
        _busy = false;
        _cycles = CYCLES;
        result = p_p1 + p_p2;
    }
    return result;
}

double AddFloat::sub( double p_p1, double p_p2 ) {
    double result;
    if( _cycles > 0 && _cycles <= CYCLES ) {
        _cycles--;
        _busy = true;
        result = 0;
    }
    else {
        _busy = false;
        _cycles = CYCLES;
        result = p_p1 - p_p2;
    }
    return result;
}

bool AddFloat::is_busy(void) {
    return _busy;
}
