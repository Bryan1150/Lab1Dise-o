#ifndef BASIC_TASK_H
#define BASIC_TASK_H

#include "Task.h"
#include <array>

class BasicTask : public Task{
  
 public:
  BasicTask(std::string name);
  BasicTask(std::string name, std::string assignee, std::string description, CompositeTask* parent, std::string tipoActual);
  std::array<int, 6> computeDates() override;
  void setDate(int firstStart, int secondStart, int thirdStar, int firstSecond, int secondSecond, int thirdSecond) override;
  std::string to_string();
  std::vector<Task*> getTasks() override;
};

#endif  // COMPOSITE_TASK_H