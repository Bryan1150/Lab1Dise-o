#include <iostream>
#include <map>
#include "ProjectManager.h"
#include "CompositeTask.h"
#include "BasicTask.h"
#include "Task.h"
#include <string>

enum projectType {
	PT_CompositeTask, PT_BasicTask, PT_Project
};

Task* taskFactory(projectType type, std::string name, std::string assignee, std::string description, CompositeTask* parent, std::string tipoActual)
{
	if (type == PT_CompositeTask) {
		return new CompositeTask(name, assignee, description, parent, tipoActual);
	}

	else if (type == PT_BasicTask) {
		return new BasicTask(name, assignee, description, parent, tipoActual);
	}

	else return NULL;
}

int main(){
  // Proyecto -> Fase -> Tarea
  ProjectManager projects;
  projects.CreateProject("Project1", "Andrey");

  /*
  Task* phase1 = taskFactory(PT_CompositeTask, "Elaborar P1", "Andrey","description phase1", &projects.getProjects()->at(0), "Phase");
  Task* phase2 = taskFactory(PT_CompositeTask, "Elaborar P2", "Andrey","description phase2", &projects.getProjects()->at(0), "Phase");
 
  Task* task1 = taskFactory(PT_BasicTask, "Administrar", "Andrey","description task1", phase1, "Task");
  Task* task2 = taskFactory(PT_BasicTask, "Guardar", "Andrey","description task2", &phase1, "Task");
  Task* task3 = taskFactory(PT_BasicTask, "Correr", "Andrey","description task3", &phase2, "Task");
  Task* task4 = taskFactory(PT_BasicTask, "Terminar", "Andrey","description task4", &phase2, "Task");
 
  task1->setDate(1,1,2021,1,2,2021);
  task2->setDate(2,2,2021,1,3,2021);
  task3->setDate(3,3,2021,1,4,2021);
  task4->setDate(4,4,2021,1,5,2021);

  projects.getProjects()->at(0).addTask(&phase1);
  projects.getProjects()->at(0).addTask(&phase2);

  phase1->addTask(&task1);
  phase1->addTask(&task2);
  phase2->addTask(&task3);
  phase2->addTask(&task4);
  */
  projects.printProjectState();

  std::array<int, 6> temporal;
  temporal = projects.getProjects()->at(0).computeDates();

  std::cout << "Fecha de inicio del proyecto: " << temporal[0] << " / " << temporal[1] << " / " << temporal[2] << std::endl;
  std::cout << "Fecha de fin del proyecto: " << temporal[3] << " / " << temporal[4] << " / " << temporal[5] << std::endl;


  return NULL;
}