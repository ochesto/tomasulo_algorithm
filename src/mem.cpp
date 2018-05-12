
double Mem::readmem( int p_addr ){
    return _mem[p_addr];
}

void Mem::writemem( int p_addr, double p_value ){
    _mem[ p_addr ] = p_value;
}
