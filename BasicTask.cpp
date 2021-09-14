#include "CompositeTask.h"
#include "BasicTask.h"

BasicTask::BasicTask(std::string name){
    this->name = name;
}

void BasicTask::addTask(std::string name) {
  BasicTask* task = new BasicTask(name);
  task->parent = this;
}