# DaoAIInterview
### Class Diagram
#### Composite Pattern
- Handle postprocessing and pipeline
- The additional operators(%) can be added by inheriting "PostProcessing"
- The "PostProcessing" and "PostProcessingPipeline" classes offer reusability in the image pipeline.
![UML class (1)](https://github.com/eakyoungyu/DaoAIInterview/assets/39245582/7530a3ee-c219-4618-b9bb-f176b24da1be)

#### Factory Pattern
- Create operator classes (Add, Subtract, Multiply, Division) in "OperatorFactory", not in main.cpp
![UML class (2)](https://github.com/eakyoungyu/DaoAIInterview/assets/39245582/f8ba2aee-6012-4cb5-9382-6f4cad90208d)
