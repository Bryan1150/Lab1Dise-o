#ifndef COMPOSITE_TASK_H
#define COMPOSITE_TASK_H

#include "Task.h"
#include <vector>

class CompositeTask : public Task{
 private:
  std::vector<Task*> tasks;
 public:
  void addTask(std::string name) override;
  void removeTask();
  CompositeTask(std::string name);
};

#endif  // COMPOSITE_TASK_H