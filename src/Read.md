# Description
This C++ application is a simple implementation of a Hospital Management System.

# Dependencies
- GLFW Library
- ImGui Library (C++ GUI)

# Design Patterns
For the sake of simplicity this design pattern is implemented in fully in the *Main.cpp* file.

![Class Diagram with Patterns drawio](https://user-images.githubusercontent.com/69485266/206863499-85a72b3d-5c2c-4210-9389-8f6008cf6c1e.png)

Following the above diagram we will implement a Factory Method on the Doctor class in order to allow the On Call Doctor class as well as the Regular Doctor class to get each of their salaries. The regular doctor will get a monthly salary and the on call doctor will get a salary per call.

# Code
![Snap (1)](https://user-images.githubusercontent.com/69485266/206863884-1d859d4c-d11a-41e9-b6fd-f0b2ed9e6d53.png)

In the obove Implimentation we gave the regular doctor a salary of 8000 and the on call doctor a salary of 300 per call, so that's what we expect to be outputted when we decide to use the creator get the salary.

# Regular Doctor & On Call Doctor Object Instantiation 
![Snap (3)](https://user-images.githubusercontent.com/69485266/206864057-b5e14868-0d20-4a52-8ce7-0caeaae826ac.png)

# Output
![Screenshot_3](https://user-images.githubusercontent.com/69485266/206864155-b26f1ef8-e7b5-448e-8cbf-28da5dd21bbf.png)

As show the salary displayed is the salary of the regular doctor and it's followed by the on calls.
