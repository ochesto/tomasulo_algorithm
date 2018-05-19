#ifndef _REG_BANK_INT_HPP
#define _REG_BANK_INT_HPP
#include "constants.hpp"

class RegBankInt {
    private:
        int _regs[AMOUNT_REGS] = {4,5,6,4,5,6,4,5,6,4,5,6,4,5,6,4,5,6,4,5,6,4,5,6,4,5,6};
    public:
        int read_reg( int p_reg );
        void write_reg( int p_reg, int p_value );
};

#include "reg_bank_int.cpp"
#endif
