
double Bus::read_mem( int p_addr ){
    return mem.readmem( p_addr );
}

int Bus::read_reg_int( int p_addr ){
    return _reg_bank_int.read_reg( p_addr );
}

double Bus::read_reg_float( int p_addr ){
    return _reg_bank_float.read_reg( p_addr );
}

void Bus::write_to_mem( int p_addr, double p_value ){
    mem.writemem( p_addr, p_value );
}

void Bus::write_to_reg_int( int p_addr, int p_value ){
    _reg_bank_int.write_reg( p_addr, p_value );
}

void Bus::write_to_reg_float( int p_addr, double p_value ){
    _reg_bank_float.write_reg( p_addr, p_value );
}
