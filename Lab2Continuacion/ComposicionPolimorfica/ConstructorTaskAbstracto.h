#pragma once

#include <string>
#include <utility>
using namespace std;

#include "BasicTask.h"
#include "CompositeTask.h"

class ConstructorTaskAbstracto
{
public:
	ConstructorTaskAbstracto() {};
	~ConstructorTaskAbstracto() {};

	/* SERIALIZADORES */
    virtual void generarSerializacion(string projectName, std::vector<Task*> tasksArr, string alineText, string tipoActual) = 0;
};