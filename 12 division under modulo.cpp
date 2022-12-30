
1. (A/B)%M = (A * B^-1)%M                => here B^-1 is MULTIPLICATIVE INVERSE of B, and (B^-1)%M is called MODULAR MULTIPLICATIVE INVERSE (MMI) of B

           = (A%M * (B^-1)%M)%M          => we expanded it usign multiplication under modulo formula
        
        

2. when A*B = 1       => we say B is MULTIPLICATIVE INVERSE of A
   when (A*B)%M = 1   => we say B (or B%M) is MODULAR MULTIPLICATIVE INVERSE (MMI) of A
   
   (A*B)%M = (A%M * B%M)%M = 1  => if we are calling B%M our MMI => then  { 0 <= MMI <M }
   
   thus we can find MMI for any pair A,M in time complexity O(M) ->by running a for loop
 
 
 
 3. For a pair A,M , MMI exists when { A and M => coprime }

