#include "CompositeTask.h"
#include "BasicTask.h"

CompositeTask::CompositeTask(std::string name){
    this->name = name;
}

void CompositeTask::addTask(std::string name) {
  BasicTask* task = new BasicTask(name);  // create basic task
  task->parent = this;
  this->tasks.push_back(task);
}