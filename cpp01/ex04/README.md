# Sed is for losers
This exercise involves writing a program similar to the sed command, allowing you to learn about the string class.

## Rules
* Create a program that takes three parameters in the following order: a `filename` and two strings, `s1` and `s2`.
* It will open the file `filename` and copies its content into a new file `filename.replace`, replacing every occurrence of `s1` with `s2`.

## Execution
  ``` 
  $> cat text
  ABC BBC ABE ACD

  $> ./replace text B F

  $> cat text.replace
  AFC FFC AFE ACDb
  ```
