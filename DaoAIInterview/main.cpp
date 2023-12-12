#include <iostream>
#include <stdexcept>
#include <string>
#include "PostProcessingPipeline.h"
#include "OperatorFactory.h"
#include "FloatingNumber.h"
using namespace std;

string defaultExpression = "((x + 1) * 2 – x / 3) / x";

int main()
{
    double x;

    cout << "Enter a floating-point input x: ";

    OperatorFactory operatorFactory;

    PostProcessingPipeline* pipeline1 = new PostProcessingPipeline();
    PostProcessingPipeline* pipeline2 = new PostProcessingPipeline();
    PostProcessingPipeline* pipeline3 = new PostProcessingPipeline();

    try {

        if (!(cin >> x)) {
            throw runtime_error("Input x is not a floating-point number");
        }

        pipeline1->setInput(new FloatingNumber(x));
        pipeline1->addProcess(operatorFactory.createOperatorWithOperand(OperatorFactory::ADD, 1));
        pipeline1->addProcess(operatorFactory.createOperatorWithOperand(OperatorFactory::MULTIPLY, 2));
        FloatingNumber *pipeline1_result = (FloatingNumber *)pipeline1->process();
         
        pipeline2->setInput(new FloatingNumber(x));
        pipeline2->addProcess(operatorFactory.createOperatorWithOperand(OperatorFactory::DIVISION, 3));
        FloatingNumber *pipeline2_result = (FloatingNumber*)pipeline2->process();


        pipeline3->setInput(pipeline1_result);

        pipeline3->addProcess(operatorFactory.createOperatorWithFloatingNumber(OperatorFactory::SUBTRACT, pipeline2_result));
        pipeline3->addProcess(operatorFactory.createOperatorWithOperand(OperatorFactory::DIVISION, x));

        FloatingNumber* result = (FloatingNumber*)pipeline3->process();

        cout << "result: " << result->getData() << std::endl;

        //double res = ((x + 1) * 2 - x / 3) / x;

        //cout << res << std::endl;
        delete result;
    }
    catch (std::exception& e) {
        cout << "Error: " << e.what() << "\n";
    }


    delete pipeline1;
    delete pipeline2;
    delete pipeline3;

    return 0;
}
