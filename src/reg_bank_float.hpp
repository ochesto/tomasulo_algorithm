#ifndef _REG_BANK_FLOAT_HPP
#define _REG_BANK_FLOAT_HPP
#include "constants.hpp"

class RegBankFloat {
    private:
        double _regs[AMOUNT_REGS];
    public:
        double read_reg( int p_reg );
        void write_reg( int p_reg, double p_value );
};

#include "reg_bank_float.cpp"
#endif
