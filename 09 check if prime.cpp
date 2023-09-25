bool isPrime(int x) {
    if(x==0 || x==1)
        return false;
    
    for (int i = 2; i * i <= x; i++) {    //time complexity => sqrt(x)
        if (x % i == 0)
            return false;
    }
    
    return true;
}



//optimized soln

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
 
    if (n % 2 == 0 || n % 3 == 0)    // This is checked so that we can skip middle five numbers in below loop
        return false;
 
    for (int i=5; i*i<= n; i+=6)    //i=5 se start, i+=6, and i*i<=n =>all IMP
        if (n % i == 0 || n % (i + 2) == 0)    //check for i and i+2
            return false;
 
    return true;
}
 

Time Complexity: O(sqrt(n)) 
Auxiliary Space: O(1)
