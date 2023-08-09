//LEETCODE: 373. Find K Pairs with Smallest Sums

// You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
// Define a pair (u, v) which consists of one element from the first array and one element from the second array.
// Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int, vector<int>>>pq;

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)
                    pq.push({sum, {nums1[i], nums2[j]}});
                else if(sum < pq.top().first){
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }else{
                    break;
                }
            }
        }

        while(pq.size()>0){
            vector<int>v = pq.top().second;
            ans.push_back(v);
            pq.pop();
        }

        return ans;
    }
};
