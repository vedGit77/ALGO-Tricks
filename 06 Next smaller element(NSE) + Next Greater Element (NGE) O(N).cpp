// A Stack based C++ program to find next smaller element for all array elements
// Time and space: O(N)

// we are writing code for NSE => almost similar approach for NGE

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

	      while (!s.empty() && s.top().first > next) //stop when stack is empty or next is smaller than s.top().first
	      {
		    answer[s.top().second] = next;  //if next is smaller....then NSE for element at that index = next
		    s.pop();  
	      }

	      s.push({ next, i }); // push next to stack so that we can find NSE for it
	}

	while (!s.empty())   //the remaining elements in stack do not have any NSE, so set -1 for them
        {
		answer[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) //print
		cout << arr[i] << " ---> " << answer[i] << endl;
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
