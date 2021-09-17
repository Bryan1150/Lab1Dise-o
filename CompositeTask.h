#ifndef COMPOSITE_TASK_H
#define COMPOSITE_TASK_H

#include "Task.h"
#include <vector>

class CompositeTask : public Task{
 private:
  std::vector<Task*> tasks;
 public:
  void addTask(std::string name) override;
  std::array<int, 6> computeDates() override;
  void removeTask(std::string name);
  CompositeTask(std::string name);
  CompositeTask(std::string name, std::string assignee, std::string description, CompositeTask* parent);
  std::vector<Task*>* getTasks();
};

#endif  // COMPOSITE_TASK_H