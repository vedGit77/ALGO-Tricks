Given three numbers n, p and mod, compute (n^p) % mod. 


ll funpow(ll n, ll p){
    if(p==0)
        return 1;
    if(p==1)
        return n;
    if(p%2==0)
        return funpow((n*n)%mod, p/2);
    else
        return (n * funpow((n*n)%mod, p/2))%mod;    //multiply by n
}
