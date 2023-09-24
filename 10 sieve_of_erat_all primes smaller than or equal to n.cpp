//Sieve of Eratosthenes

// time: n*log(log(n))

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p*p<=n; p++)  // p*p => repeated in both loops => beech mei, then left mei
    {  
        if (prime[p] == true) 
        {
            for (int i =p*p; i<=n; i+=p)   // i += p
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)   //p = 2 se start
        if (prime[p])
            cout << p << " ";
}
