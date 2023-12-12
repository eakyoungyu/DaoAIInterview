#include "Multiply.h"
#include <iostream>

Multiply::~Multiply() {
	//std::cout << "Multiply Destructor" << std::endl;
}

Multiply::Multiply(double rightOperand) : rightOperand(rightOperand), input(NULL) {}

Data *Multiply::process(Data *input) {
	this->input = (FloatingNumber*)input;
	this->input->setData(this->input->getData() * rightOperand);

	return input;
}