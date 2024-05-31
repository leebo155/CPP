#  Span
In this exercise, implement class using containers, which help understand the containers more.

## Rules
Develop a **Span** class that can store a maximum of **N** integers. **N** is an unsigned int variable and will be the only parameter passed to the constructor.

This class will have a member function called **addNumber()** to add a single number to the Span. It will be used in order to fill it.
Any attempt to add a new element if ther are already **N** elements stored should throw an exception.

Next, implement two member functions: **shortestSpan()** and **longestSpan()**

They will respectively find out the shortest span or the longest span (or distance, if you prefer) between all the numbers stored, and return it.
If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.

Last but not least, it would be wonderful to fill your Span using a range of iterators.
Making thousands calls to addNumber() is so annoying. Implement a member function to add many numbers to your Span in one call.

## Execution
```cpp
int main()
{
	try {
		std::cout << "Test0: default" << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.printElements();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	
		std::cout << "\nTest1: full storage" << std::endl;
		try {
			sp.addNumber(15);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		
		std::cout << "\nTest2: empty storage shortestSpan(), longestSpan()" << std::endl;
		Span span = Span(100);
		try {
			std::cout << span.shortestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			std::cout << span.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << "\nTest3: addNumber(size, min, max)" << std::endl;
		try {
			span.addNumber(100, -2147483648, 2147483647);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		span.printElements();
	
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	
		std::cout << "\nTest4: boundary test" << std::endl;
		Span test(10);
		test.addNumber(-2147483648);
		test.addNumber(2147483647);
		test.printElements();
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;

		std::cout << "\nTest5: deep copy" << std::endl;
		Span copy = Span(test);
		copy.addNumber(0);
		test.printElements();
		copy.printElements();
		std::cout << copy.shortestSpan() << std::endl;
		std::cout << copy.longestSpan() << std::endl;

	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
```
```
./a.out
Test0: default
{ 6 3 17 9 11 }
2
14

Test1: full storage
storage is full

Test2: empty storage shortestSpan(), longestSpan()
not enough elements
not enough elements

Test3: addNumber(size, min, max)
{ 1746143030 -85597885 170390294 -993497033 1128205440 -531756123 601779552 -539030099 -1392850847 -2072433229 799474536 2110847726 587899248 -1897065551 1856474998 -1162082717 -1907938801 -501611403 437947900 -983569809 471334742 1803335464 -925033503 743519358 -2024958827 -162167733 1751143158 -1947792469 -307311615 1859341376 -231507905 287009028 512479240 1829179016 -364151733 30217418 1058020440 984954726 1330145612 452552420 -338537927 1024725460 -258025913 1275447148 258468888 1874683188 -79711261 322632100 -2065970815 2039084284 1345539168 1474010472 322667918 -1463977689 794608302 1928431474 1324599800 1733370604 -3396967 -1258249547 1018819226 -739852989 -778869993 592339760 -279824365 -18915625 -87329619 1129908014 -1981365963 -1936309759 -590932875 -1844446397 1463333712 1266988946 -164611423 -665249025 -1040496893 1475540516 268313662 -167924659 -516231655 -471491705 -146428505 -7624073 711223908 646259360 -291206199 1960128566 1481680588 385288710 -1263313575 1807046510 1316974502 -1870961355 -1791934111 -725938049 1161292710 1515209840 1270711560 -2023147335 }
35818
4183280955

Test4: boundary test
{ -2147483648 2147483647 }
4294967295
4294967295

Test5: deep copy
{ -2147483648 2147483647 }
{ -2147483648 2147483647 0 }
2147483647
4294967295
```
