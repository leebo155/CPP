# cpp00
  **Time to dive into Object Oriented Programming!**
                      
## Introduction
  This first prroject of C++ is designed to help me understand the specifities of the language when compared to C.
  
## Contents
 * ex00: Megaphone
 * ex01: My Awesome PhoneBook
 * ex02: The Job Of Your Dreams

## Makefile
All Exercises follow a common Make rule.
| Rules | Description |
| ----- | ----------- |
| all | Compile a program. |
| clean | Remove all the temporary generated files. |
| fclean | Remove all the generated files. |
| re | Remove all the generated files and compile a program. |

## ex00: Megaphone
This exercise aims to create a simple output program while adhering to C++ manner.   
Here's how the program operates:
  ```
  $>./megaphone "shhhhh... I think the students are asleep..."
  SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
  $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
  DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
  $>./megaphone
  * LOUD AND UNBEARABLE FEEDBACK NOISE *
  $>
  ```
  
## ex01: My Awesome PhoneBook
This exercise teaches how to write classes and create a contact program using methods. The rules for writing the program are as follows:   
* implement two classes:   
  • PhoneBook   
	  ◦ It has an array of contacts.   
	  ◦ It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.   
	  ◦ Please note that dynamic allocation is forbidden.   
  • Contact   
  	◦ Stands for a phonebook contact.
  </br>
* On program start-up, the phonebook is empty and the user is prompted to enter one of three commands. The program only accepts ADD, SEARCH and EXIT   

  • ADD: save a new contact
	> ◦ If the user enters this command, they are prompted to input the information of the new contact one field at a time. Once all the fields have been completed, add the contact to the phonebook.
  > 
	> ◦ The contact fields are: first name, last name, nickname, phone number, and darkest secret. A saved contact can’t have empty fields.
  
  • SEARCH: display a specific contact   
  > ◦ Display the saved contacts as a list of 4 columns: index, first name, last name and nickname.
  > 
  > ◦ Each column must be 10 characters wide. A pipe character `|` separates them. The text must be right-aligned. If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot `.`.
  > 
  > ◦ Then, prompt the user again for the index of the entry to display. If the index is out of range or wrong, define a relevant behavior. Otherwise, display the contact information, one field per line.

  • EXIT   
  > ◦ The program quits and the contacts are lost forever!

  • Any other input is discarded.

```
$> ./phonebook
Wellcome My Awesome PhoneBook
Please, Enter your command (ADD | SEARCH | EXIT)
>ADD
Enter First Name : Bohyeong
Enter Last Name : Lee
Enter Nick Name : bohlee
Enter Phone Number : 010 XXXX XXXX
Enter Darkest Secret : frequent diarrhea.
Please, Enter your command (ADD | SEARCH | EXIT)
>SEARCH

          |     index|first name| last name|  nickname|
          |         1|  Bohyeong|       Lee|    bohlee|

Please enter the contact's index to see more details.
>1
  
First Name : Bohyeong
Last Name : Lee
Nickname : bohlee
Phone Number : 010 XXXX XXXX
Darkest Secret : frequent diarrhea.
  
Please, Enter your command (ADD | SEARCH | EXIT)
>EXIT
$>
```

## ex02: The Job Of Your Dreams
This exercise provides Account.hpp, tests.cpp, and a log file containing the program's output.   
The goal is to read these three files, write Account.cpp, and ensure that the output matches the provided log file.   
It teaches how to use the static keyword in this process.

The provided log:
```
$> cat 19920104_091532.log
[19920104_091532] index:0;amount:42;created
[19920104_091532] index:1;amount:54;created
[19920104_091532] index:2;amount:957;created
[19920104_091532] index:3;amount:432;created
[19920104_091532] index:4;amount:1234;created
[19920104_091532] index:5;amount:0;created
[19920104_091532] index:6;amount:754;created
[19920104_091532] index:7;amount:16576;created
[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
[19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
[19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
[19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
[19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
[19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
[19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
[19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
[19920104_091532] index:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1
[19920104_091532] index:3;p_amount:432;deposit:2;amount:434;nb_deposits:1
[19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1
[19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1
[19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
[19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1
[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
[19920104_091532] index:1;amount:819;deposits:1;withdrawals:0
[19920104_091532] index:2;amount:1521;deposits:1;withdrawals:0
[19920104_091532] index:3;amount:434;deposits:1;withdrawals:0
[19920104_091532] index:4;amount:1321;deposits:1;withdrawals:0
[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
[19920104_091532] index:6;amount:763;deposits:1;withdrawals:0
[19920104_091532] index:7;amount:16596;deposits:1;withdrawals:0
[19920104_091532] index:0;p_amount:47;withdrawal:refused
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
[19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
[19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
[19920104_091532] index:5;p_amount:23;withdrawal:refused
[19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
[19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1
[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
[19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
[19920104_091532] index:1;amount:785;deposits:1;withdrawals:1
[19920104_091532] index:2;amount:864;deposits:1;withdrawals:1
[19920104_091532] index:3;amount:430;deposits:1;withdrawals:1
[19920104_091532] index:4;amount:1245;deposits:1;withdrawals:1
[19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
[19920104_091532] index:6;amount:106;deposits:1;withdrawals:1
[19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1
[19920104_091532] index:0;amount:47;closed
[19920104_091532] index:1;amount:785;closed
[19920104_091532] index:2;amount:864;closed
[19920104_091532] index:3;amount:430;closed
[19920104_091532] index:4;amount:1245;closed
[19920104_091532] index:5;amount:23;closed
[19920104_091532] index:6;amount:106;closed
[19920104_091532] index:7;amount:8942;closed

```
