#ifndef COMPOSITE_TASK_H
#define COMPOSITE_TASK_H

#include "Task.h"
#include <vector>

class CompositeTask : public Task{
 private:
  std::vector<Task*> tasks;

 public:
  void addTask(Task* task);
  void removeTask();

};

#endif  // COMPOSITE_TASK_H