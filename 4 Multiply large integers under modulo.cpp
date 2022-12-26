// (a*b)%m = (a%m * b%m) %m
//whats the issue.....(a%m * b%m) can cause overflow

//so use this logic=>
// If b is even then 
//   a * b = 2 * a * (b / 2) ............here both multiplied
// otherwise 
//   a * b = a + a * (b - 1).............here 1+ and 1*


long long moduloMultiplication(long long a, long long b, long long mod)
{
    long long res = 0; // Initialize result
 
    // Update a if it is more than or equal to mod
    a %= mod;
 
    while (b) {
        if (b & 1)  //if odd
            res = (res + a) % mod; //yaha res
 
        a = (2 * a) % mod;  //yaha a
 
        b >>= 1;  //DONO ke liye->odd/even
    }
 
    return res;
}

