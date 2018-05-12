
double RegBankFloat::read_reg( int p_reg ){
    return _regs[ p_reg ];
}

void RegBankFloat::write_reg( int p_reg, double p_value ) {
    _regs[ p_reg ] = p_value;
}

