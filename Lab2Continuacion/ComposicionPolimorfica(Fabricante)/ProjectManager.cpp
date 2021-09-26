#include "ProjectManager.h"
#include <windows.h>

void ProjectManager::CreateProject(std::string name, std::string inCharge){
    CompositeTask newProject = CompositeTask(name, "Proyecto");
    projects.push_back(newProject);
}

void ProjectManager::removeProject(std::string name){
    for (auto it = projects.begin(); it != projects.end(); ++it){
        if(it->getName()== name){
            projects.erase(it);
        }
    }
}

void ProjectManager::printProjectState(){
    for (int i = 0; i < projects.size(); i++){
        std::cout << projects[i].to_string() << std::endl;
    }
}
std::vector<CompositeTask>* ProjectManager::getProjects(){
 return &this->projects;
}