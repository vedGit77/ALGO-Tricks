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
// 2. suppose we have processed the points from 1 to N-1, and let h be the shortest distance we have got so far. 
// 3. For Nth point, we want to find points whose distance from Nth point is <= h.
// 4. we can only go till h distance from x_n to find such point. => x_n ke loiye ONLY leftwards (since we are considering points [1,n-1])
// 5. in the y direction, we can go in h distance upwards and h distance downwards => for y_n => upar and neeche both 
// 6. So, all such points => x coordinate lie in [x_n - h, x_n] && y coordinates lie in [y_n - h, y_n + h]=> what we are concerned with
// 7. All points in the set with x coordinates less than (x_n-h) are to be deleted . 
// 8. After this processing, we'll add the Nth point to the set.
// NOTE => at any instance, the number of points under consideration is O(1)(there can be atmost 5 points around a point under consideration => excluding the point itself)


#define px second
#define py first
typedef pair<long long, long long> pairll;
pairll pnts [MAX];
int compare(pairll a, pairll b)
{ 
        return a.px<b.px; 
}
double closest_pair(pairll pnts[],int n)
{
        sort(pnts,pnts+n,compare);
        double best=INF;
        set<pairll> box;
        box.insert(pnts[0]);
        int left = 0;
        for (int i=1;i<n;++i)
        {
            while (left<i && pnts[i].px-pnts[left].px > best)
                box.erase(pnts[left++]);
            for(typeof(box.begin()) it=box.lower_bound(make_pair(pnts[i].py-best, pnts[i].px-best));it!=box.end() && pnts[i].py+best>=it->py;it++)
                best = min(best, sqrt(pow(pnts[i].py - it->py, 2.0)+pow(pnts[i].px - it->px, 2.0)));
            box.insert(pnts[i]);
        }
        return best;
}











long closestPair(vector<pair<int, int> > coordinates, int n)
{
	int i;
	// Vector pair to store points on plane
	vector<pair<int, int> > v;
  
	for (i = 0; i < n; i++)
		v.push_back({ coordinates[i].first,	coordinates[i].second });

	// Sort them according to their x-coordinates
	sort(v.begin(), v.end());

	// Minimum distance b/w points seen so far
	long d = INT_MAX;

	// Keeping the points in increasing order
	set<pair<int, int> > st;
	st.insert({ v[0].first, v[0].second });

	for (i = 1; i < n; i++) {
		auto l = st.lower_bound({ v[i].first - d, v[i].second - d });
		auto r = st.upper_bound({ v[i].first, v[i].second + d });
		if (l == st.end())
			continue;

		for (auto p = l; p != r; p++) {
			pair<int, int> val = *p;
			long dis = (v[i].first - val.first)* (v[i].first - val.first)+ (v[i].second - val.second)* (v[i].second - val.second);

			// Updating the minimum distance dis
			if (d > dis)
				d = dis;
		}
		st.insert({ v[i].first, v[i].second });
	}

	return d;
}

