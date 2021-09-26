#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <string>
#include "CompositeTask.h"
#include "Task.h"
#include <vector>
#include <iostream>

class ProjectManager {
 protected:
 std::vector<CompositeTask> projects;

 public:
 void CreateProject(std::string name, std::string inCharge);
 void removeProject(std::string name);
 void printProjectState();
 std::vector<CompositeTask>* getProjects();

};

#endif  // PROJECT_MANAGER_H