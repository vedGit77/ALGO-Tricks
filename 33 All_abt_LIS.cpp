// LIS => longest increasing subsequence 




// In LIS => 2 types of questions:

// 1. find length of LIS => most optimal in O(N *logN) time

// 2. given an array 'nums' => construct an array 'dp' 
//    => where dp[i] = length of LIS considering ONLY [0,i] indices in nums, AND DEFINITELY including nums[i] in the LIS
//    => this comes handy in many dp questions
//    => optimal time: O(N^2)





//ANS_for_problem_1

int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> temp;
    temp.push_back(arr[0]);
    
    int len = 1;
    
    for(int i=1; i<n; i++)  //start from i=1
    {
        if(arr[i]>temp.back())
	{  
           temp.push_back(arr[i]);
           len++;  
        } 
        else  //else -> includes == wala case also -> example we have temp array as -> [1,2,9] -> now arr[i] is 2 -> since we take lower_bound -> temp remains same
	{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();    //DO NOT use uper_bound
            temp[ind] = arr[i];  //replace => DONT change len
        }
        
    }
    
    return len;
}







// ANS_for_problem_2

vector<int> fun(vector<int>&nums){
	int n = nums.size();
	vector<int>dp(n,1);  //initialize all dp[i]=1 => since for each element => length==1

	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<i;j++)  //NOTE: j<i
	    {
		if(nums[i]>nums[j])  //change dp[i] ONLY when nums[i]>nums[j]
		    dp[i] = max(dp[i], dp[j]+1);
	    }
	}

	return dp;
}
    
