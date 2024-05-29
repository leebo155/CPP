# BSP
BSP stands for Binary Space Partitioning.

This exercise involves using the fixed-point class have written so far to create a function that can determine if a specific point is located inside a triangle.    

Use the shoelace formula to solve the problem. Calculate the areas of four triangles, and if the area of the largest triangle is equal to the sum of the areas of the other three triangles, determine that the point is inside the triangle.

## Rules
Start by creating the class **Point** in Orthodox Canonical Form that represents a 2D point:

* Private members:   
  ◦ A Fixed const attribute **x**.   
  ◦ A Fixed const attribute **y**.    
  ◦ Anything else useful.   

* Public members:   
  ◦ A default constructor that initializes x and y to 0.   
  ◦ A constructor that takes as parameters two constant floating-point numbers. It initializes x and y with those parameters.   
  ◦ A copy constructor.   
  ◦ A copy assignment operator overload.   
  ◦ A destructor.   
  ◦ Anything else useful.   

To conclude, implement the following function in the appropriate file:
```cpp
bool bsp( Point const a, Point const b, Point const c, Point const point);
```
* a, b, c: The vertices of our beloved triangle.

* point: The point to check.

* Returns: True if the point is inside the triangle. False otherwise.   
  Thus, if the point is a vertex or on edge, it will return False.

## Execution
```cpp
int main( void )
{
	Point a(2, -1);
	Point b(-4, 17);
	Point c(-12, 3);
	Point point( -11.6f, 2.9f);

	if (bsp(a, b, c, point))
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;
	return 0;
}
```
```
$> ./a.out
True
```
