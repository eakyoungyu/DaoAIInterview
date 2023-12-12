#pragma once
#include "Data.h"

class FloatingNumber: public Data
{
public:
	FloatingNumber(double data);
	double getData();
	void setData(double data);

private:
	double data;
};

