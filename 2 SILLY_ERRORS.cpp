//SORT MAP by value

class Solution {
public:
    static bool mycmp(pair<int,int>&a ,pair<int,int>&b)  //take care to use STATIC! , and use '&' with both the arguments
    {
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
  
    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int, int> mapp;
        vector<pair<int, int>> v;
                
        sort(v.begin(), v.end(), mycmp);  //this cmp function can be applied to vector pairs...NOT MAPS...throws error
          
        ...further code...
      
    }
};
