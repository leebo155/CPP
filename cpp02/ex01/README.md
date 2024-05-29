# Towards a more useful fixed-point number class
In this exercise, we take the fixed-point class written in ex00 and extend it further. Through this process, learn about Ad-hoc polymorphism.

## Rules 
Add the following public constructors and public member functions to your class:   
* A constructor that takes a **constant integer** as a parameter.   
  It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.

* A constructor that takes a **constant floating-point number** as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.

* A member function _float toFloat( void ) const_;   
  that converts the fixed-point value to a floating-point value.

* A member function _int toInt( void ) const_;   
  that converts the fixed-point value to an integer value.

And add the following function to the **Fixed** class files:

* An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.

## Execution
  ```cpp
  int main( void ) {
  
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    
    a = Fixed( 1234.4321f );
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    
    return 0;

  }
  ```
  ```
  $> ./a.out
  Default constructor called
  Int constructor called
  Float constructor called
  Copy constructor called
  Copy assignment operator called
  Float constructor called
  Copy assignment operator called
  Destructor called
  a is 1234.43
  b is 10
  c is 42.4219
  d is 10
  a is 1234 as integer
  b is 10 as integer
  c is 42 as integer
  d is 10 as integer
  Destructor called
  Destructor called
  Destructor called
  Destructor called
  ```
