
#include <iostream>    
using namespace std;   
//  Declaration of class Point
// class Point represents a two-dimensional point
//creating class
class Point
{
public:
  // default class constructor (with no arguments):
  Point(); 
  // class constructor that sets the coordinates x, y to the values xval,
  // yval:
  Point(int xval, int yval);
  // member function for moving a point by dx, dy:
  void Move(int dx, int dy);
  // member functions for getting values of x, y:
  int Get_X() const;
  int Get_Y() const;
  // member functions for setting x, y to xval, yval respectively  
  void Set_X(int xval);
  void Set_Y(int yval);
//Lab 7 exercise 4.1. Add declaration of member function Print here:
  void print();
// private data members x, y represent coordinates of the point:
private:
  int X;
  int Y;
};  
// class constructor sets X, Y to zero when no values are specified:
Point::Point()
{
  X = 0;
  Y = 0;
}
// class constructor sets X, Y to given values xval, yval:
Point::Point(int xval, int yval)
{
  X = xval;
  Y = yval;
}
// member function Move: increases the x coordinate by dx and the y
// coordinate by dy.
void Point::Move(int dx, int dy)
{
  X += dx;
  Y += dy;
}
// Get_X returns the value of the X coordinate
int Point::Get_X() const
{
  return X;
}
// Get_Y returns the value of the Y coordinate
int Point::Get_Y() const
{
  return Y;
}
// Set_X sets the value of X coordinate to xval
void Point::Set_X(int xval)
{
  X = xval;
} 
// Set_Y sets the value of Y coordinate to yval
void Point::Set_Y(int yval)
{
  Y = yval;
} 
    
//Lab 7 exercise 4.1. Add definition of member function print:
void Point::print()    
{
  cout<<"("<<X<<","<<Y<<")"<<endl;
}
//Lab 7 exercise 4.2, 4.3: Add class Rectangle declaration HERE: 
class Rectangle: public Point
{
 Point p1, p2, p3, p4;
 public:
 Rectangle(Point,Point);         
 Rectangle();                    
 private:
 int side1();                      
 int side2();
 public:
 int area();                      
 int l1,l2;                        
 int my_side1();                     
 int my_side2();	                     		
};
//Lab 7 exercise 4.2, 4.3. Add class Rectangle methods HERE:
Rectangle::Rectangle()
{
 p1.Set_X(0);
 p1.Set_Y(0);
 p2.Set_X(0); 
 p2.Set_Y(1);
 p3.Set_X(1);
 p3.Set_Y(1);
 p4.Set_X(1);
 p4.Set_Y(0);
//display the points
 cout<<"The coordinates are:\n";
 cout<<"First point:"<<endl;
 p1.print();
 cout<<endl<<"Second point:"<<endl;
 p2.print();
 cout<<endl<<"Third point:"<<endl;
 p3.print();
 cout<<endl<<"Fourth point:"<<endl;
 p4.print();
 cout<<endl;
} 
Rectangle::Rectangle(Point a, Point b)
{
 p1 = a;
 p3 = b;
 p2.Set_X(p1.Get_X());
 p2.Set_Y(p3.Get_Y());
 p4.Set_X(p3.Get_X());
 p4.Set_Y(p1.Get_Y());
 cout<<"Coordinates of first point: "<<endl;
 p1.print();
 cout<<endl;
 cout<<"Coordinates of second point: "<<endl;
 p2.print();
 cout<<endl;
 cout<<"Coordinates of third point: "<<endl;
 p3.print();
 cout<<endl;
 cout<<"Coordinates of fourth point: "<<endl;
 p4.print();
 cout<<endl;
}
int Rectangle::side1()                   
{
 l1 = p2.Get_Y() - p1.Get_Y();
}
int Rectangle::side2()             
{
 l2 = p4.Get_X() - p1.Get_X();
}
int Rectangle::area()						 
{
 return l1*l2;
}
int Rectangle::my_side1()
{
 side1();
 return l1;	
}
int Rectangle::my_side2()
{
 side2();
 return l2;	
}
// main function
int main()
{
 Point po1;
 cout<< "The coordinates of po1 are: ";
 po1.print();
 cout<<endl;
 Point po2(2, 3);
 cout<< "The coordinates of po2 are: ";
 po2.print();
 po2.Move(1, -1);
 cout<< "After the move:" << endl;
 cout<< "The x value for po2 is " << po2.Get_X() << endl;
 cout<< "The y value for po2 is " << po2.Get_Y() << endl;
 cout<< "The coordinates are ";
 po2.print();
//stores coordinates for 2 points by which a rectangle will be done
  int xval,yval;                                                   
  cout<<"Enter coordinates of 1st point"<<endl;
  cout<<"Enter x coordinate: "<<endl;
  cin>>xval;
  cout<<"Enter y coordinate: "<<endl;
  Point p1(xval,yval);
  cout<<endl;
  cout<<"Enter coordinates of 2nd point"<<endl;
  cout<<"Enter x coordinate: "<<endl;
  cin>>xval;
  cout<<"Enter y coordinate: "<<endl;
  cin>>yval;
  Point p3(xval,yval);
 //Lab 7 Exercises 4.2, 4.3. Testing of the class Rectangle goes here: 
 cout<<"Rectangle ob1:"<<endl;
 Rectangle ob1;
 cout<<"Rectangle ob2:"<<endl;
 Rectangle ob2(p1,p3);
 cout<<"The sides of the rectangle are: \n";
 cout<<ob2.my_side1()<<" & "<<ob2.my_side2()<<endl;
 //displays the area of the rectangle
 cout<<"The area of the rectangle: "<<ob2.area();
 //return 0
  return 0;
}