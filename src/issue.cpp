//
// Created by isaac on 5/12/18.
//

#include "issue.hpp"
namespace work {
  Issue::Issue() {
    reservation_slot load1;
    load1.name = "load1";
    reservation_slot load2;
    load2.name = "load2";
    reservation_slot add1;
    add1.name = "add1";
    reservation_slot add2;
    add2.name = "add2";
    reservation_slot add3;
    add3.name = "add3";
    reservation_slot mul1;
    mul1.name = "mul1";
    reservation_slot mul2;
    mul2.name = "mul2";
    reservation_slot store1;
    store1.name = "store1";
    reservation_slot store2;
    store2.name = "store2";

    Issue::reservation_table.push_back(load1);
    Issue::reservation_table.push_back(load2);
    Issue::reservation_table.push_back(add1);
    Issue::reservation_table.push_back(add2);
    Issue::reservation_table.push_back(add3);
    Issue::reservation_table.push_back(mul1);
    Issue::reservation_table.push_back(mul2);
    Issue::reservation_table.push_back(store1);
    Issue::reservation_table.push_back(store2);

    std::string name = "F";
    for (int i = 0; i < 32; ++i) {
      std::string reg = name + std::to_string(i);
      Issue::float_register reg_slot;
      reg_slot.reg_name = reg;
      register_status.push_back(reg_slot);
    }
  }

  Issue::~Issue() {

  }

  void Issue::check_issue(std::vector<Issue::instr_struct> &instr_file) {
    int size = instr_file.size();
    int max_reserve = reservation_table.size();
    try {
      for (int i = 0; i < size && total_slot > 0; ++i) {
        std::string name = instr_file.at(i).instr_name;
        std::string reg_s0 = "";
        if (!instr_file.at(i).issue) {
          std::vector<std::string> instr;
          boost::split(instr, name, boost::is_any_of(" "));
            std::string operation;
            if (instr.at(0).find("LD") != std::string::npos) {
              for (int k = 0; k < 2; ++k) {
                if (!reservation_table.at(k).busy && !instr_file.at(i).issue) {
                  operation = reservation_table.at(k).name;
                  reg_s0 = checkDependecy(instr.at(1));
                  if (reg_s0 == "") {
                    reservation_table.at(k).op = "LOAD";
                    reservation_table.at(k).busy = true;
                    try {
                      reservation_table.at(k).vj = std::stoi(instr.at(2));
                    }catch(std::exception& e){
                      std::cout << __LINE__ << std::endl;
                    }
                    std::string tmp = instr.at(3);
                    reservation_table.at(k).vk = _bus.read_reg_int(std::stoi(tmp.substr(1, tmp.length() - 1)));
                    reservation_table.at(k).busy = true;
                    reservation_table.at(k).index = i;
                    updateRegStatus(instr.at(1), operation);
                    instr_file.at(i).issue = true;
                  }
                  total_slot -= 1;
                }
              }
              //cambiar para que cumpla el algoritmo de tomasulo.
            } else if ((instr.at(0).find("ST") != std::string::npos)) {
              for (int k = 0; k < 2; ++k) {
                if (!reservation_table.at(7 + k).busy && !instr_file.at(i).issue) {
                  operation = reservation_table.at(7 + k).name;
                  reservation_table.at(7 + k).op = "STORE";
                  reservation_table.at(7 + k).busy = true;
                  std::string tmp = instr.at(3);
                  std::string tmp1 = instr.at(1);
                  std::string reg = checkDependecy(tmp1);
                  try {
                    reservation_table.at(k).vj = std::stoi(instr.at(2)) + _bus.read_reg_int(std::stoi(tmp.substr(1, tmp.length() - 1)));
                    reservation_table.at(k).vk = (reg == "") ? _bus.read_reg_float( std::stoi(tmp1.substr(1, tmp1.length() - 1)) ):0;
                  }catch(std::exception& e){
                    std::cout << "This presents an error: "<< instr.at(0) << std::endl;
                    std::cout << __LINE__ << std::endl;
                  }
                  reservation_table.at(7 + k).qk = reg;
                  reservation_table.at(7 + k).busy = true;
                  reservation_table.at(7 + k).index = i;
                  total_slot -= 1;
                  instr_file.at(i).issue = true;
                }
              }

            } else if ((instr.at(0).find("MUL") != std::string::npos) ||
                       (instr.at(0).find("ADD") != std::string::npos) ||
                       (instr.at(0).find("SUB") != std::string::npos)) {
              int index = (instr.at(0).substr(0, 3) == "MUL") ? 5 : 2;
              int offset = (instr.at(0).substr(0, 3) == "ADD") ? 3 : 2;
              for (int k = 0; k < offset; ++k) {
                if (!reservation_table.at(index + k).busy && !instr_file.at(i).issue) {
                  operation = reservation_table.at(index + k).name;
                  reg_s0 = checkDependecy(instr.at(1));
                  if (reg_s0 == "") {
                    reservation_table.at(index + k).op = instr.at(0).substr(0, 3);
                    reservation_table.at(index + k).busy = true;
                    std::string reg_s1 = checkDependecy(instr.at(2));
                    std::string reg_s2 = checkDependecy(instr.at(3));
                    std::string tmp0 = instr.at(2);
                    std::string tmp1 = instr.at(3);
                    reservation_table.at(index + k).qj = reg_s1;
                    reservation_table.at(index + k).qk = reg_s2;
                    reservation_table.at(index + k).vj = (reg_s1 == "") ? _bus.read_reg_float( std::stoi(tmp0.substr(1, tmp0.length() - 1)) ):0;
                    reservation_table.at(index + k).vk = (reg_s2 == "") ? _bus.read_reg_float( std::stoi(tmp1.substr(1, tmp1.length() - 1)) ):0;
                    reservation_table.at(index + k).busy = true;
                    instr_file.at(i).issue = true;
                    reservation_table.at(index + k).index = i;
                    updateRegStatus(instr.at(1), operation);
                  }
                  total_slot -= 1;
                }
              }
            }
        }
      }
    }catch (std::exception& e){
      std::cout << e.what() << std::endl;
    }
  }

  std::string Issue::checkDependecy(std::string reg) {
    for (int i = 0; i < register_status.size(); ++i) {
      if (reg == register_status.at(i).reg_name)
        return register_status.at(i).reg_value;
    }
  }

  void Issue::updateRegStatus(std::string reg_name, std::string reg_op) {
    for (int i = 0; i < register_status.size(); ++i) {
      if ((reg_name == register_status.at(i).reg_name) && (register_status.at(i).reg_value == "")) {
        register_status.at(i).reg_value = reg_op;
        break;
      }

    }
  }

  void Issue::getOperations(std::vector<work::Issue::reservation_slot> &operations) {
    int size = reservation_table.size();
    for (int i = 0; i < size && operations.size() < 3; ++i) {
      reservation_slot tmp = reservation_table.at(i);
      if( (tmp.qk == "") && (tmp.qj == "") && tmp.busy){
        operations.push_back(tmp);
      }
    }
  }

  void Issue::updateData(work::Issue::reservation_slot &operation, double result) {
    int size = reservation_table.size();
    for (int i = 0; i < size; ++i) {
      if (reservation_table.at(i).qj == operation.name){
        reservation_table.at(i).vj = result;
        reservation_table.at(i).qj = "";
      }

      if (reservation_table.at(i).qk == operation.name){
        reservation_table.at(i).vj = result;
        reservation_table.at(i).qk = "";
      }

      if(reservation_table.at(i).name == operation.name){
        reservation_slot _new;
        _new.name = operation.name;
        reservation_table.at(i) = _new;
        int reg_size = register_status.size();
        for (int j = 0; j < reg_size; ++j) {
          register_status.at(j).reg_value = (register_status.at(j).reg_value == operation.name)?"":register_status.at(j).reg_value;
        }
      }
    }
  }
}