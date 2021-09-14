#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
 protected:
  std::string name;
  std::string assignee;
  std::string description;

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
};

#endif  // TASK_H