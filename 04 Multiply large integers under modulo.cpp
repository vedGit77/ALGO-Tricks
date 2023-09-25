// (a*b)%m = (a%m * b%m) %m
//whats the issue.....(a%m * b%m) can cause overflow

//so use this logic=>
// If b is even then 
//   a * b = 2 * a * (b / 2) ............here both multiplied
// otherwise 
//   a * b = a + a * (b - 1).............here 1+ and 1*


long long fun(long long a, long long b, long long mod){
    a = a%mod;
    b = b%mod;

    if(a==1)
        return b;
    if(b==1)
        return a;

    if((b%2)==0){
        return (2 * fun(a, b/2, mod)%mod)%mod;
    }else{
        return (a%mod + fun(a, b-1, mod)%mod)%mod;
    }
}
