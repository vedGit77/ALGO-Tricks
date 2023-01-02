// This approach is similar to Sieve of Eratosthenes
// Time Complexity: This Approach is best for all composite numbers and achieves O(log n) but is O(n) otherwise.


void primeFactors(int n)
{
    int c=2;
    while(n>1)
    {
        if(n%c==0){
        cout<<c<<" ";
        n/=c;
        }
        else c++;
    }
}
