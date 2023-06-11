// say we are given an array: 
// array  =>  [1, 3, 5, 7]
// indices=>  [0, 1, 2, 3]

// we need to find dist bw all pairs (i,j) -> NOTE: do NOT count (j,i)ka distance -> otherwise it will be counted 2x 
 
  
int ans=0, pre=0;
for(int i=0; i<n; i++){
    ans += (i*v[i] - pre);
    pre += v[i];
}
return ans;


// ans is our answer
// pre is prefix sum

Explanation:
// Imagine we have the array [1, 3, 5, 7]. Let's go through it backwards. 
// To compute the distance of all pairs (i, j) when 7 is i, we follow this procedure: 
// There are [index] numbers behind 7. 
// If they were all 7, then their sum would be 21. 
// Because we have a prefix sum, we know that their sum is 9 instead, which means they in total have a distance of 12 from 7. 
  
// We repeat this procedure for 5, 3, and 1. 
// Note that when 5 is i in the pair (i, j) then we are never comparing its distance from 7, because we already counted 7 as i previously. 
// So for the number 5, we only look at 3 and 1 behind it and calculate the deviation from the expected distance.

