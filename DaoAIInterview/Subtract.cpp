#include "Subtract.h"
#include <iostream>

Subtract::~Subtract() {
	//std::cout << "Subtract Destructor" << std::endl;
}
Subtract::Subtract(double rightOperand) : rightOperand(rightOperand), input(NULL) {}

Data *Subtract::process(Data *input) {
	this->input = (FloatingNumber*)input;
	this->input->setData(this->input->getData() - rightOperand);

	return input;
}