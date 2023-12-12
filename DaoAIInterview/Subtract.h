#pragma once
#include "PostProcessing.h"
#include "FloatingNumber.h"

class Subtract: public PostProcessing {
public:
	Subtract(double rightOperand);
	Data *process(Data *input);
	~Subtract();
private:
	double rightOperand;
	FloatingNumber* input;
};

