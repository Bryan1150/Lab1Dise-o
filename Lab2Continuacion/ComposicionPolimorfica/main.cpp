
#include <iostream>
#include <map>
#include "ProjectManager.h"
#include "CompositeTask.h"
#include "BasicTask.h"
#include "ConstructorTaskXML.h"
#include "ConstructorTaskJSON.h"
#include "Task.h"
#include <string>

std::string director(ConstructorTaskAbstracto& cs, CompositeTask c);

int main(){
  // Proyecto -> Fase -> Tarea
  ProjectManager projects;
  projects.CreateProject("Project1", "Andrey");
  //CompositeTask proyecto1 = CompositeTask();

  CompositeTask phase1("Elaborar P1", "Andrey","description phase1", &projects.getProjects()->at(0), "Phase");
  CompositeTask phase2("Elaborar P2", "Andrey","description phase2", &projects.getProjects()->at(0), "Phase"); 

  BasicTask task1("Administrar", "Andrey","description task1", &phase1, "Task");
  BasicTask task2("Guardar", "Andrey","description task2", &phase1, "Task"); 
  BasicTask task3("Correr", "Andrey","description task3", &phase2, "Task"); 
  BasicTask task4("Terminar", "Andrey","description task4", &phase2, "Task");

  task1.setDate(1,1,2021,1,2,2021);
  task2.setDate(2,2,2021,1,3,2021);
  task3.setDate(3,3,2021,1,4,2021);
  task4.setDate(4,4,2021,1,5,2021);

  projects.getProjects()->at(0).addTask(&phase1);
  projects.getProjects()->at(0).addTask(&phase2);

  phase1.addTask(&task1);
  phase1.addTask(&task2);
  phase2.addTask(&task3);
  phase2.addTask(&task4);

  projects.printProjectState();

  std::array<int, 6> temporal;
  temporal = projects.getProjects()->at(0).computeDates();

  std::cout << "Fecha de inicio del proyecto: " << temporal[0] << " / " << temporal[1] << " / " << temporal[2] << std::endl;
  std::cout << "Fecha de fin del proyecto: " << temporal[3] << " / " << temporal[4] << " / " << temporal[5] << std::endl;

  std::cout << "Ahora usando el serializador XML: \n\n" << std::endl;
  ConstructorTaskAbstracto* cs_xml = new ConstructorTaskXML();
  cs_xml->generarSerializacion(projects.getProjects()->at(0).getName(), projects.getProjects()->at(0).getTasks(), "", projects.getProjects()->at(0).getTipo());


  std::cout << "Ahora usando el serializador JSON: \n\n" << std::endl;
  ConstructorTaskAbstracto* cs_json = new ConstructorTaskJSON();
  cs_json->generarSerializacion(projects.getProjects()->at(0).getName(), projects.getProjects()->at(0).getTasks(), "", projects.getProjects()->at(0).getTipo());
  //cout << director(*cs_xml, projects.getProjects()->at(0)) << std::endl;
}

std::string director(ConstructorTaskAbstracto& cs, CompositeTask c){
	// vector< pair< string, Task* > >  vv;
	// c.(vv); // se obtiene el vector de atributos
	// cs.inicioObjeto(string("Proyecto"));
	// for (auto v : vv)
	// 	switch (v.second->obtTipo())
	// 	{
	// 	case tipo::Entero: cs.serializarEntero(v);
	// 		break;
	// 	case tipo::Doble: cs.serializarDoble(v);
	// 		break;
	// 	}
	// cs.finObjeto();

  //std::vector<std::pair<std::string, std::vector<Task*>* > >  vv;
  //cs.inicioObjeto(string("Proyecto"));
  // for (int i = 0; i < c.tasks.size(); i++){
  //       std::cout << c.tasks[i].to_string() << std::endl;
  // }


  //cs.finObjeto();
	return "cs.obtSerializacion();";
}