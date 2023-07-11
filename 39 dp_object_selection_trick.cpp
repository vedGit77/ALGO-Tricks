// Question : Leetcode 689 : Max sum of 3 NON overlapping Subarrays

// Given an integer array nums and an integer k, find (3 non-overlapping subarrays) of (length k) with (maximum sum) and return them.
// Return the result as a list of indices representing the starting position of each interval (0-indexed). 
// If there are multiple answers, return the lexicographically smallest one.

// Input: nums = [1,2,1,2,6,7,5,1], k = 2
// Output: [0,3,5] ->these are indices (max sum = 23)



// GENERAL APPROACH:

// Whenever the question asks you to **find the objects chosen** instead of the **final value** you get when you choose these objects 
// (like the indices selected in this question) 
// do the DP for finding the value (like the maximum sum in this case)
// then do a DFS for retracing the steps

// So first for each index find the subarray sum of length k starting at that index and store it in an array. 
// Then simply do a knapsack DP which is like you can either choose or not choose this sub array. 
// If you include take this sub array, then you can only go to the (i+k)th index because every in between element will have some overlap with the ith sum.

//the below code is very generic -> can be used for any 'XYZ NON OVERLAPPING SUBARRAYS'


class Solution {
public:
    int n;
    vector<int>pre;  //prefix sum
    vector<int>ans;  //answer->array of 3 indices
    int dp[20001][4];

    int fun(int i, int cnt, int k){  //i is the current index OF NUMS, cnt is number of remaining subarrays
        if((i+k)>n || cnt==0){
            return 0;
        }
        if(dp[i][cnt]!=-1)
            return dp[i][cnt];

        int take = pre[i+k]-pre[i] + fun(i+k, cnt-1, k);
        int dont = fun(i+1, cnt, k);

        return dp[i][cnt] = max(take, dont);
    }

    void dfs(int i, int cnt, int k){
        if((i+k)>n || cnt==0)
            return;
        
        int take = pre[i+k]-pre[i] + fun(i+k, cnt-1, k);  //get values from dp table -> NOTE: we cll fun(), and NOT dp[i+k][cnt-1] because (i+k) can exceed size of dp
        int dont = fun(i+1, cnt, k);   //get values from dp table

        if(take >= dont){  //recursion
            ans.push_back(i);
            dfs(i+k, cnt-1, k);
        }else{
            dfs(i+1, cnt, k);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        n = nums.size();
        pre.push_back(0);  //imp ->size of pre is (n+1)
        for(int i=0;i<n;i++)
            pre.push_back(pre[i]+nums[i]);
        
        memset(dp, -1, sizeof(dp));
      
        fun(0, 3, k);  //first fill the dp table
        dfs(0, 3, k);  //then fill the ans array
      
        return ans;
    }
};
      
