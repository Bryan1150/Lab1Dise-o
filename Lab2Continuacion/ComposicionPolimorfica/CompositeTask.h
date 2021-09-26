#ifndef COMPOSITE_TASK_H
#define COMPOSITE_TASK_H

#include "Task.h"
#include <vector>
#include <iostream>
#include <map>

class CompositeTask : public Task{
 private:
  std::vector<Task*> tasks;
 public:
  
  CompositeTask(std::string name, std::string tipoActual);
  CompositeTask(std::string name, std::string assignee, std::string description, CompositeTask* parent, std::string tipoActual);
  void addTask(Task* task);
  std::array<int, 6> computeDates() override;
  void setDate(int firstStart, int secondStart, int thirdStar, int firstSecond, int secondSecond, int thirdSecond) override;
  void removeTask(std::string name);
  std::string to_string();
  void getAtributos(std::vector<std::pair<std::string, std::vector<Task*>* > >& vectorV);
  std::vector<Task*> getTasks() override;
};

#endif  // COMPOSITE_TASK_H