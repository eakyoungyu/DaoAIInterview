#pragma once
#include "PostProcessing.h"
#include <vector>

class PostProcessingPipeline :public PostProcessing {
public:
	void addProcess(PostProcessing *opr);
	Data *process(Data *input);
	Data *process();
	void setInput(Data *input);
	~PostProcessingPipeline();

private:
	std::vector<PostProcessing *> pipeline;
	Data *input;
};

