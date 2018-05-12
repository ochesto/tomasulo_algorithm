
int RegBankInt::read_reg( int p_reg ){
    return _regs[ p_reg ];
}

void RegBankInt::write_reg( int p_reg, int p_value ) {
    _regs[ p_reg ] = p_value;
}
