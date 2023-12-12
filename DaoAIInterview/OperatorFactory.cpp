#include <stdexcept>
#include "OperatorFactory.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Division.h"

PostProcessing* OperatorFactory::createOperatorWithOperand(operators opr, double rightOperand) {
	switch (opr) {
	case operators::ADD:
		return new Add(rightOperand);
	case operators::SUBTRACT:
		return new Subtract(rightOperand);
	case operators::MULTIPLY:
		return new Multiply(rightOperand);
	case operators::DIVISION:
		return new Division(rightOperand);
	default:
		throw std::runtime_error("Invalid operator");
	}
}

PostProcessing* OperatorFactory::createOperatorWithFloatingNumber(operators opr, FloatingNumber* floatingNumber) {
	double rightOperand = floatingNumber->getData();
	delete floatingNumber;
	return createOperatorWithOperand(opr, rightOperand);
}