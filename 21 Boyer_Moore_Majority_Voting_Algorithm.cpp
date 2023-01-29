// used to find the majority element among the given elements that have more than N/2 occurrences. 
// takes 2 traversals over the given elements
// works in O(N) time complexity and O(1) space complexity



int findMajority(int arr[], int n)
{
	int i, candidate = -1, votes = 0;
	// Finding majority candidate
	for (i = 0; i < n; i++) {
      if (votes == 0) {
        candidate = arr[i];
        votes = 1;
      }
      else{
          if (arr[i] == candidate)
            votes++;
          else
            votes--;
      }
	}
  
	int count = 0;
	
  // Checking if majority candidate occurs more than n/2 times
	for (i = 0; i < n; i++) {
		if (arr[i] == candidate)
			count++;
	}

	if (count > n/2)
	  	return candidate;
	return -1;
}
