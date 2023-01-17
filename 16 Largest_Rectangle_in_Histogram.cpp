// For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. 
// If we calculate the such area for every bar ‘x’ and find the maximum of all areas, our task is done. 

// How to calculate the area with ‘x’ as the smallest bar? 

// We need to know the index of the (first smaller than ‘x’) bar on the left of ‘x’ and the index of the (first smaller bar) on the right of ‘x’. 
// Let us call these indexes as ‘left index’ and ‘right index’ respectively. 
  
// We traverse all bars from left to right and maintain a stack of bars. Every bar is pushed to stack once. 
// A bar is popped from the stack when a bar of smaller height is seen. 
// When a bar is popped, we calculate the area with the popped bar as the smallest bar. 

// How do we get the left and right indexes of the popped bar?
// The current index tells us the right index and the index of the previous item in the stack is the left index.



int getMaxArea(int hist[], int n)
{
	stack<int> s;                // The stack holds indexes of hist[] array. The bars stored in stack are ALWAYS IN INCREASING ORDER of heights.

	int max_area = 0;            // Initialize max area
	int tp;                      // To store top of stack
	int area_with_top;           // To store area with top bar as the smallest bar


  int i = 0;
	while (i < n) {
    
		if (s.empty() || hist[s.top()] <= hist[i]){
			s.push(i);
	      		i++;
	    	}

		// If this bar is lower than top of stack, then calculate area of rectangle with stack top as the smallest (or minimum height) bar.
		// 'i' is 'right index' for the top and element before top in stack is 'left index'.
		else {
			tp = s.top(); // store the top index
			s.pop(); // pop the top

			area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);  // Calculate the area with hist[tp] stack as smallest bar

      			max_area = max(max_area, area_with_top);
		}
    
	}

	// Now pop the REMAINING BARS from stack and calculate
	// area with every popped bar as the smallest bar
	while (s.empty() == false) {
		tp = s.top();
		s.pop();
		area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

		max_area = max(max_area, area_with_top);
	}

	return max_area;
}
