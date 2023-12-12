#pragma once
#include "PostProcessing.h"
#include "FloatingNumber.h"
class OperatorFactory {
public:
	enum operators{
		ADD,
		SUBTRACT,
		MULTIPLY,
		DIVISION
	};
	
	PostProcessing *createOperatorWithOperand(operators opr, double rightOperand);
	PostProcessing* createOperatorWithFloatingNumber(operators opr, FloatingNumber * floatingNumber);
};

