#include "ProjectManager.h"

void ProjectManager::CreateProject(std::string name, std::string inCharge){
    CompositeTask newProject = CompositeTask(name);
    projects.push_back(newProject);
}

void ProjectManager::removeProject(std::string name){
    for (auto it = projects.begin(); it != projects.end(); ++it){
        if(it->getName()== name){
            projects.erase(it);
        }
    }
}

/**
public void print(int level) {
    for (int i = 1; i < level; i++) {
        System.out.print("\t");
    }
    System.out.println(data);
    for (Tree child : children) {
        child.print(level + 1);
    }
}



/**

