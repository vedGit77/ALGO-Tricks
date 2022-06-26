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
