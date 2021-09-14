#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <string>
#include "CompositeTask.h"
#include <vector>

class ProjectManager {
 protected:
 std::vector<CompositeTask> projects;

 public:
 void CreateProject(std::string name, std::string inCharge);
 void removeProject(std::string name);
 
};

#endif  // PROJECT_MANAGER_H