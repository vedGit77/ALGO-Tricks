Before Linear Diophantine Equations, some prerequisite:

1. Euclidean algorithm (GCD):
  
  int gcd(int a, int b)
  {
      if (a == 0)
          return b;
      return gcd(b % a, a);
  }


2. Extended Euclidean Algorithm: 
  finds integer coefficients x and y such that:
  ax + by = gcd(a, b) 
