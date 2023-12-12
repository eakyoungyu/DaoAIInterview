#include "PostProcessingPipeline.h"

void PostProcessingPipeline::addProcess(PostProcessing *process) {
	pipeline.push_back(process);
}

Data *PostProcessingPipeline::process(Data *input) {
	this->input = input;
	for (PostProcessing* process : pipeline) 
	{
		this->input = process->process(this->input);
	}

	return this->input;
}

Data *PostProcessingPipeline::process() {
	return process(this->input);
}

void PostProcessingPipeline::setInput(Data *input) {
	this->input = input;
}

PostProcessingPipeline::~PostProcessingPipeline() {
	for (PostProcessing* process : pipeline) {
		delete process;
	}
}