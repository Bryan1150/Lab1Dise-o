#include "CompositeTask.h"
#include "BasicTask.h"

CompositeTask::CompositeTask(std::string name, std::string tipoActual){
    this->name = name;
    this->tipo = tipoActual;
}

void CompositeTask::addTask(Task* task) {
  this->tasks.push_back(task);
}

CompositeTask::CompositeTask(std::string name, std::string assignee, std::string description, CompositeTask* parent, std::string tipoActual) {
  this->name = name;
  this->assignee = assignee;
  this->description = description;
  this->parent = parent;
  this->tipo = tipoActual;
}

void CompositeTask::removeTask(std::string name){
  for (auto it = tasks.begin(); it != tasks.end(); ++it){
        if((*it)->getName()== name){
            tasks.erase(it);
        }
    }
}

void CompositeTask::setDate(int firstStart, int secondStart, int thirdStar, int firstSecond, int secondSecond, int thirdSecond){
  std::cout << "Me cole en composite" << std::endl;
  // this->startDate.at(0) = firstStart;
  // this->startDate.at(1) = secondStart;
  // this->startDate.at(2) = thirdStar;
  
  // this->endDate.at(0) = firstSecond;
  // this->endDate.at(1) = secondSecond;
  // this->endDate.at(2) = thirdSecond;
}

std::array<int, 6> CompositeTask::computeDates(){
  std::array<int, 6> dates;
  std::array<int, 6> temp;
  dates.fill(0);
  temp.fill(0);
  dates = tasks[0]->computeDates();
  for (int i = 0; i < tasks.size(); i++){
    temp = tasks[i]->computeDates();


    if (temp[5] > dates[5]){
      dates[5] = temp[5];
      dates[4] = temp[4];
      dates[3] = temp[3];
    }else if(temp[4] > dates[4] && temp[5] == dates[5]){
      dates[5] = temp[5];
      dates[4] = temp[4];
      dates[3] = temp[3];
    }else if(temp[3] > dates[3] && temp[4] == dates[4] && temp[5] == dates[5]){
      dates[5] = temp[5];
      dates[4] = temp[4];
      dates[3] = temp[3];
    }

    if (temp[2] < dates[2]){
      dates[2] = temp[2];
      dates[1] = temp[1];
      dates[0] = temp[0];
    }else if(temp[1] < dates[1] && temp[2] == dates[2]){
      dates[2] = temp[2];
      dates[1] = temp[1];
      dates[0] = temp[0];
    }else if(temp[0] < dates[0] && temp[1] == dates[1] && temp[2] == dates[2]){
      dates[2] = temp[2];
      dates[1] = temp[1];
      dates[0] = temp[0];
    }
  }
  return dates;
}

std::string CompositeTask::to_string() {
  std::string taskStr;
  taskStr += name + " Hijos: ";
  for (int i = 0; i < tasks.size(); ++i) {
    taskStr += tasks[i]->getName() + " ,";
  }
  taskStr += "\b \b\n";
  for (int i = 0; i < tasks.size(); ++i) {
    taskStr += tasks[i]->to_string();
  }

  return taskStr;
}

 void CompositeTask::getAtributos(std::vector<std::pair<std::string, std::vector<Task*>* > >& vectorV){
   int tamano = this->tasks.size();
   vectorV.resize(tamano);
   for (int i = 0; i < tamano; i++){
     vectorV.at(i).first = this->getName();
     vectorV.at(i).second = &(this->tasks);
   }
   
 }


 std::vector<Task*> CompositeTask::getTasks(){
   return this->tasks;
 }