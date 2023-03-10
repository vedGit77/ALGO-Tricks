// Given a set of n integers where n <= 40.
// Each of them is at most 10^12.
// determine the maximum sum subset having sum less than or equal S where S <= 10^18.


// Brute Force:
// find all possible subset sums of N integers 
// check if it is less than or equal S and keep track of such a subset with maximum sum. 
// Time complexity => O(2^n) and n is at most 40. 2^40 will be quite large.
  

// OPTIMIZED:
// Meet in the middle => search technique => used when the input is small but NOT as small that brute force can be used. 
// Like divide and conquer it splits the problem into two, solves them individually and then merge them. 

  
// Split => set of integers => 2 subsets say A and B. 
// A having first n/2 integers and B having rest.
// Find all possible subset sums of integers in set A => store in an array X. 
// All possible subset sums of integers in set B => store in array Y. 
// Hence, Size of each of the array X and Y will be at most 2^(n/2).
// Now merge these 2 subproblems. 
// Find combinations from array X and Y such that their sum is less than or equal to S. 

// To make it optimized => sort array Y and then iterate over each element of X => for each element x in X use binary search => find maximum element y in Y such that x + y <= S.
// Binary search here helps in reducing complexity to 2^(n/2)*log(2^(n/2)) which is equivalent to n*(2^(n/2))





typedef long long int ll;
ll X[2000005],Y[2000005];

// Find all possible sum of elements of a[] and store in x[] 
void calcsubarray(ll a[], ll x[], int n, int c)
{
	for (int i=0; i<(1<<n); i++)  // i is from [0, 2^n) => all possible permutations
	{
		ll s = 0;
		for (int j=0; j<n; j++)  //this loop => basically adds all those a[j+c] => where the jth bit is set in 'i' => since set bit in 'i' denotes if that element is taken in our sum
			if (i & (1<<j))
				s += a[j+c];
		x[i] = s;
	}
}

// Returns the maximum possible sum less or equal to S
ll solveSubsetSum(ll a[], int n, ll S)
{
	// Compute all subset sums of first and second halves
	calcsubarray(a, X, n/2, 0);
	calcsubarray(a, Y, n-n/2, n/2);

	int size_X = 1<<(n/2);
	int size_Y = 1<<(n-n/2);

	// Sort Y (we need to do doing binary search in it)
	sort(Y, Y+size_Y);

	// To keep track of the maximum sum of a subset such that the maximum sum is less than S
	ll max = 0;

	// Traverse all elements of X and do Binary Search for a pair in Y with maximum sum less than S.
	for (int i=0; i<size_X; i++)
	{
		if (X[i] <= S)
		{
			int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y;

			// If S-X[i] was not in array Y then decrease p by 1
			if (p == size_Y || Y[p] != (S-X[i]))
				p--;

			if ((Y[p]+X[i]) > max)
				max = Y[p]+X[i];
		}
	}
	return max;
}


