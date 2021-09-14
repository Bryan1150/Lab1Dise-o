#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
 protected:
  std::string name;
  std::string inCharge;
  std::string description;

 public:
  void setName(std::string name) {
    this->name = name;
  }

  std::string getName() {
    return this->name;
  }

  void setInCharge(std::string inCharge) {
    this->inCharge = inCharge;
  }

  virtual std::string getInCharge() = 0;

  void setDescription(std::string description) {
    this->description = description;
  }

  std::string getDescription() {
    return this->name;
  }
};

#endif  // TASK_H