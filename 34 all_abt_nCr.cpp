//we need nCr


// Method 1: Space & Time Efficient 
//        : Time O(r)
//        : Space O(1)

// Drawback => for big values of n, r => products may overflow


int fun(int n, int k)
{
	int res = 1;

	// Since C(n, k) = C(n, n-k)
	if (k > n - k)
		k = n - k;

	// Calculate => [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
	for (int i = 0; i < k; ++i) {
		res *= (n - i);
		res /= (i + 1);
	}

	return res;
}


       




 


// Method 2: using gcd
// Time Complexity: O(R * Log N) 
// Auxiliary Space: O(1)

// Advantage: Prevents overflow



void printNcR(int n, int r)
{

	// p holds the value of n*(n-1)*(n-2)...(n-r+1)
	// k holds the value of r*(r-1)...1
	long long p = 1, k = 1;

	// C(n, r) == C(n, n-r),
	// choosing the smaller value
	if (n - r < r)
		r = n - r;

	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;

			// gcd of p, k
			long long m = __gcd(p, k);

			// dividing by gcd => saves from the overflow
			p /= m;
			k /= m;

			n--;
			r--;
		}

		// k should be simplified to 1
		// as C(n, r) is a natural number
		// (denominator should be 1 ) 
	}

	else
		p = 1;   //when r==0

	// if our approach is correct p = ans and k =1
	cout << p << endl;
}











// Method 3: (Modular Inversion technique) => for (nCr)%m => MODULO AAYEGA since large value!

// Time Complexity: O(n+r)
// Auxiliary Space: O(r) 

// 1. General formula => nCr is ( n*(n-1)*(n-2)* … *(n-r+1) ) / (r!)
//    sometimes => overflow out of bound. 
//    We need to find nCr mod m so that it doesn’t overflow. 
//    We can easily do it with modular arithmetic formula. 

// 2. for => n*(n-1)*(n-2)* ... *(n-r+1) => we can use the formula =>
//    (a*b)%m = ((a % m) * (b % m)) % m

// 3. and for the 1/r! part
//    find the modular inverse of EVERY number from 1 to r. 
//    We can find modular inverse in O(r) time using  the formula =>

//    inv[1] = 1
//    inv[i] = (m − (m/i) * inv[m%i]%m)        => done this before in MMI wali file

//    To use this formula, m has to be a prime.
//    In the practice problem, we need to show the answer with modulo 1000000007 which is a prime. 
//    So, this technique will work.



// find (nCr)%m
int binomialCoeff(int n, int r)
{
	if (r > n)
		return 0;
	
	long long int m = 1000000007;
	long long int inv[r + 1] = { 0 };   //why r+1 => since this given answer for [0, k-1] => so when r+1 => answer for [0, r]
	
	inv[0] = 1;
	
	if(r+1>=2)
		inv[1] = 1;

	
	// modular inversion for all the numbers
	// from 2 to r with respect to m
	// here m = 1000000007
	
	for (int i = 2; i <= r; i++) 
		inv[i] = ( m - (m / i) * inv[m % i] % m );
	
	//pehle multiply-> then %-> then subtract
	

	int ans = 1;

	// for 1/(r!) part
	for (int i = 2; i <= r; i++) 
		ans = ((ans % m) * (inv[i] % m)) % m;

	// for (n)*(n-1)*(n-2)*...*(n-r+1) part
	for (int i = n; i >= (n - r + 1); i--) 
		ans = ((ans % m) * (i % m)) % m;
	
	return ans;
}












// Method 4: (nCr)%p for q queries 

// N <= 10^6
// R <= 10^6
// p is a prime number

// query => p is fixed => n,r are varying

// Time Complexity: O(N) for precomputing and O(1) for every query
// Auxiliary Space: O(N) 




const int N = 1000001;

// array to precompute inverse of 1! to N!
ll factorialNumInverse[N + 1];

// array to store inverse of 1 to N
ll naturalNumInverse[N + 1];

// array to store factorial of first N numbers
ll fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(ll p)
{
	naturalNumInverse[0] = naturalNumInverse[1] = 1;
	
	for (int i = 2; i <= N; i++)
		naturalNumInverse[i] = p - (p/i) * naturalNumInverse[p % i] % p;
}

// Function to precompute inverse of factorials
void InverseofFactorial(ll p)
{
	factorialNumInverse[0] = factorialNumInverse[1] = 1;

	// precompute inverse of natural numbers
	for (int i = 2; i <= N; i++)
		factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;    //jaise factorial nikalte hai...analogous logic => fact(i) = i*fact(i-1)
}

// Function to calculate factorial of 1 to N
void factorial(ll p)
{
	fact[0] = 1;

	// precompute factorials
	for (int i = 1; i <= N; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

// Function to return nCr % p in O(1) time
ll Binomial(ll N, ll R, ll p)
{
	// n C r = n!*inverse(r!)*inverse((n-r)!)
	ll ans = ((fact[N] * factorialNumInverse[R])% p * factorialNumInverse[N - R])% p;
	return ans;
}

// Driver Code
int main()
{
	ll p = 1000000007;
	InverseofNumber(p);
	InverseofFactorial(p);
	factorial(p);

	// 1st query
	ll N = 15;
	ll R = 4;
	cout << Binomial(N, R, p) << endl;

	// 2nd query
	N = 20;
	R = 3;
	cout << Binomial(N, R, p) << endl;

	return 0;
}
