// Given the number of pages in N different books and M students.
// The books are arranged in ascending order of the number of pages. 
// Every student is assigned to read some consecutive books. 
// The task is to assign ALL books in such a way that the maximum number of pages assigned to a student is minimum. 
  



// IMP: N books => each book ka pages are given => sort them in ascending order
//    : M students
//    : each student MUST have atleast 1 book
//    : student MUST read CONSECUTIVE books
//    : we MUST distribute ALL books




// Example : 
// pages[] = {12, 34, 67, 90} , m = 2
// answer : 113

// Explanation: There are 2 number of students. Books can be distributed in following fashion : 
// 1) [12] and [34, 67, 90] Max number of pages is allocated to student ‘2’ with 34 + 67 + 90 = 191 pages
// 2) [12, 34] and [67, 90] Max number of pages is allocated to student ‘2’ with 67 + 90 = 157 pages 
// 3) [12, 34, 67] and [90] Max number of pages is allocated to student ‘1’ with 12 + 34 + 67 = 113 pages

// Of the 3 cases, Option 3 has the minimum pages = 113.





// approach is binary search




bool isPossible(int arr[], int n, int m, int curr_min)
{
	int studentsRequired = 1;
	int curr_sum = 0;

	// iterate over all books
	for (int i = 0; i < n; i++) {
		
		if (arr[i] > curr_min)
			return false;

		if (curr_sum + arr[i] > curr_min) 
		{

			studentsRequired++;

			curr_sum = arr[i];

			if (studentsRequired > m)
				return false;
		}
		else
		{
			curr_sum += arr[i];
		}
	}
	
	return true;
}

// function to find minimum pages
int findPages(int arr[], int n, int m)
{
	if (n < m) 	 // return -1 if no. of books is less than no. of students
		return -1;
	
	long long sum = 0;  // to Count total number of pages => upper-limit for binary search 
	int mx = INT_MIN;   // book with max pages => kisi na kisi student ko assign hogi => lower-limit for binary search

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		mx = max(mx, arr[i]);
	}

	int start = mx, end = sum;
	int result = INT_MAX;

	while (start <= end) 
	{
		int mid = (start + end) / 2;
		
		if (isPossible(arr, n, m, mid)) {
			
			result = mid;

			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}

	return result;
}

