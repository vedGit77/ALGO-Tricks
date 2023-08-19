// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/

You are given positive integers low, high, and k.

A number is beautiful if it meets both of the following conditions:
1. The count of even digits in the number is equal to the count of odd digits.
2. The number is divisible by k.

Return the number of beautiful integers in the range [low, high].


SOLn => see the soln on LC

BUT TRICK DEKHO => 
very confusing to solve with low and high both => too many if else

TRICK => apply => fun(high) - fun(low - 1)  => reduces the code drastically 

#IMP => low-1
