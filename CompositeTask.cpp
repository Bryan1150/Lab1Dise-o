#include "CompositeTask.h"
#include "BasicTask.h"

CompositeTask::CompositeTask(std::string name){
    this->name = name;
}

void CompositeTask::addTask(std::string name) {
  BasicTask* task = new BasicTask(name);  // create basic task
  task->setParent(this);
  this->tasks.push_back(task);
}

CompositeTask::CompositeTask(std::string name, std::string assignee, std::string description, CompositeTask* parent) {
  this->name = name;
  this->assignee = assignee;
  this->description = description;
  this->parent = parent;
}

void CompositeTask::removeTask(std::string name){
  for (auto it = tasks.begin(); it != tasks.end(); ++it){
        if((*it)->getName()== name){
            tasks.erase(it);
        }
    }
}

std::vector<Task*>* CompositeTask::getTasks() {
  return &this->tasks;
} 

std::array<int, 6> CompositeTask::computeDates(){
  std::array<int, 6> dates;
  std::array<int, 6> temp;
  dates.fill(0);
  for (int i = 0; i < tasks.size(); i++){
    temp = tasks[i].computeDates();
    for (int i = 0; i < 6; i++){
      if (tasks[i]->computeDates()[i] != 0 && tasks[i]->computeDates()[i] < dates[i]){
        dates[i]
      }
      
      
    }
    
    
  }
  
}