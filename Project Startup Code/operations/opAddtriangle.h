#pragma once
#include "operations/operation.h"
class opAddtriangle :
    public operation
{
public:
	opAddtriangle(controller* pCont);
	virtual ~opAddtriangle();

	//Add line to the controller
	virtual void Execute();
};

