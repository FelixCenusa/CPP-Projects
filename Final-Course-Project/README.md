### School Management System

#### Developers:
- **Felix Beniamin Cenusa**
- **Senai Amanuel Tewoldmedhin**

#### Project Overview:
- A school database system that stores information about a school (people and classes).
- Features:
  - Menu
  - Save to file
  - Load from file

#### Key Requirements and Features:

1. **Classes and Objects:**
   - **7 Classes Implemented:**
     - People, Student, Teacher, Staff, and others.
   - **Multiple Objects:**
     - Instances of People, Student, Teacher, and Staff are created.

2. **Inheritance and Abstraction:**
   - **Logical and Reasonable Inheritance:**
     - Use of abstract classes for logical structure.
   
3. **Polymorphism and Dynamic Binding:**
   - **Method Overriding and Dynamic Binding:**
     - Example: `DisplayInfo` method in Teacher, Student, and Staff classes.

4. **Dynamic Memory Management:**
   - **Handler Classes:**
     - PeopleHandler manages dynamic memory.

5. **File Operations:**
   - **Reading and Writing to Text Files:**
     - PeopleHandler and ClassHandler can save and load all objects to/from files.
     - Implemented in two different ways.

#### Interesting Implementation:
- **Two different methods for loading and saving data.**

#### Detailed Requirements Verification:
- **Classes:**
  - More than 5 custom-defined relevant classes, approved by the teacher.
  - Objects of these classes are handled using containers (arrays, vectors).
- **Inheritance:**
  - Logical and reasonable inheritance with abstract classes.
- **Polymorphism:**
  - Multiple instances of dynamic binding.
  - Example function in the abstract class `Person` that is overridden in subclasses.
- **Dynamic Memory:**
  - Use of dynamic arrays, unique pointers, and a vector.
- **Data Structures:**
  - Standard library data structures like vectors used.
- **File Handling:**
  - Multiple methods for reading and writing to text files.
- **Memory Management:**
  - All allocated memory is freed upon program termination.
- **Program Stability:**
  - The program is designed not to crash or freeze.

#### Conclusion:
The project meets all the specified requirements for the CPP course, demonstrating comprehensive use of classes, inheritance, polymorphism, dynamic memory management, standard data structures, and file operations.
