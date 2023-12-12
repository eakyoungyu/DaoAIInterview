#pragma once
#include "Data.h"

class PostProcessing {
public:
	PostProcessing();
	virtual Data *process(Data *input) = 0;
	virtual ~PostProcessing();
};