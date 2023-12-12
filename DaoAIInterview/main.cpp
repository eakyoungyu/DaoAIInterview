#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <stack>
#include <memory>
#include "PostProcessingPipeline.h"
#include "OperatorFactory.h"
#include "FloatingNumber.h"
#include <windows.h>
using namespace std;

string defaultExpression = "( ( x + 1 ) * 2 – x / 3 ) / x";


bool isOperator(string str) {
    return (str == "+" || str == "-" || str == "*" || str == "/");
}

int precedence(string c) {
    if (c == "/" || c == "*") {
        return 2;
    }
    else if (c == "+" || c == "-") {
        return 1;
    }
    else {
        return 0;
    }
}

OperatorFactory::operators strToOperator(string str) {
    if (str == "+")
        return OperatorFactory::ADD;
    if (str == "-")
        return OperatorFactory::SUBTRACT;
    if (str == "*")
        return OperatorFactory::MULTIPLY;
    if (str == "/")
        return OperatorFactory::DIVISION;
}

void calculateExpression(vector<string>& postfixExpression) {
    stack<FloatingNumber*> numbers;
    OperatorFactory operatorFactory;

    for (string str : postfixExpression) {
        if (isOperator(str)) {
            FloatingNumber* rightOperand = numbers.top();
            numbers.pop();
            FloatingNumber* leftOperand = numbers.top();
            numbers.pop();

            PostProcessing* postProcessingOperator = operatorFactory.createOperatorWithFloatingNumber(strToOperator(str), rightOperand);
            FloatingNumber* result = (FloatingNumber*)postProcessingOperator->process(leftOperand);

            numbers.push(result);
        }
        else {
            FloatingNumber* number = new FloatingNumber(stod(str));
            numbers.push(number);
        }
    }

    FloatingNumber* result = numbers.top();
    numbers.pop();

    cout << "Result of custom expression: " << result->getData() << "\n";
    delete result;
}

void buildDynamicPipeline(string expression, double x) {
    vector<string> postfixExpression;
    stack<string> operators;
    "( ( x + 1 ) * 2 – x / 3 ) / x";

    istringstream iss(expression);
    string buffer;
    vector<string> splitedExpression;

    while (getline(iss, buffer, ' ')) {
        splitedExpression.push_back(buffer);
    }

    for (string curOpr : splitedExpression) {

        if (curOpr == "(") {
            operators.push(curOpr);
        }
        else if (curOpr == ")") {
            bool find = false;
            while (!operators.empty()) {
                string topOpr = operators.top();
                if (topOpr == "(") {
                    find = true;
                    operators.pop();
                    break;
                }
                postfixExpression.push_back(topOpr);
                operators.pop();
            }
            if (!find)
                throw runtime_error("Invalid expression");
        }
        else if (isOperator(curOpr)) {
            if (!operators.empty()) {
                string topOpr = operators.top();
                if (precedence(topOpr) >= precedence(curOpr)) {
                    postfixExpression.push_back(topOpr);
                    operators.pop();
                }
            }
            operators.push(curOpr);
        }
        else if (curOpr == "x") {
            postfixExpression.push_back(to_string(x));
        }
        else { // floating number
            postfixExpression.push_back(curOpr);
        }
    }
    
    while (!operators.empty()) {
        postfixExpression.push_back(operators.top());
        operators.pop();
    }

    //for (auto exp : postfixExpression) {
    //    cout << exp << endl;
    //}

    calculateExpression(postfixExpression);
}

void buildStaticPipeline(double x) {
    OperatorFactory operatorFactory;

    std::unique_ptr<PostProcessingPipeline> pipeline1(new PostProcessingPipeline);
    std::unique_ptr<PostProcessingPipeline> pipeline2(new PostProcessingPipeline);
    std::unique_ptr<PostProcessingPipeline> pipeline3(new PostProcessingPipeline);

    try {
        pipeline1->setInput(new FloatingNumber(x));
        pipeline1->addProcess(operatorFactory.createOperatorWithOperand(OperatorFactory::ADD, 1));
        pipeline1->addProcess(operatorFactory.createOperatorWithOperand(OperatorFactory::MULTIPLY, 2));
        FloatingNumber* pipeline1_result = (FloatingNumber*)pipeline1->process();

        pipeline2->setInput(new FloatingNumber(x));
        pipeline2->addProcess(operatorFactory.createOperatorWithOperand(OperatorFactory::DIVISION, 3));
        FloatingNumber* pipeline2_result = (FloatingNumber*)pipeline2->process();


        pipeline3->setInput(pipeline1_result);
        pipeline3->addProcess(operatorFactory.createOperatorWithFloatingNumber(OperatorFactory::SUBTRACT, pipeline2_result));
        pipeline3->addProcess(operatorFactory.createOperatorWithOperand(OperatorFactory::DIVISION, x));
        FloatingNumber* result = (FloatingNumber*)pipeline3->process();

        cout << "Result: " << result->getData() << std::endl;
    } catch (std::exception& e) {
        cout << "Error: " << e.what() << "\n";
    }
}

int main()
{
    double x;
    int option;

    try {
        cout << "Enter a floating-point input x: ";
        if (!(cin >> x)) {
            throw runtime_error("Invalid x: x is not a floating-point number");
        }

        cout << "1. Use default expression: " << '\n';
        cout << "2. Use custom expression (Please add a space between operator and operand)" << '\n';
        cout << "Select mathemetical expression to calculate: ";
        if (!(cin >> option)) {
            throw runtime_error("Invalid option: option is not an integer");
        }
        if (option != 1 && option != 2) {
            throw runtime_error("Invalid option: option shoud be 1 or 2");
        }

        if (option == 1) {
            buildStaticPipeline(x);
        }
        else {
            cout << "e.g. 1 - ( 4 + 5 )\n";
            string expression;
            cin.ignore();
            getline(cin, expression);

            buildDynamicPipeline(expression, x);
        }
    }
    catch (std::exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    //double res = ((x + 1) * 2 - x / 3) / x;

    //cout << res << std::endl;


    system("pause");
    return 0;
}
