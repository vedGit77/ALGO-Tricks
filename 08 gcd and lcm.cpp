
=>  n*m = GCD(n,m)*LCM(n,m)   
    
=> for coprime numbers, GCD = 1

code=> 

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


To get LCM -> (n*m)/gcd


