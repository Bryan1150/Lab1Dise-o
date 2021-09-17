#ifndef TASK_H
#define TASK_H

#include <string>
class CompositeTask;
class Task {
 protected:
  
  std::string assignee;
  std::string description;
  CompositeTask* parent;
  std::string name;
  
 public:

  void setName(std::string name) {
    this->name = name;
  }

  std::string getName() {
    return this->name;
  }

  void setAssignee(std::string assignee) {
    this->assignee = assignee;
  }

  virtual std::string getAssignee() {
    return this->assignee;
  }

  void setDescription(std::string description) {
    this->description = description;
  }

  std::string getDescription() {
    return this->name;
  }

  virtual void addTask(std::string name) = 0;

  virtual std::array<int, 6> computeDates() = 0;

  Task* getParent(){
    return this->parent;
  }

  void setParent(CompositeTask* parent){
    this->parent = parent;
  }
};

#endif  // TASK_H