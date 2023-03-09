// A sweep line is an imaginary vertical line which is swept across the plane rightwards. 
// That's why, the algorithms based on this concept are sometimes also called plane sweep algorithms. 
// We sweep the line based on some events, in order to discretize the sweep.


// We will discuss these problems for understanding:
// 1. Closest Pair












// 1. Closest Pair
// Problem: Find the closest pair of points in the given array of distinct points. (points (x,y) => x and y are integers)

// Naive sol : comparing all pairs of points => but then its complexity is O(N^2)

// Optimized : sweep line
// 1. sort the points in x direction => as we want our line to move towards right.
// 2. suppose we have processed the points from 1 to N-1, and let d be the shortest distance we have got so far. 
// 3. For Nth point, we want to find points whose distance from Nth point is <= d.
// 4. we can only go till d distance from x_n to find such point. => x_n ke loiye ONLY leftwards (since we are considering points [1,n-1])
// 5. in the y direction, we can go in d distance upwards and d distance downwards => for y_n => upar and neeche both 
// 6. So, all such points => x coordinate lie in [x_n - d, x_n] && y coordinates lie in [y_n - d, y_n + d]=> what we are concerned with
// 7. All points in the set with x coordinates less than (x_n-d) are to be deleted . 
// 8. After this processing, we'll add the Nth point to the set.
// NOTE => at any instance, the number of points under consideration is O(1)(there can be atmost 5 points around a point under consideration => excluding the point itself)


// Time Complexity: O(N * log(N)) => since lower_bound / upper_bound works on binary search
// Auxiliary Space: O(N)



// PRE-REQUISITE:

// In Pairs => lower_bound() for pair(x, y) => return an iterator => whose:   
// 1. first value > x  
// 	OR
// 2. first value == x && second value >= y
// If the above-mentioned criteria are not met => returns an iterator to the index which is out of the vectors of pairs. 

// In Pairs => upper_bound() for pair(x, y) => return an iterator => whose:
// 1. first value > x
// 	OR
// 2. First value == x && second value > y
	
	
long closestPair(vector<pair<int, int> > coordinates, int n)
{
	int i;
	
	vector<pair<int, int> > v;   //store points on plane
  
	for (i = 0; i < n; i++)
		v.push_back({ coordinates[i].first, coordinates[i].second });

	sort(v.begin(), v.end());  // Sort them according to their x-coordinates

	long d = INT_MAX;  // Minimum distance b/w points seen so far

	set<pair<int, int> > st;
	st.insert({ v[0].first, v[0].second });

	for (i = 1; i < n; i++) //start with i=1, since set mei already i=0 wala point hai
	{  
		auto l = st.lower_bound({ v[i].first - d, v[i].second - d });  //lower -> (x-d, y-d)
		auto r = st.upper_bound({ v[i].first, v[i].second + d });    //upper -> (x,y+d)
		
		if (l == st.end())
			continue;

		for (auto p = l; p != r; p++)  //IMP => p!=r
		{
			pair<int, int> val = *p;
			
			long dis = (v[i].first - val.first)*(v[i].first - val.first) + (v[i].second - val.second)*(v[i].second - val.second);  //under-root nahi liya => since we want coordinates => no need to return distance

			if (d > dis)
				d = dis;
		}
		
		st.insert({ v[i].first, v[i].second });
	}

	return d;
}

