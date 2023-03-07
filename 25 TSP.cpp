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

// Let the given set of vertices be {1, 2, 3, 4,….n}. Let us consider 1 as starting and ending point of output. 
// For every other vertex I (other than 1), we find the minimum cost path with 1 as the starting point, I as the ending point, and all vertices appearing exactly once. 

// Let the cost of this path cost (i), and the cost of the corresponding Cycle would cost (i) + dist(i, 1) 
// where dist(i, 1) is the distance from I to 1. 
// Finally, we return the minimum of all [cost(i) + dist(i, 1)] values. This looks simple so far. 

// Now the question is how to get cost(i)? 
// To calculate the cost(i) using Dynamic Programming, we need to have some recursive relation in terms of sub-problems. 

// Let us define a term C(S, i) be the cost of the minimum cost path visiting each vertex in set S exactly once, starting at 1 and ending ati.
// We start with all subsets of size 2 and calculate C(S, i) for all subsets where S is the subset, 
// then we calculate C(S, i) for all subsets S of size 3 and so on. Note that 1 must be present in every subset.

// If size of S is 2, then S must be {1, i},
//  C(S, i) = dist(1, i) 
// Else if size of S is greater than 2.
//  C(S, i) = min { C(S-{i}, j) + dis(j, i)} where j belongs to S, j != i and j != 1.

  
// For maintaining the subsets we can use the bitmasks to represent the remaining nodes in our subset. 
// Since bits are faster to operate and there are only few nodes in graph, bitmasks is better to use.

// For example: –  
// 10100 represents node 2 and node 4 are left in set to be processed
// 010010 represents node 1 and 4 are left in subset.

// NOTE:- ignore the 0th bit since our graph is 1-based



