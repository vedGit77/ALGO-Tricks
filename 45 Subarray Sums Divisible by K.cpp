// Subarray Sums Divisible by K


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0, tot=0;
        unordered_map<int,int>m;
        m[0]++; //for case when 0 to index i has a tot sum divisible by k

        for(int i=0;i<nums.size();i++){
            tot += nums[i];
            int rem = tot%k;
            if(rem<0)   
                rem+=k;
            
            if(m.find(rem) != m.end())
                ans += m[rem];
            
            m[rem]++;
        }

        return ans;
    }
};
