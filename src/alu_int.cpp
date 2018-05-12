#define CYCLES 2

ALUInt::ALUInt() {
    _busy = false;
    _cycles = CYCLES;
}

int ALUInt::add( int p_p1, int p_p2 ){
    int result;
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

int ALUInt::sub( int p_p1, int p_p2 ){
    int result;
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

int ALUInt::mult( int p_p1, int p_p2 ){
    int result;
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

int ALUInt::div( int p_p1, int p_p2 ){
    int result;
    if( _cycles > 0 && _cycles <= CYCLES ) {
        _cycles--;
        _busy = true;
        result = 0;
    }
    else {
        _busy = false;
        _cycles = CYCLES;
        if( p_p2 != int(0) ) result = p_p1 / p_p2;   
        else result = int(0);
    }
    return result;
}

bool ALUInt::is_busy(void) {
    return _busy;
}
