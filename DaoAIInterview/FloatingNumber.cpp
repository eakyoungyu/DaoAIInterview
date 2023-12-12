#include "FloatingNumber.h"

FloatingNumber::FloatingNumber(double data): data(data){}
double FloatingNumber::getData() {
	return data;
}
void FloatingNumber::setData(double data) {
	this->data = data;
}