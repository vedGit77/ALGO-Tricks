// Given an array of positive numbers
// find the smallest positive integer value that can NOT be represented as the sum of elements of any subset of a given set. 

// time complexity : O(nlogn)
// if array is already sorted : O(n)



//EXAMPLES:
// Input:  arr[] = {1, 10, 3, 11, 6, 15};
// Output: 2

// Input:  arr[] = {1, 1, 1, 1};
// Output: 5

// Input:  arr[] = {1, 1, 3, 4};
// Output: 10

// Input:  arr[] = {1, 2, 5, 10, 20, 40};
// Output: 4




// Using a simple loop, we can solve this problem in O(N log N) time
// Let the input array be arr[0..n-1]. 
// We first sort the array in non-decreasing order. 

// Let the smallest element that cannot be represented by elements at indexes from 0 to (i-1) be ‘res’.  
// We initialize ‘res’ as 1 (smallest possible answer) and traverse the given array from i=0.  

// There are the following 2 possibilities when we consider element at index i:
// 1. We decide that ‘res’ is the final result: If arr[i] is greater than ‘res’, then we found the gap which is ‘res’ because the elements after arr[i] are also going to be greater than ‘res’.
// 2. The value of ‘res’ is incremented after considering arr[i]: If arr[i] is not greater than ‘res’, the value of ‘res’ is incremented by arr[i] so ‘res’ = ‘res’+arr[i] 
//    (why? If elements from 0 to (i-1) can represent 1 to ‘res-1’, then elements from 0 to i can represent from 1 to ‘res + arr[i] – 1’ by adding arr[i] to all subsets that represent 1 to ‘res-1’ which we have already determined to be represented)



long long smallestpositive(vector<long long> arr, int n) {
    long long int res = 1;

    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < n && arr[i] <= res; i++){
        res = res + arr[i];
    }
  
    return res;
}
