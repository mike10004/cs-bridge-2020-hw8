# Question 6

Write a program that reads in a line of text and outputs the line with all the 
digits in all integer numbers replaced with `x`.

    Please enter a line of text:
    My userID is john17 and my 4 digit pin is 1234 which is secret
    My userID is john17 and my x digit pin is xxxx which is secret

## Notes

1. If a digits is part of a word, then the digit is not changed to an 'x'. 
   For example, `john17` is NOT changed to `johnxx`.
2. You may assume that the text entered by the user will contain only letters 
  (upper case or lower case), digits and spaces.
3. Think how to break down your implementation to functions.
