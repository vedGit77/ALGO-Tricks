//VERY SIMPLE

// For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. 
// If we calculate the such area for every bar ‘x’ and find the maximum of all areas, our task is done. 

// How to calculate the area with ‘x’ as the smallest bar? 
// get index of 1st smaller element on left of 'x'
// get index of 1st smaller element on right of 'x'

// simple use NEXT SMALLER ELEMENT concept

// calculate area



class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int ans = 0, n = height.size();

        stack<pair<int,int>>left_small, right_small;  //value, index

        vector<int>left(n), right(n);

        for(int i=0; i<n; i++){
            if(left_small.size() == 0){
                left_small.push({height[i], i});
                left[i] = -1;
            }else{
                while(left_small.size()>0 && left_small.top().first>=height[i])
                    left_small.pop();
                
                if(left_small.size()>0)
                    left[i] = left_small.top().second;
                else
                    left[i] = -1;
                
                left_small.push({height[i], i});
            }
        }

        for(int i=(n-1); i>=0; i--){
            if(right_small.size() == 0){
                right_small.push({height[i], i});
                right[i] = n;
            }else{
                while(right_small.size()>0 && right_small.top().first>=height[i])
                    right_small.pop();
                
                if(right_small.size()>0)
                    right[i] = right_small.top().second;
                else
                    right[i] = n;
                
                right_small.push({height[i], i});
            }
        }

        for(int i=0;i<n;i++){
            int till_left = left[i]+1;
            int till_right = right[i]-1;

            ans = max(ans, height[i]*(till_right - till_left + 1));
        }

        return ans;
    }
};
