//
// Created by isaac on 5/12/18.
//

#ifndef TOMASULO_ALGORITHM_ISSUE_HPP
#define TOMASULO_ALGORITHM_ISSUE_HPP


#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <boost/algorithm/string.hpp>

#include "bus.hpp"
namespace work {
  class Issue {

  public:
    Issue();
    ~Issue();
    struct reservation_slot {
      std::string name = "";
      std::string op = "";
      std::string qj = "";
      std::string qk = "";
      double vj = 0;
      double vk = 0;
      int a = 0;
      bool busy = false;
    };
    struct instr_struct {
      std::string instr_name;
      bool issue = false;
      bool execute = false;
      bool write_back = false;
    };

    struct float_register {
      std::string reg_name = "";
      std::string reg_value = "";
    };

    void check_issue(std::vector<Issue::instr_struct> &instr_file);

    std::vector<reservation_slot> reservation_table;
    std::vector<float_register> register_status;

  private:
    int total_slot = 7;

    std::string checkDependecy(std::string reg);

    void updateRegStatus(std::string reg_name, std::string reg_op);

    Bus _bus;

  };
}

#endif //TOMASULO_ALGORITHM_ISSUE_HPP
