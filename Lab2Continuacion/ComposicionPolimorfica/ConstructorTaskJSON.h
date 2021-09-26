#pragma once

#include <sstream>
using namespace std;

#include "Task.h"
#include "ConstructorTaskAbstracto.h"

class ConstructorTaskJSON : public ConstructorTaskAbstracto
{
public:
	ConstructorTaskJSON();
	~ConstructorTaskJSON();

	/* SERIALIZADORES */
    void generarSerializacion(string projectName, std::vector<Task*> tasksArr, string alineText, string tipoActual) override;

private:
	string serializacion; // el producto del Constructor
};

ConstructorTaskJSON::ConstructorTaskJSON() : serializacion("")
{
}

ConstructorTaskJSON::~ConstructorTaskJSON()
{
}


void ConstructorTaskJSON::generarSerializacion(string projectName, std::vector<Task*> tasksArr, string alineText, string tipoActual){
    string tipoSecundario = tipoActual;
    cout << "{'" << tipoActual << "':" << flush;
    for (int i = 0; i < tasksArr.size(); i++){
        tipoSecundario = tasksArr[i]->getTipo() +  " " + to_string(i);
        generarSerializacion(tasksArr[i]->getName(),tasksArr[i]->getTasks(), ",", tipoSecundario);
        
        
    }
    cout << "{'Title'}:'" << projectName << "'" << flush;
    
     

    cout <<"}" << alineText << flush;
}