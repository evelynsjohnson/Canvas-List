#include <gtest/gtest.h>

#include "canvaslist.h"
#include "shape.h"

/*
  Testing Shape
*/
TEST(ShapeTest, DefaultConstructor) {
  Shape shape;
  EXPECT_EQ(shape.getX(), 0);
  EXPECT_EQ(shape.getY(), 0);
  EXPECT_EQ(shape.as_string(), "It's a Shape at x: 0, y: 0");
}

TEST(ShapeTest, ParameterizedConstructor) {
  Shape shape(1, 2);
  EXPECT_EQ(shape.getX(), 1);
  EXPECT_EQ(shape.getY(), 2);
  EXPECT_EQ(shape.as_string(), "It's a Shape at x: 1, y: 2");
}

TEST(ShapeTest, CopyConstructor) {
  Shape shape(1, 2);
  Shape* copied = shape.copy();
  EXPECT_EQ(copied->getX(), 1);
  EXPECT_EQ(copied->getY(), 2);
  EXPECT_EQ(copied->as_string(), "It's a Shape at x: 1, y: 2");
  delete copied;
}

TEST(ShapeTest, NegativeValues) {
  // Testing with default constructor
  Shape shape1(-1, -2);
  EXPECT_EQ(shape1.getX(), -1);
  EXPECT_EQ(shape1.getY(), -2);

  // Testing with set() functions
  Shape shape2;
  shape2.setX(-1);
  shape2.setY(-2);
  EXPECT_EQ(shape2.getX(), -1);
  EXPECT_EQ(shape2.getY(), -2);
}


/*
  Testing Circle
*/
TEST(CircleTest, DefaultConstructor) {
  Circle circle;
  EXPECT_EQ(circle.getX(), 0);
  EXPECT_EQ(circle.getY(), 0);
  EXPECT_EQ(circle.getRadius(), 0);
  EXPECT_EQ(circle.as_string(), "It's a Circle at x: 0, y: 0, radius: 0");
}

TEST(CircleTest, ParameterizedConstructor) {
  // Testing with 1 input for radius
  Circle circle1(1);
  EXPECT_EQ(circle1.getX(), 0);
  EXPECT_EQ(circle1.getY(), 0);
  EXPECT_EQ(circle1.getRadius(), 1);
  EXPECT_EQ(circle1.as_string(), "It's a Circle at x: 0, y: 0, radius: 1");

  // Testing with all 3 inputs
  Circle circle2(1, 2, 3);
  EXPECT_EQ(circle2.getX(), 1);
  EXPECT_EQ(circle2.getY(), 2);
  EXPECT_EQ(circle2.getRadius(), 3);
  EXPECT_EQ(circle2.as_string(), "It's a Circle at x: 1, y: 2, radius: 3");
}

TEST(CircleTest, CopyConstructor) {
  Circle circle(1, 2, 3);
  Circle* copied = circle.copy();
  EXPECT_EQ(copied->getX(), 1);
  EXPECT_EQ(copied->getY(), 2);
  EXPECT_EQ(copied->getRadius(), 3);
  EXPECT_EQ(copied->as_string(), "It's a Circle at x: 1, y: 2, radius: 3");
  delete copied;
}

TEST(CircleTest, NegativeValues) {
  // Testing with default constructor
  Circle circle1(-1);
  EXPECT_EQ(circle1.getRadius(), -1);

  // Testing with set() function
  Circle circle2;
  circle2.setRadius(-1);
  EXPECT_EQ(circle2.getRadius(), -1);
}


/*
  Testing Rectangle
*/
TEST(RectTest, DefaultConstructor) {
  Rect rect;
  EXPECT_EQ(rect.getX(), 0);
  EXPECT_EQ(rect.getY(), 0);
  EXPECT_EQ(rect.getWidth(), 0);
  EXPECT_EQ(rect.getHeight(), 0);
  EXPECT_EQ(rect.as_string(), "It's a Rectangle at x: 0, y: 0 with width: 0 and height: 0");
}

TEST(RectTest, ParameterizedConstructor) {
  // Testing with 2 inputs for b and h
  Rect rect1(1, 2);
  EXPECT_EQ(rect1.getX(), 0);
  EXPECT_EQ(rect1.getY(), 0);
  EXPECT_EQ(rect1.getWidth(), 1);
  EXPECT_EQ(rect1.getHeight(), 2);
  EXPECT_EQ(rect1.as_string(), "It's a Rectangle at x: 0, y: 0 with width: 1 and height: 2");

  // Testing with all 4 inputs
  Rect rect2(1, 2, 3, 4);
  EXPECT_EQ(rect2.getX(), 1);
  EXPECT_EQ(rect2.getY(), 2);
  EXPECT_EQ(rect2.getWidth(), 3);
  EXPECT_EQ(rect2.getHeight(), 4);
  EXPECT_EQ(rect2.as_string(), "It's a Rectangle at x: 1, y: 2 with width: 3 and height: 4");
}

TEST(RectTest, CopyConstructor) {
  Rect rect(1, 2, 3, 4);
  Rect* copied = rect.copy();
  EXPECT_EQ(copied->getX(), 1);
  EXPECT_EQ(copied->getY(), 2);
  EXPECT_EQ(copied->getWidth(), 3);
  EXPECT_EQ(copied->getHeight(), 4);
  EXPECT_EQ(copied->as_string(), "It's a Rectangle at x: 1, y: 2 with width: 3 and height: 4");
  delete copied;
}

TEST(RectTest, NegativeValues) {
  // Testing with default constructor
  Rect rect1(-1, -2);
  EXPECT_EQ(rect1.getWidth(), -1);
  EXPECT_EQ(rect1.getHeight(), -2);

  // Testing with set() functions
  Rect rect2;
  rect2.setWidth(-1);
  rect2.setHeight(-2);
  EXPECT_EQ(rect2.getWidth(), -1);
  EXPECT_EQ(rect2.getHeight(), -2);
}


/*
  Testing RightTriangle
*/
TEST(RightTriangleTest, DefaultConstructor) {
  RightTriangle triangle;
  EXPECT_EQ(triangle.getX(), 0);
  EXPECT_EQ(triangle.getY(), 0);
  EXPECT_EQ(triangle.getBase(), 0);
  EXPECT_EQ(triangle.getHeight(), 0);
  EXPECT_EQ(triangle.as_string(), "It's a Right Triangle at x: 0, y: 0 with base: 0 and height: 0");
}

TEST(RightTriangleTest, ParameterizedConstructor) {
  // Testing with 2 inputs for b and h
  RightTriangle triangle1(1, 2);
  EXPECT_EQ(triangle1.getX(), 0);
  EXPECT_EQ(triangle1.getY(), 0);
  EXPECT_EQ(triangle1.getBase(), 1);
  EXPECT_EQ(triangle1.getHeight(), 2);
  EXPECT_EQ(triangle1.as_string(), "It's a Right Triangle at x: 0, y: 0 with base: 1 and height: 2");

  // Testing with all 4 inputs
  RightTriangle triangle2(1, 2, 3, 4);
  EXPECT_EQ(triangle2.getX(), 1);
  EXPECT_EQ(triangle2.getY(), 2);
  EXPECT_EQ(triangle2.getBase(), 3);
  EXPECT_EQ(triangle2.getHeight(), 4);
  EXPECT_EQ(triangle2.as_string(), "It's a Right Triangle at x: 1, y: 2 with base: 3 and height: 4");
}

TEST(RightTriangleTest, CopyConstructor) {
  RightTriangle original(1, 2, 3, 4);
  RightTriangle* copied = original.copy();
  EXPECT_EQ(copied->getX(), 1);
  EXPECT_EQ(copied->getY(), 2);
  EXPECT_EQ(copied->getBase(), 3);
  EXPECT_EQ(copied->getHeight(), 4);
  EXPECT_EQ(copied->as_string(), "It's a Right Triangle at x: 1, y: 2 with base: 3 and height: 4");
  delete copied;
}

TEST(RightTriangleTest, NegativeValues) {
  // Testing with default constructor
  RightTriangle triangle1(-1, -2);
  EXPECT_EQ(triangle1.getBase(), -1);
  EXPECT_EQ(triangle1.getHeight(), -2);

  // Testing with set() functions
  RightTriangle triangle2;
  triangle2.setBase(-1);
  triangle2.setHeight(-2);
  EXPECT_EQ(triangle2.getBase(), -1);
  EXPECT_EQ(triangle2.getHeight(), -2);
}

/*
  Testing Constructor
*/
TEST(Constructor, DefaultCanvasList) {
  CanvasList list;

  // Check initial state
  EXPECT_EQ(list.size(), 0);
  EXPECT_EQ(list.front(), nullptr);
}


/*
  Testing Copy constructor
*/
TEST(CopyConstructor, ThreeShapes) {
  CanvasList list;
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);
  CanvasList copy(list);

  EXPECT_EQ(copy.size(), list.size());
  EXPECT_NE(copy.front(), list.front()); // Addresses not the same (deep copy)
  list.clear();
}


/*
  Testing operator=
*/
TEST(OperatorEQ, SelfAssignment) {
  // Testing self assignment for empty list
  CanvasList emptyList;

  emptyList = emptyList;
  EXPECT_EQ(emptyList.size(), 0);
  EXPECT_EQ(emptyList.shape_at(0), nullptr);
  emptyList.clear();

  // Testing self assignment for non-empty list
  CanvasList nonEmptyList;
  Shape* shape = new Shape(1, 1);
  nonEmptyList.push_back(shape);

  nonEmptyList = nonEmptyList;
  EXPECT_EQ(nonEmptyList.size(), 1);
  EXPECT_EQ(nonEmptyList.shape_at(0)->as_string(), "It's a Shape at x: 1, y: 1");

  nonEmptyList.clear();
}

TEST(OperatorEQ, EmptyToNonEmpty) {
  CanvasList list;      // Non-Empty list
  CanvasList copyList;  // Empty list

  // List setup
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);
  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);

  copyList = list;
  EXPECT_EQ(copyList.size(), 3);
  
  EXPECT_EQ(copyList.shape_at(0)->as_string(), "It's a Shape at x: 0, y: 0");
  EXPECT_EQ(copyList.shape_at(1)->as_string(), "It's a Shape at x: 1, y: 1");
  EXPECT_EQ(copyList.shape_at(2)->as_string(), "It's a Shape at x: 2, y: 2");

  copyList.clear();
  list.clear();
}

TEST(OperatorEQ, NonEmptyToEmpty) {
  CanvasList list;      // Empty list
  CanvasList copyList;  // Non-Empty list

  // List setup
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);
  copyList.push_back(shape1);
  copyList.push_back(shape2);
  copyList.push_back(shape3);

  copyList = list;
  EXPECT_EQ(copyList.size(), 0);
  EXPECT_EQ(copyList.shape_at(0), nullptr);
  copyList.clear();
}

TEST(OperatorEQ, NonEmptyToNonEmpty) {
  // Lists/Shapes setup
  CanvasList list;
  CanvasList copyList;
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  list.push_back(shape1);
  list.push_back(shape2);

  copyList.push_back(shape3);

  copyList = list;
  EXPECT_EQ(copyList.size(), 2);

  EXPECT_EQ(copyList.shape_at(0)->as_string(), "It's a Shape at x: 0, y: 0");
  EXPECT_EQ(copyList.shape_at(1)->as_string(), "It's a Shape at x: 1, y: 1");
  
  list.clear();
  copyList.clear();
}


/*
  Testing insert_after
*/
TEST(InsertAfter, DefaultInsert) {
  CanvasList list;
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  list.push_back(shape1);
  list.push_back(shape2);

  list.insert_after(0, shape3);

  EXPECT_EQ(list.size(), 3);

  EXPECT_EQ(list.shape_at(0), shape1);
  EXPECT_EQ(list.shape_at(0)->as_string(), "It's a Shape at x: 0, y: 0");

  EXPECT_EQ(list.shape_at(1), shape3);
  EXPECT_EQ(list.shape_at(1)->as_string(), "It's a Shape at x: 2, y: 2");
  
  EXPECT_EQ(list.shape_at(2), shape2);
  EXPECT_EQ(list.shape_at(2)->as_string(), "It's a Shape at x: 1, y: 1");
  list.clear();
}

TEST(InsertAfter, EmptyList) {
  CanvasList list;
  Shape* shape = new Shape(1, 2);
  list.insert_after(0, shape);

  // Check that the CanvasList remains empty
  EXPECT_EQ(list.size(), 0);
  EXPECT_EQ(list.shape_at(0), nullptr);

  list.clear();
  delete shape;
}

TEST(InsertAfter, InsertMultiple) {
  CanvasList list;
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);
  list.push_back(shape1);

  // Insert multiple times at index 0
  list.insert_after(0, shape2);
  list.insert_after(0, shape3);

  EXPECT_EQ(list.size(), 3);
  EXPECT_EQ(list.shape_at(0), shape1);
  EXPECT_EQ(list.shape_at(0)->as_string(), "It's a Shape at x: 0, y: 0");

  EXPECT_EQ(list.shape_at(1), shape3);
  EXPECT_EQ(list.shape_at(1)->as_string(), "It's a Shape at x: 2, y: 2");
  
  EXPECT_EQ(list.shape_at(2), shape2);
  EXPECT_EQ(list.shape_at(2)->as_string(), "It's a Shape at x: 1, y: 1");
  list.clear();
}

TEST(InsertAfter, LastIndex) {
  CanvasList list;
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  list.push_back(shape1);

  list.insert_after(0, shape2);

  EXPECT_EQ(list.size(), 2);

  EXPECT_EQ(list.shape_at(0), shape1);
  EXPECT_EQ(list.shape_at(0)->as_string(), "It's a Shape at x: 0, y: 0");

  EXPECT_EQ(list.shape_at(1), shape2);
  EXPECT_EQ(list.shape_at(1)->as_string(), "It's a Shape at x: 1, y: 1");
  list.clear();
}

TEST(InsertAfter, InvalidIndex) {
  CanvasList list;
  Shape* shape1 = new Shape(1, 2);
  list.push_back(shape1);

  // Attempt to insert after an invalid index
  Shape* shape2 = new Shape(3, 4);
  list.insert_after(2, shape2);
  list.insert_after(-1, shape2);

  // Check that the CanvasList remains unchanged
  EXPECT_EQ(list.size(), 1);

  EXPECT_EQ(list.shape_at(0), shape1);
  EXPECT_EQ(list.shape_at(0)->as_string(), "It's a Shape at x: 1, y: 2");

  EXPECT_EQ(list.shape_at(1), nullptr);
  list.clear();
  delete shape2;
}


/*
  Testing pushes
*/
TEST(PushFront, PushFrontTests) {
  CanvasList list;

  // Test one shape pushed
  Shape* shape1 = new Shape();
  list.push_front(shape1);

  EXPECT_EQ(list.front()->value, shape1);
  EXPECT_EQ(list.front()->next, nullptr);
  EXPECT_EQ(list.size(), 1);

  // Test two shapes pushed total
  Shape* shape2 = new Shape(1, 1);
  list.push_front(shape2);
  EXPECT_EQ(list.front()->value, shape2);
  EXPECT_EQ(list.size(), 2);

  // Test three shapes pushed total
  Shape* shape3 = new Shape(2, 2);
  list.push_front(shape3);
  EXPECT_EQ(list.front()->value, shape3);
  EXPECT_EQ(list.size(), 3);
  list.clear();
}

TEST(PushBack, PushBackTests) {
  CanvasList list;

  // Test one shape pushed
  Shape* shape1 = new Shape();
  list.push_back(shape1);
  EXPECT_EQ(list.front()->value, shape1);
  EXPECT_EQ(list.front()->next, nullptr);
  EXPECT_EQ(list.size(), 1);
  
  // Test two shapes pushed total
  Shape* shape2 = new Shape(1, 1);
  list.push_back(shape2);
  EXPECT_EQ(list.front()->next->value, shape2);
  EXPECT_EQ(list.size(), 2);

  Shape* shape3 = new Shape(2, 2);
  list.push_back(shape3);
  EXPECT_EQ(list.front()->next->next->value, shape3);
  EXPECT_EQ(list.size(), 3);
  list.clear();
}


/*
  Testing remove_after
*/
TEST(RemoveAt, EmptyList) {
  CanvasList list;

  // Attempt to remove from an empty list
  list.remove_at(0);

  // Check that the CanvasList remains unchanged
  EXPECT_EQ(list.size(), 0);
}

TEST(RemoveAt, FirstElement) {
  CanvasList list;
  list.push_back(new Shape(1, 2));
  list.push_back(new Shape(3, 4));

  list.remove_at(0);

  EXPECT_EQ(list.size(), 1);
  list.clear();
}

TEST(RemoveAt, LastElement) {
  CanvasList list;
  list.push_back(new Shape(1, 2));
  list.push_back(new Shape(3, 4));

  list.remove_at(1);

  EXPECT_EQ(list.size(), 1);
  list.clear();
}

TEST(RemoveAt, InvalidIndex) {
  CanvasList list;
  list.push_back(new Shape(1, 2));
  list.push_back(new Shape(3, 4));

  list.remove_at(2);

  // Check that the CanvasList remains unchanged
  EXPECT_EQ(list.size(), 2);
  list.clear();
}


/*
  Testing remove_every_other
*/
TEST(RemoveEveryOther, EmptyList) {
  CanvasList list;
  list.remove_every_other();

  EXPECT_EQ(list.size(), 0);
}

TEST(RemoveEveryOther, OneShapeList) {
  CanvasList list;
  list.push_back(new Shape(1, 2));
  list.remove_every_other();

  // Check that the CanvasList remains unchanged
  EXPECT_EQ(list.size(), 1);
  list.clear();
}

TEST(RemoveEveryOther, TwoShapeList) {
  CanvasList list;
  list.push_back(new Shape(1, 2));
  list.push_back(new Shape(3, 4));

  list.remove_every_other();

  // Check that the CanvasList contains only the first element
  EXPECT_EQ(list.size(), 1);
  list.clear();
}

TEST(RemoveEveryOther, ThreeShapeList) {
  CanvasList list;
  list.push_back(new Shape(1, 2));
  list.push_back(new Shape(3, 4));
  list.push_back(new Shape(5, 6));

  list.remove_every_other();

  // Check that the CanvasList contains only the first and third elements
  EXPECT_EQ(list.size(), 2);
  list.clear();
}


/*
  Testing pops
*/
TEST(PopFront, PopFrontEmpty) {
  CanvasList list;
  Shape* removedShape = list.pop_front();
  EXPECT_EQ(removedShape, nullptr);
  EXPECT_EQ(list.size(), 0);
  delete removedShape;
}

TEST(PopFront, PopFrontOne) {
  Shape* s1 = new Shape(1, 2);
  CanvasList list;
  list.push_front(s1);
  Shape* removedShape = list.pop_front();
  EXPECT_EQ(removedShape, s1);
  EXPECT_EQ(list.size(), 0);
  EXPECT_EQ(list.front(), nullptr);
  delete removedShape;
}

TEST(PopFront, PopFrontMultiple) {
  Shape* s1 = new Shape(1, 2);
  Shape* s2 = new Shape(3, 4);
  Shape* s3 = new Shape(5, 6);
  CanvasList list;
  list.push_front(s3);
  list.push_front(s2);
  list.push_front(s1);

  Shape* removedShape1 = list.pop_front();
  EXPECT_EQ(removedShape1, s1);
  EXPECT_EQ(list.size(), 2);
  EXPECT_EQ(list.front()->value, s2);

  Shape* removedShape2 = list.pop_front();
  EXPECT_EQ(removedShape2, s2);
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front()->value, s3);
  list.clear();
  delete removedShape1;
  delete removedShape2;
}

TEST(PopBack, PopBackEmpty) {
  CanvasList list;
  Shape* removedShape = list.pop_back();
  EXPECT_EQ(removedShape, nullptr);
  EXPECT_EQ(list.size(), 0);
  delete removedShape;
}

TEST(PopBack, PopBackOne) {
  Shape* s1 = new Shape(1, 2);
  CanvasList list;
  list.push_front(s1);
  Shape* removedShape = list.pop_back();

  EXPECT_EQ(removedShape, s1);
  EXPECT_EQ(list.size(), 0);
  EXPECT_EQ(list.front(), nullptr);

  delete removedShape;
}

TEST(PopBack, PopBackMultiple) {
  Shape* s1 = new Shape(1, 2);
  Shape* s2 = new Shape(3, 4);
  Shape* s3 = new Shape(5, 6);
  CanvasList list;
  list.push_front(s1);
  list.push_front(s2);
  list.push_front(s3);

  Shape* removedShape1 = list.pop_back();
  EXPECT_EQ(removedShape1, s1);
  EXPECT_EQ(list.size(), 2);

  Shape* removedShape2 = list.pop_back();
  EXPECT_EQ(removedShape2, s2);
  EXPECT_EQ(list.size(), 1);
  EXPECT_EQ(list.front()->value, s3);
  list.clear();
  delete removedShape1;
  delete removedShape2;
}


/*
  Testing empty
*/
TEST(Empty, EmptyTests) {
  CanvasList list;
  EXPECT_EQ(list.empty(), true);

  Shape* shape1 = new Shape();
  list.push_front(shape1);
  EXPECT_EQ(list.empty(), false);
  list.clear();
}


/*
  Testing size
*/
TEST(Size, SizeTests) {
  CanvasList list;
  EXPECT_EQ(list.size(), 0);

  Shape* shape1 = new Shape();
  list.push_front(shape1);
  EXPECT_EQ(list.size(), 1);
  list.clear();
}


/*
  Testing find
*/
TEST(Find, FindExistingShape) {
  CanvasList list;
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);

  int index = list.find(1, 1);
  EXPECT_EQ(index, 1);
  list.clear();
}

TEST(Find, FindNonExistingShape) {
  CanvasList list;
  Shape* shape1 = new Shape(0, 0);
  Shape* shape2 = new Shape(1, 1);
  Shape* shape3 = new Shape(2, 2);

  list.push_back(shape1);
  list.push_back(shape2);
  list.push_back(shape3);

  // Test finding a non-existing shape
  int index = list.find(3, 3);

  // Expect the index to be -1 since no shape has coordinates (3, 3)
  EXPECT_EQ(index, -1);
  list.clear();
}


/*
  Testing shape_at
*/
TEST(ShapeAt, EmptyList) {
  CanvasList list;
  Shape* result = list.shape_at(0);

  EXPECT_EQ(result, nullptr);
  delete result;
}

TEST(ShapeAt, OneShape) {
  CanvasList list;
  list.push_back(new Shape(1, 2));

  Shape* result = list.shape_at(0);

  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->getX(), 1);
  EXPECT_EQ(result->getY(), 2);
  list.clear();
}

TEST(ShapeAt, MultiShape) {
  CanvasList list;
  list.push_back(new Shape(1, 2));
  list.push_back(new Shape(3, 4));
  list.push_back(new Shape(5, 6));

  Shape* result = list.shape_at(1);

  EXPECT_NE(result, nullptr);
  EXPECT_EQ(result->getX(), 3);
  EXPECT_EQ(result->getY(), 4);
  list.clear();
}

TEST(ShapeAt, InvalidIndex) {
  CanvasList list;
  list.push_back(new Shape(1, 2));
  list.push_back(new Shape(3, 4));

  Shape* result = list.shape_at(2);
  EXPECT_EQ(result, nullptr);
  
  // Test for negative invalid index too
  result = list.shape_at(-1);
  EXPECT_EQ(result, nullptr);

  list.clear();
}