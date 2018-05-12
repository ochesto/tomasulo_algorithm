#ifndef _REG_BANK_INT_HPP
#define _REG_BANK_INT_HPP

class RegBankInt {
    private:
        int _regs[32];
    public:
        int read_reg( int p_reg );
        void write_reg( int p_reg, int p_value );
};

#include "reg_bank_int.cpp"
#endif
