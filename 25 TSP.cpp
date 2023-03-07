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


// For DP:
// Time Complexity : O(n^2 * 2^n) 
// Auxiliary Space : O(n^2) , where n is number of Nodes/Cities here.






 int rec(int curr, vector<vector<int>>&cost, int mask, int n,vector<vector<int>>&dp)
{
	if(mask == ((1<<n)-1))  //all visited
	      return cost[curr][0];  // curr->0 ka return karo

	if(dp[curr][mask]!=-1)
		return dp[curr][mask];

	int res=INT_MAX;

	for(int city=0; city<n; city++)
	{
	     if( (mask&(1<<city)) == 0 )  //means NOT visited
	     {
		    int temp = cost[curr][city] + rec(city, cost, mask|(1<<city), n, dp);   //make thsi city visited in our mask   //add cost[curr][city]

		    res = min(res,temp);
	     }
	}

	return dp[curr][mask] = res;
}

int total_cost(vector<vector<int>>cost){  //given cost vector... cost[i,j] = cost of moving from city i to j => NOTE: cost[i][j] != cost[j][i] (may OR may not)
	int n=cost.size();
	vector<vector<int>>dp(n, vector<int>((1<<n),-1));  //dp[curr_city][mask]  
	
	int mask=1;  // initially...means we have visited city_0 ... say we have 4 cities ... then mask initially = 0001
	return rec(0,cost,mask,n,dp);  //we assume we start from city_0, and return back to it
}
