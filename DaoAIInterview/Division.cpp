#include "Division.h"
#include <stdexcept>
#include <iostream>

Division::~Division() {
	//std::cout << "Division Destructor" << std::endl;
}

Division::Division(double rightOperand): rightOperand(rightOperand), input(NULL) {
	if (rightOperand == 0) {
		throw std::runtime_error("division by 0");
	}
}

Data *Division::process(Data *input) {

	this->input = (FloatingNumber*)input;
	this->input->setData(this->input->getData() / rightOperand);

	return input;
}