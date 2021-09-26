#ifndef TASK_H
#define TASK_H

#include <string>
#include <array>
#include <vector>

class CompositeTask;
class Task {
 protected:
  
  std::string assignee;
  std::string description;
  CompositeTask* parent;
  std::string name;
  std::array<int, 3> startDate;
  std::array<int, 3> endDate;
  std::string tipo;
  
 public:

  void setName(std::string name) {
    this->name = name;
  }

  std::string getTipo() {
    return this->tipo;
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

  virtual std::array<int, 6> computeDates() = 0;

  virtual std::vector<Task*> getTasks() = 0;

  virtual void setDate(int firstStart, int secondStart, int thirdStar, int firstSecond, int secondSecond, int thirdSecond) = 0;

  virtual std::string to_string() = 0;
};

#endif  // TASK_H