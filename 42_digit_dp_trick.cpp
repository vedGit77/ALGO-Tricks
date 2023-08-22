// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/

You are given positive integers low, high, and k.

A number is beautiful if it meets both of the following conditions:
1. The count of even digits in the number is equal to the count of odd digits.
2. The number is divisible by k.

Return the number of beautiful integers in the range [low, high].

see sol on LC -> here we wil discuss general trick ONLY



TRICK DEKHO => 
very confusing to solve with low and high both => too many if else

TRICK => apply => fun(high) - fun(low - 1)  => reduces the code drastically 

# 2 things to take care of->
  1. use (low-1) => NOT low (since question asks to include low as well)
  2. use memset 2 TIMES => once for each dp call => VVVVIIIMMMMPPPPP!!!!


# generally the parameters we use in digit dp=>
  1. i (index of string -> the number is in form of string)
  2. tight
  3. zero (if all zeros till now)
....other parameters based on question 

