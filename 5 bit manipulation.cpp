log2(x & ~(x-1)) }....this is a short cut to return the position of the 1st set bit from the end
   eg x = 5....its binary form is 101...so ans =0
   eg x = 8.... "   "      "    " 1000....so ans = 3


a+b = a^b + 2*(a&b)
  
(a+b)%m = a%m + b%m

(a*b)%m = (a%m * b%m )%m //NOTE: (a%m * b%m) can cause overflow! ...check file 4 for it

a^(a&b) = (a|b)^b


Some properties of bitwise operations:
a|b = a⊕b + a&b
a⊕(a&b) = (a|b)⊕b
b⊕(a&b) = (a|b)⊕a
(a&b)⊕(a|b) = a⊕b

Addition:
a+b = a|b + a&b
a+b = a⊕b + 2(a&b)

Subtraction:
a-b = (a⊕(a&b))-((a|b)⊕a)
a-b = ((a|b)⊕b)-((a|b)⊕a)
a-b = (a⊕(a&b))-(b⊕(a&b))
a-b = ((a|b)⊕b)-(b⊕(a&b))
