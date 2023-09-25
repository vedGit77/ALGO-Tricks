//Sieve of Eratosthenes

// time: n*log(log(n))

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int i = 2; i*i<=n; i++)  // i*i => repeated in both loops => beech mei, then left mei
    {  
        if (prime[i] == true) 
        {
            for (int j =i*i; j<=n; j+=i)   // j += i
                prime[j] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)   //p = 2 se start
        if (prime[p])
            cout << p << " ";
}
