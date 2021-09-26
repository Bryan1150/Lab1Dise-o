#pragma once

#include <sstream>
using namespace std;

#include "Task.h"
#include "ConstructorTaskAbstracto.h"

class ConstructorTaskXML : public ConstructorTaskAbstracto
{
public:
	ConstructorTaskXML();
	~ConstructorTaskXML();

	/* SERIALIZADORES */
    void generarSerializacion(string projectName, std::vector<Task*> tasksArr, string alineText, string tipoActual) override;

private:
	string serializacion; // el producto del Constructor
};

ConstructorTaskXML::ConstructorTaskXML() : serializacion("")
{
}

ConstructorTaskXML::~ConstructorTaskXML()
{
}


void ConstructorTaskXML::generarSerializacion(string projectName, std::vector<Task*> tasksArr, string alineText, string tipoActual){
    string newAlineText = alineText + "\t";
    cout << alineText << "<" << tipoActual << ">" << endl;
    cout << newAlineText << "<Title>" << projectName << "</Title>" << endl;
    for (int i = 0; i < tasksArr.size(); i++){
        generarSerializacion(tasksArr[i]->getName(),tasksArr[i]->getTasks(), newAlineText, tasksArr[i]->getTipo());
    }
     

    cout << alineText <<"</" << tipoActual << ">" << endl;
}