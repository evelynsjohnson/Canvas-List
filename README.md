# Canvas-List Project

By the end of the project, the goal is to:
- Gain an understanding of the usage of a linked list in data structures
- Have practiced manipulating a linked list in various ways
- Understand the power of polymorphism in an object-oriented language

CanvasList:
- Implemented methods in canvaslist.cpp such as size, front, push, find, insert, pop, remove, etc.

Other Shapes:
- Implemented derived classes Rect, Circle, and RightTriangle, taking advantage of polymorphism.
- Set member variables not given as arguments in a derived class's constructor to 0.

Testing:
- Wrote multiple tests for CanvasList in canvaslist_tests.cpp, following the documentation in canvaslist.h.
- Wrote tests to insert Rect, Circle, and RightTriangle instances into CanvasList. Ensured the CanvasList works seamlessly with these new shapes.
- Used EXPECT_EQ to write test cases, ran the testing suite with makefile commands, checking the validity of them using make run_tests and make run_solution_tests.
  
