#include "CompositeTask.h"
#include "BasicTask.h"

BasicTask::BasicTask(std::string name){
    this->name = name;
}

void BasicTask::addTask(std::string name) {
  CompositeTask* ctask = new CompositeTask(this->name, this->assignee, this->description, this->parent);
  ctask->addTask(name);
  this->parent->removeTask(this->name);
  this->parent->getTasks()->push_back(ctask);
}

std::array<int, 6> BasicTask::computeDates(){
    std::array<int, 6> expectedDates;
    for (int i = 0; i < 6; i++){
      (i < 3) ? expectedDates[i] = startDate[i] : expectedDates[i] = endDate[i-3]; 
    }
    return expectedDates;
}