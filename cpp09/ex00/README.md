# Bitcoin Exchange
In this exercise, use containers to implement a class that functions similar to a database,   
which help know how to parse data into containers.

## Rules 
Have to create a program which outputs the value of a certain amount of bitcoin on a certain date.

This program must use a database in csv format which will represent bitcoin price over time. This database is provided with this subject.

The program will take as input a second database, storing the different prices/dates to evaluate.

Program must respect these rules:
* The program name is **btc**.
* Your program must take a file as argument.
* Each line in this file must use the following format: "date | value".
* A valid date will always be in the following format: Year-Month-Day.
* A valid value must be either a float or a positive integer, between 0 and 1000.

## Execution
Example of an input.txt file:
```
$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```
```
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```
