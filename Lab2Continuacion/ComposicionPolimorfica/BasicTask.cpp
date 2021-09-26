#include "CompositeTask.h"
#include "BasicTask.h"

BasicTask::BasicTask(std::string name){
    this->name = name;
}

BasicTask::BasicTask(std::string name, std::string assignee, std::string description, CompositeTask* parent, std::string tipoActual) {
  this->name = name;
  this->assignee = assignee;
  this->description = description;
  this->parent = parent;
  this->tipo = tipoActual;
}

std::array<int, 6> BasicTask::computeDates(){
    std::array<int, 6> expectedDates;
    for (int i = 0; i < 6; i++){
      (i < 3) ? expectedDates[i] = this->startDate[i] : expectedDates[i] = this->endDate[i-3]; 
    }
    return expectedDates;
}

void BasicTask::setDate(int firstStart, int secondStart, int thirdStar, int firstSecond, int secondSecond, int thirdSecond){
  this->startDate.at(0) = firstStart;
  this->startDate.at(1) = secondStart;
  this->startDate.at(2) = thirdStar;
  
  this->endDate.at(0) = firstSecond;
  this->endDate.at(1) = secondSecond;
  this->endDate.at(2) = thirdSecond;
}

std::string BasicTask::to_string(){
  std::string taskStr = name + "\n";
  return taskStr;
}

std::vector<Task*> BasicTask::getTasks(){
  std::vector<Task*> temp;
  return temp;
}