#pragma once
#include "PostProcessing.h"
#include "FloatingNumber.h"

class Add: public PostProcessing {
public:
	Add(double rightOperand);
	Data *process(Data *input);
	~Add();
private:
	double rightOperand;
	FloatingNumber *input;
};

