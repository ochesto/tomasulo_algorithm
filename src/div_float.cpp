
#define CYCLES 6

DivFloat::DivFloat(){
    _busy = false;
    _cycles = CYCLES;
}

double DivFloat::div( double p_p1, double p_p2 ){
    double result;
    if( _cycles > 0 && _cycles <= CYCLES ) {
        _cycles--;
        _busy = true;
        result = 0;
    }
    else {
        _busy = false;
        _cycles = CYCLES;
        if( p_p2 != double(0) ) result = p_p1 / p_p2;   
        else result = double(0);
    }
    return result;
}

bool DivFloat::is_busy(void) {
    return _busy;
}
