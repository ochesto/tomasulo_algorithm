
#include <iostream>
#include <vector>
#include <iomanip>
#include "issue.cpp"

#include <limits>

void printData(work::Issue& issue,
               std::vector<work::Issue::instr_struct>& instr_rom){
  const char separator = ' ';
  const int nameWidth     = 10;
  const int numWidth      = 10;
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Name";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Operation";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Busy?";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Vj";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Vk";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Qj";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Qk";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "A" << std::endl;
  std::cout << std::endl;
  for (int i = 0; i < issue.reservation_table.size(); ++i) {
    work::Issue::reservation_slot test = issue.reservation_table.at(i);
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.name;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.op;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.busy;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.vj;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.vk;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.qj;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.qk;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << test.a << std::endl;
  }
  std::cout << std::endl;
  for (int j = 0; j < issue.register_status.size()/2; ++j) {
    work::Issue::float_register tmp= issue.register_status.at(j);
    work::Issue::float_register tmp1= issue.register_status.at(2*j+1);

    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << tmp.reg_value;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << tmp.reg_name ;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << tmp1.reg_value;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << tmp1.reg_name << std::endl;
  }
  std::cout << std::left << std::setw(nameWidth+10) << std::setfill(separator) << "Instruction";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Issue";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Execute";
  std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Write Back" << std::endl;

  for (int k = 0; k < instr_rom.size(); ++k) {
    work::Issue::instr_struct instr = instr_rom.at(k);
    std::cout << std::left << std::setw(numWidth+10) << std::setfill(separator) << instr.instr_name;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << (instr.issue)?"✓":"X";
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << (instr.execute)?"✓":"X";
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << (instr.write_back)?"✓":"X";
    std::cout << std::endl;
  }
}

enum status {ready, busy};

int main( int argc, char* argv[] ){
    std::string exit = "";
    std::vector<work::Issue::instr_struct> instr_rom;
    //while(exit != "exit") {
    //    work::Issue::instr_struct instr;
    //    std::getline(std::cin, instr.instr_name);
    //    exit = instr.instr_name;
    //    if(exit == "exit") break;
    //    instr_rom.push_back(instr);
    //}

    work::Issue::instr_struct instr;
    instr.instr_name = "LD.D F6 0 R2";
    instr_rom.push_back(instr);
    instr.instr_name = "LD.D F2 0 R3";
    instr_rom.push_back(instr);
    instr.instr_name = "MUL.D F0 F2 F4";
    instr_rom.push_back(instr);
    instr.instr_name = "SUB.D F8 F2 F6";
    instr_rom.push_back(instr);
    instr.instr_name = "ST.D F6 0 R1";
    instr_rom.push_back(instr);
    instr.instr_name = "ADD.D F10 F6 F6";
    instr_rom.push_back(instr);
    instr.instr_name = "ADD.D F4 F2 F6";
    instr_rom.push_back(instr);
    work::Issue issue;
    issue.check_issue(instr_rom);
    std::string parameter;
    std::vector<work::Issue::reservation_slot> operations  = std::vector<work::Issue::reservation_slot>();
    status MEM = ready;
    int mem_cycles = -1;
    int mem_index = 0;
    status add_float = ready;
    int add_cycles = -1;
    int add_index = 0;
    status div_float = ready;
    int div_index = 0;
    int div_cycles = -1;
    status mul_float = ready;
    int mul_index = 0;
    int mul_cycles = -1;
    int CYCLE = 1;
    while(parameter != "exit"){
      freopen("output.txt","a",stdout);
      std::cout << "CYCLE = " << CYCLE << std::endl;
      CYCLE +=1;
      std::cout << std::flush;
      printData(issue,instr_rom);
      getline(std::cin, parameter);
      issue.getOperations(operations);
      for (int i = 0; i < operations.size(); ++i) {
        if((operations.at(i).op == "LOAD" || operations.at(i).op == "STORE")
           && MEM == ready){
          mem_cycles = 2;
          mem_index = i;
          MEM = busy;
          instr_rom.at(operations.at(i).index).execute = true;
        }

        if(operations.at(i).op == "ADD" && !issue._bus._float_adder.is_busy()){
          add_cycles = FLOAT_CYCLES;
          issue._bus._float_adder.set_parameters(operations.at(i).vj, operations.at(i).vk);
          add_index = i;
          instr_rom.at(operations.at(i).index).execute = true;
        }

        if(operations.at(i).op == "SUB" && !issue._bus._float_adder.is_busy()){
          add_cycles = FLOAT_CYCLES;
          issue._bus._float_adder.set_parameters(operations.at(i).vj, (-1)*operations.at(i).vk);
          add_index = i;
          instr_rom.at(operations.at(i).index).execute = true;
        }

        if(operations.at(i).op == "MUL" && !issue._bus._float_mult.is_busy()){
          add_cycles = FLOAT_CYCLES;
          issue._bus._float_mult.set_parameters(operations.at(i).vj,operations.at(i).vk);
          mul_index = i;
          instr_rom.at(operations.at(i).index).execute = true;
        }
      }

      if(MEM == busy && mem_cycles >=1){
        if(mem_cycles == 2){
          operations.at(mem_index).a = operations.at(mem_index).vj + operations.at(mem_index).vk;
          issue.reservation_table.at(operations.at(mem_index).index%9).a = operations.at(mem_index).a;
          mem_cycles -= 1;
        }else if (operations.at(mem_index).op == "LOAD" && mem_cycles ==1){
          issue.updateData(operations.at(mem_index),issue._bus.read_mem(operations.at(mem_index).a));
          issue.total_slot +=1;
          MEM = ready;
          instr_rom.at(operations.at(mem_index).index).write_back = true;
          work::Issue::reservation_slot tmp = operations.at(operations.size()-1);
          operations.at(mem_index) = tmp;
          std::vector<work::Issue::reservation_slot> temporal =  std::vector<work::Issue::reservation_slot>();
          for (int j = 0; j < operations.size() && j != mem_index; ++j) {
            temporal.push_back(operations.at(j));
          }
          operations = std::vector<work::Issue::reservation_slot>();
          operations = temporal;
          if (tmp.op == "ADD" || tmp.op == "SUB") add_index = mem_index;
          if (tmp.op == "MUL") mul_index = mem_index;

        }else if (operations.at(mem_index).op == "STORE" && mem_cycles ==1){
          issue._bus.write_to_mem(operations.at(mem_index).vj,operations.at(mem_index).vk);
          issue.updateData(operations.at(mem_index),operations.at(mem_index).vk);
          instr_rom.at(operations.at(mem_index).index).write_back = true;
          MEM = ready;
          work::Issue::reservation_slot tmp = operations.at(operations.size()-1);
          operations.at(mem_index) = tmp;
          std::vector<work::Issue::reservation_slot> temporal =  std::vector<work::Issue::reservation_slot>();
          for (int j = 0; j < operations.size() && j != mem_index; ++j) {
            temporal.push_back(operations.at(j));
          }
          operations = std::vector<work::Issue::reservation_slot>();
          operations = temporal;
          if (tmp.op == "ADD" || tmp.op == "SUB") add_index = mem_index;
          if (tmp.op == "MUL") mul_index = mem_index;
          issue.total_slot +=1;
        }
      }

      if(issue._bus._float_adder.is_busy()){
        issue._bus._float_adder.add();
        if (!issue._bus._float_adder.is_busy()){
          work::Issue::reservation_slot tmp;
          try {
            instr_rom.at(operations.at(add_index).index).write_back = true;
            issue.updateData(operations.at(add_index), issue._bus._float_adder.get_result());
            tmp = operations.at(operations.size() - 1);
            operations.at(add_index) = tmp;
          }catch(std::out_of_range& e){
            std::cout << "ERROR ADD" << std::endl;
          }
          std::vector<work::Issue::reservation_slot> temporal = std::vector<work::Issue::reservation_slot>();
          for (int j = 0; j < operations.size() && j != add_index; ++j) {
            temporal.push_back(operations.at(j));
          }
          operations = std::vector<work::Issue::reservation_slot>();
          operations = temporal;
          if (tmp.op == "LOAD" || tmp.op == "STORE") mem_index = add_index;
          if (tmp.op == "MUL") mul_index = add_index;
          issue.total_slot +=1;
        }
      }

      if(issue._bus._float_mult.is_busy()){
        issue._bus._float_mult.mult();
        if(!issue._bus._float_mult.is_busy()){
          work::Issue::reservation_slot tmp;
          try{
            instr_rom.at(operations.at(mul_index).index).write_back = true;
            issue.updateData(operations.at(mul_index),issue._bus._float_adder.get_result());
            tmp = operations.at(operations.size()-1);
            operations.at(mul_index) = tmp;
          }catch (std::out_of_range& e){
            std::cout << "ERROR MUL" << mul_index <<" OP SIZE"<<operations.size()<< std::endl;
          }
          std::vector<work::Issue::reservation_slot> temporal;
          for (int j = 0; j < operations.size() && j != mul_index; ++j) {
            temporal.push_back(operations.at(j));
          }
          operations = std::vector<work::Issue::reservation_slot>();
          operations = temporal;
          if (tmp.op == "LOAD" || tmp.op == "STORE") mem_index = mul_index;
          if (tmp.op == "ADD" || tmp.op == "SUB") add_index = mul_index;
          issue.total_slot +=1;
        }
      }
    }
}

