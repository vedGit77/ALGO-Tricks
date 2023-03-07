// Travelling Salesman Problem

// Given a set of cities and the distance between EVERY pair of cities, 
// the problem is to find the shortest possible route that visits every city EXACTLY ONCE and RETURNS to the starting point. 

// Note the difference between Hamiltonian Cycle and TSP. 
// The Hamiltonian cycle problem is to find IF there exists a tour that visits every city exactly once. 
// Here we know that Hamiltonian Tour exists (because the graph is complete) and in fact, many such tours exist
// the problem is to find a minimum weight Hamiltonian Cycle. 




// Naive Solution: 
// 1) Consider city 1 as the starting and ending point.
// 2) Generate all (n-1)! Permutations of cities. 
// 3) Calculate the cost of every permutation and keep track of the minimum cost permutation. 
// 4) Return the permutation with minimum cost. 

// Time Complexity: Θ(n!) 






// Dynamic Programming:

// given set of vertices => {1, 2, 3, 4,….n} => consider 1 as starting and ending point of output. 
// For every other vertex I (other than 1) => find the minimum cost path with 1 as the starting point, I as the ending point, and all vertices appearing exactly once. 

// cost of this path => cost (i) => and the cost of the corresponding Cycle => cost (i) + dist(i, 1) ... since we have to return back from i to 1
// where dist(i, 1) is the distance from I to 1. 
// Finally, we return the minimum of all [cost(i) + dist(i, 1)] values. 

// Now the question is how to get cost(i)? 
// To calculate the cost(i) => Dynamic Programming

// Let us define => C(S, i) => cost of the minimum cost path visiting each vertex in set S exactly once, starting at 1 and ending at i.

// We start with all subsets of size 2 and calculate C(S, i) for all subsets where S is the subset
// then we calculate C(S, i) for all subsets S of size 3 and so on. 
// Note that 1 must be present in every subset.

// If size of S is 2, then S must be {1, i},
//    C(S, i) = dist(1, i) 
// Else if size of S is greater than 2.
//    C(S, i) = min { C(S-{i}, j) + dis(j, i)} ... where j belongs to S, j != i and j != 1.

  
// For maintaining the subsets we can use the bitmasks to represent the remaining nodes in our subset. 
// Since bits are faster to operate and there are only few nodes in graph, bitmasks is better to use.

// For example: –  
// 10100 represents node 2 and node 4 are left in set to be processed
// 010010 represents node 1 and 4 are left in subset.

// NOTE:- ignore the 0th bit since our graph is 1-based






// Time Complexity : O(n^2 * 2^n) 
// Auxiliary Space : O(n^2) , where n is number of Nodes/Cities here.








// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3))
		return dist[1][i];
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of
	// all possible j nodes

	for (int j = 1; j <= n; j++)
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i)))
									+ dist[j][i]);
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1)
								+ dist[i][1]);

	printf("The cost of most efficient tour = %d", ans);

	return 0;
}




