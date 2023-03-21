//we need nCr


// Method 1: Space & Time Efficient 
//        : Time O(r)
//        : Space O(1)


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


       

 





// Method 2: (Modular Inversion technique) => for (nCr)%m => MODULO AAYEGA since large value!

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

