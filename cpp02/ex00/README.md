# My First Class in Orthodox Canonical Form
This exercise is about creating a fixed-point class according to the Orthodox Canonical Form. Through this process, learn about the default constructor, destructor, copy constructor, and copy assignment operator.

# Rules 
* Create a class in Orthodox Canonical Form that represents a fixed-point number:
  
  • Private members:   
  > ◦ An integer to store the fixed-point number value.   
  > ◦ A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.   

  • Public members:   
  > ◦ A default constructor that initializes the fixed-point number value to 0.   
  > ◦ A copy constructor.   
  > ◦ A copy assignment operator overload.   
  > ◦ A destructor.   
  > ◦ A member function int getRawBits( void ) const; that returns the raw value of the fixed-point value.   
  > ◦ A member function void setRawBits( int const raw ); that sets the raw value of the fixed-point number.   

# Execution
  ```cpp
  int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
  }
  ```

  ```
  ./a.out
  Default constructor called
  Copy constructor called
  Copy assignment operator called
  getRawBits member function called
  Default constructor called
  Copy assignment operator called
  getRawBits member function called
  getRawBits member function called
  0
  getRawBits member function called
  0
  getRawBits member function called
  0
  Destructor called
  Destructor called
  Destructor called
  ```
