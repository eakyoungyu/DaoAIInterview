# DaoAIInterview
### How to build
1. Download a project and open a solution file, DaoAIInterview.sln, in Visual Studio
2. Click Ctrl + F5 to build
### Test examples
#### 1. Default expression test: ((x + 1) * 2 – x / 3) / x.
   - Enter an input x
   - Enter "1" to use a default expression
```
Enter a floating-point input x: 1.1
1. Use default expression:
2. Use custom expression (Please add a space between operator and operand)
Select mathematical expression to calculate: 1
Result: 3.48485
```
#### 2. Custom expression test
   - Enter an input x
   - Enter "2" to use a custom expression
   - Enter mathematical expression including space between operators, operands, and braces.
   - valid expression: 1 + ( x * 1.2 ) / 3
   - invalid expression: 1 + (x*1.2) / 3
```
Enter a floating-point input x: 1.1
1. Use default expression:
2. Use custom expression (Please add a space between operator and operand)
Select mathematical expression to calculate: 2
e.g. 1 - ( 4 + 5 )
1 + ( x * 1.2 ) / 3
Result of custom expression: 1.44
```
### Class Diagram
#### Composite Pattern
- Handle postprocessing and pipeline
- The additional operators(%) can be added by inheriting "PostProcessing"
- The "PostProcessing" and "PostProcessingPipeline" classes offer reusability in the image pipeline.
![UML class (1)](https://github.com/eakyoungyu/DaoAIInterview/assets/39245582/7530a3ee-c219-4618-b9bb-f176b24da1be)

#### Factory Pattern
- Create operator classes (Add, Subtract, Multiply, Division) in "OperatorFactory", not in main.cpp
![UML class (2)](https://github.com/eakyoungyu/DaoAIInterview/assets/39245582/f8ba2aee-6012-4cb5-9382-6f4cad90208d)
