#ifndef BASIC_TASK_H
#define BASIC_TASK_H

#include "Task.h"
#include <array>

class BasicTask : public Task{
 private:
  std::array<int, 3> startDate;
  std::array<int, 3> endDate;
  
 public:
  void addTask(std::string name) override;
  std::array<int, 6> computeDates() override;
  BasicTask(std::string name);
};

#endif  // COMPOSITE_TASK_H