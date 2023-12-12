#include "Add.h"
#include <iostream>

Add::Add(double rightOperand): rightOperand(rightOperand), input(NULL) {}

Add::~Add() {
	//std::cout << "Add Destructor" << std::endl;
}

Data *Add::process(Data *input) {
	this->input = (FloatingNumber *)input;
	this->input->setData(this->input->getData() + rightOperand);
	
	return this->input;
}