//Given a set of points in the plane
//convex hull of the set is the smallest convex polygon that contains all the points of it

// we solve using Grahams Scan
// time complexity: O(N*logN)

//algo:
//1. if no. of (pts <= 3) => those 3 pts form the convex hull
//2. else:
//   1. sort accorging to x-coordinate
//   2. left-most AND right-most pt will SURELY be part of the convex hull
//   3. create upper and lower hull using left-most and right-most pt
//3. How to make the hull? -> use cross product:
//   1. cross product of 3 points in sorted x-coordinate will give > 0 for clockwise => use to create upper half of hull
//   2.   "      "     "    "    REVERSE-sorted x-coordinate gives > 0 for ANTI-clockwise => use to create lower half of hull
//4. combine upper and lower hull


class Solution {
public:
    int cross_product(vector<int>&p1, vector<int>&p2, vector<int>&p3){
        //learn as (p3_y - p1_y)*(p2_x - p1_x) - (p3_x - p1_x)*(p2_y - p1_y)
        return ((p3[1]-p1[1])*(p2[0]-p1[0])) - ((p3[0]-p1[0])*(p2[1]-p1[1]));
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int sz = trees.size();
        if(sz <= 3)
            return trees;
        
        vector<vector<int>>up_hull;
        vector<vector<int>>low_hull;

        sort(trees.begin(), trees.end());  //sort as per x axis

        up_hull.push_back(trees[0]);   // push 0 and 1
        up_hull.push_back(trees[1]);

        for(int i=2; i<sz; i++){  
            int k = up_hull.size();
            while(k>=2 && cross_product(up_hull[k-2], up_hull[k-1], trees[i])>0){  //dono loops mei >0
                k--;
                up_hull.pop_back();
            }
            up_hull.push_back(trees[i]);
        }

        low_hull.push_back(trees[sz-1]);  //push sz-1 and sz-2
        low_hull.push_back(trees[sz-2]);

        for(int i=sz-3; i>=0; i--){  // ULTA for loop => IMP
            int k = low_hull.size();
            while(k>=2 && cross_product(low_hull[k-2], low_hull[k-1], trees[i])>0){  // dono loops mei >0
                k--;
                low_hull.pop_back();
            }
            low_hull.push_back(trees[i]);
        }
        
        set<vector<int>>s;  //merge upper and lower hulls
        for(auto x:up_hull)
            s.insert(x);
        for(auto x:low_hull)
            s.insert(x);
        
        vector<vector<int>>ans;
        for(auto x:s)
            ans.push_back(x);

        return ans;
    }
};
