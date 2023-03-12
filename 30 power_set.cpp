POWER SET => 2 methods:
1. Recursive/Backtracking => O(2^N) => BETTER 
2. Iterative => O(N * 2^N)
  
  
	
	
// Recursive/Backtrack:

void findPowerSet(char* s, vector<char> &res, int n){
	if (n == 0) {
		for (auto i: res)
			cout << i;
		cout << "\n";
		return;
	}
	
	res.push_back(s[n - 1]);
	findPowerSet(s, res, n - 1);
	res.pop_back();
	
	findPowerSet(s, res, n - 1);
}



// Iterative:

void printPowerSet(char* set, int set_size)
{
	// Set_size of power set of a set with set_size n is (2^n-1)
	unsigned int pow_set_size = pow(2, set_size);
	int counter, j;

	// Run from counter 000..0 to 111..1
	for (counter = 0; counter<pow_set_size; counter++) 
	{
		for (j = 0; j < set_size; j++) 
		{
			if (counter & (1 << j))
				cout << set[j];
		}
		cout << endl;
	}
}

