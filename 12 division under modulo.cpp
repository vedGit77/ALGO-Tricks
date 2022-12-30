Point 5 is main, others are just explanation




1. (A/B)%M = (A * B^-1)%M                => here B^-1 is MULTIPLICATIVE INVERSE of B, and (B^-1)%M is called MODULAR MULTIPLICATIVE INVERSE (MMI) of B

           = (A%M * (B^-1)%M)%M          => we expanded it usign multiplication under modulo formula
        
        

2. For a pair A,M , MMI (ie. B%M) exists when { A and M => coprime }



3. when A*B = 1       => we say B is MULTIPLICATIVE INVERSE of A
   when (A*B)%M = 1   => we say B (or B%M) is MODULAR MULTIPLICATIVE INVERSE (MMI) of A
   
   (A*B)%M = (A%M * B%M)%M = 1  => if we are calling B%M our MMI => then  { 0 <= MMI <M }
   
   thus we can find MMI (ie. B%M) for any pair A,M in time complexity O(M) => by running a for loop => NOT OPTIMAL WAY
 
 
 
4. In pt 3, we discussed POOR/UN-OPTIMIZED soln to find MMI for a pair A,M
    
   OPTIMIZED WAY => Fermats Little Thm =>   (A^(M-1))%M = 1   => given M is Prime && A is NOT a multiple of M && (automatically implies coprime)
                 => multiply A^-1 both sides => A^-1 = (A^(M-2))%M  => this is how we get MMI for a pair A,M.
           
   {******  A^-1 = (A^(M-2))%M  ******}

   how to calculate A^(M-2) optimally? => BINARY EXPONENTIATION
   
   
   
   
5. So if I need (A/B)%M => (A%M * (B^-1)%M)%M      --> B inverse
                        = (A%M * (B^(M-2))%M)%M    --> B ki power M-2  --> use Binary Exponentiation
   
   
   
6. Till now we discussed when M is prime => when NON prime => use extended Eucleidean Algo => NO need to do it!
