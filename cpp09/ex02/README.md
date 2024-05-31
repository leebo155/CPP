# PmergeMe
In this exercise, implement a program that aligns two containers in the Ford-Johnson algorithm,    
which help understand the differences between the two containers.

## Rules
Create a program with these constraints:
* The name of the program is PmergeMe.

* Program must be able to use a positive integer sequence as argument.

* Program must use the merge-insert sort algorithm to sort the positive integer sequence.

* If an error occurs during program execution, an error message should be displayed on the standard output.

Here are some additional guidelines on the information you should display line by line on the standard output:
* On the first line must display an explicit text followed by the unsorted positive integer sequence.

* On the second line must display an explicit text followed by the sorted positive integer sequence.

* On the third line you must display an explicit text indicating the time used by   
  algorithm by specifying the first container used to sort the positive integer sequence.
  
* On the last line you must display an explicit text indicating the time used by   
  algorithm by specifying the second container used to sort the positive integer sequence.
  
## Execution
```
$> ./PmergeMe 3 5 9 7 4
before:	3 5 9 7 4
after:	3 4 5 7 9
Time to process a range of	5 elements with std::vector : 0.009 ms
Time to process a range of	5 elements with std::deque  : 0.026 ms

$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
before:	18720 1882 59005 [...]
after:	8 27 65 [...]
Time to process a range of	3000 elements with std::vector : 5.429 ms
Time to process a range of	3000 elements with std::deque  : 9.969 ms
```
