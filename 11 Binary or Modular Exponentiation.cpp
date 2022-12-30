Given three numbers x, y and p, compute (x^y) % p. 


int power(long long x, unsigned int y, int p)
{
    int res = 1;	
  
    x = x % p; // Update x 
    
    // y = y%p;  =>DONT DO => FATAL!
  
    if (x == 0) 
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd
        if (y & 1)
          res = (res*x) % p;    //multiply x with res =>imp

        // y must be even now
        y = y/2;
        x = (x*x) % p;  //update x
    }
  
    return res;
}


