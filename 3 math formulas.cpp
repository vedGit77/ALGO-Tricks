a2 – b2 = (a – b)(a + b)
  
(a + b)2 = a2 + 2ab + b2

(a – b)2 = a2 – 2ab + b2

(a + b + c)2 = a2 + b2 + c2 + 2ab + 2bc + 2ca
  
(a – b – c)2 = a2 + b2 + c2 – 2ab + 2bc – 2ca
  
(a + b + c + …)2 = a2 + b2 + c2 + … + 2(ab + ac + bc + ….) //VVIMP
 //why imp...say we have an array arr[]={a,b,c,d,e...}....we want (SUM of product of all pairs)...ie we want (ab+ac+ad+ae...+bc+bd+be...+cd+ce...so on)
 //we can get in O(n^2) with naive approach
//but with this formula...we can get in O(n)!!!!
  
(a + b)3 = a3 + 3a2b + 3ab2 + b3  or  a3 + b3 + 3ab(a + b)
  
(a – b)3 = a3 – 3a2b + 3ab2 – b3  or  a3 – b3 – 3ab(a – b)
  
(a + b)4 = a4 + 4a3b + 6a2b2 + 4ab3 + b4
(a – b)4 = a4 – 4a3b + 6a2b2 – 4ab3 + b4

If n is a natural number=> an – bn = (a – b)(an-1 + an-2b+…+ bn-2a + bn-1)//all +
  
If n is even (n = 2k)=> an + bn = (a + b)(an-1 – an-2b +…+ bn-2a – bn-1)//alternate +-
  
If n is odd (n = 2k + 1)=> an + bn = (a + b)(an-1 – an-2b +an-3b2…- bn-2a + bn-1)//alternate +-
  
