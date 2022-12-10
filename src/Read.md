# Description
This C++ application is a simple implementation of a Hospital Management System.

# Dependencies
- GLFW Library
- ImGui Library (C++ GUI)

#Design Patterns
For the sake of simplicity this design pattern is implemented in fully in the *Main.cpp* file.

![Class Diagram with Patterns drawio](https://user-images.githubusercontent.com/69485266/206863499-85a72b3d-5c2c-4210-9389-8f6008cf6c1e.png)

Following the above diagram we will implement a Factory Method on the Doctor class in order to allow the On Call Doctor class as well as the Regular Doctor class to get each of their salaries. The regular doctor will get a monthly salary and the on call doctor will get a salary per call.
