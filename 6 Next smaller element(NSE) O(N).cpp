// A Stack based C++ program to find next smaller element for all array elements
// Time and space: O(N)

#include <bits/stdc++.h>
using namespace std;

void printNSE(int arr[], int n)
{
	stack<pair<int, int> > s;
	vector<int> answer(n);  //this is our ans array

	for (int i = 0; i < n; i++) 
  	{
	      int next = arr[i];
	      // if stack is empty then this element can't be NSE for any other element,
	      //so just push it to stack so that we can find NSE for it, and continue
	      if (s.empty()) 
	      {
		s.push({ next, i });  // push {element,index}
		continue;
	      }

	      // while stack is not empty and the top element is greater than next
	      // a) NSE for top is next, use top's index to maintain original order
	      // b) pop the top element from stack

	      while (!s.empty() && s.top().first > next) 
	      {
		answer[s.top().second] = next;
		s.pop();
	      }

	      // push next to stack so that we can find NSE for it

	      s.push({ next, i });
	}

	// After iterating over the loop, the remaining elements
	// in stack do not have any NSE, so set -1 for them

	while (!s.empty()) 
        {
		answer[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) 
  	{
		cout << arr[i] << " ---> " << answer[i] << endl;
	}
}

int main()
{
	int arr[] = { 11, 13, 21, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printNSE(arr, n);
	return 0;
}
// Output
// 11 ---> 3
// 13 ---> 3
// 21 ---> 3
// 3 ---> -1
