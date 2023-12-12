#pragma once
#include "PostProcessing.h"
#include "FloatingNumber.h"

class Multiply: public PostProcessing {
public:
	Multiply(double rightOperand);
	Data *process(Data *input);
	~Multiply();
private:
	double rightOperand;
	FloatingNumber* input;
};