#pragma once
#include "PostProcessing.h"
#include "FloatingNumber.h"

class Division: public PostProcessing {
public:
	Division(double rightOperand);
	Data *process(Data *input);
	~Division();
private:
	double rightOperand;
	FloatingNumber* input;
};