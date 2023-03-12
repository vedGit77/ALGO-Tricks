POWER SET => 2 methods:
1. Recursive/Backtracking => O(2^N) => BETTER 
2. Iterative => O(N * 2^N)
  
  
// Recursive:

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

