// Before Linear Diophantine Equations, some prerequisite:




// 1. Euclidean algorithm (GCD):
  
//   int gcd(int a, int b)
//   {
//       if (a == 0)
//           return b;
//       return gcd(b % a, a);
//   }






// 2. Extended Euclidean Algorithm: 

//   finds integer coefficients x and y such that:
//   ax + by = gcd(a, b) 
//   here-> a,b were given ... we can find gcd(a,b) ... now x and y are unknowns -> find them
    
//   # NOTE: for the above eqn, its GUARANTEED that x,y INTEGERS exist

// How to find (x,y)?
  
//   ax + by = gcd(a, b)  --- 1
//   gcd(a, b) = gcd(b%a, a)   ----2 ----we know this----from euclidean algo
  
//   gcd(b%a, a) = (b%a)x1 + ay1   ----using 1 and 2 --- now we have (x1,y1)
//   ax + by = (b%a)x1 + ay1   ----using 1 and 2
  
//   we know => dividend = divisor*quotient + remanider => use this => b = a*(b/a) + (b%a)

//   ax + by = (b – (b/a)*a)x1 + ay1
//   ax + by = a(y1 – (b/a)*x1) + bx1

//   Comparing LHS and RHS,
//   x = y1 – (b/a)*x1
//   y = x1

// Now, we can get x,y using a base case in recursion => when a==0 => GCD(a,b)==b => thus x==anything, y==1 => necessarily 



//this function returns GCD, and simultaneously updates x and y
int extendedEuclideanAlgorithm(int a, int b, int &x, int &y){  //x and y => passed by REFERENCE
      if(b==0){
          x=1;  //necessarily 1
          y=0;  //could be anything 
          return a;
      }

      int g = extendedEuclideanAlgorithm(b, a%b, x, y);  //see parameters -> (a, b, &x, &y) => (b, a%b, x, y)
  
      int x1 = x;
      int y1 = y;
  
      x = y1;  //as per the derivation above
      y = x1 - (a/b)*y1;

      return g;
  }


// main function -> returns vector {x,y} where ax+by = gcd(a,b)
  vector<int> gcd(int a, int b){
      vector<int> res;
      int x, y;

      int GCD = extendedEuclideanAlgorithm(a, b, x, y);

      res.push_back(x);
      res.push_back(y);

      return res;
  }









// --------------------PRE-REQUISITES OVER NOW-------------------------



// Linear Diophantine equation: ( ax + by = c ) -> given a,b,c -> find (x,y)

//Now this has 2 parts -> particular and general sol


// 1. PARTICULAR SOL:
// Find GCD of a and b
// if ( c % GCD(a ,b) == 0 ) => ONLY then sol. exists!!!  => ie. c is a multiple of gcd

// Now, if sol. exists:
// For given a and b => calculate the value of x1, y1 => and gcd using **Extended** Euclidean Algorithm.
// Calculate the solution of the equation as follows:
// x = x1 * ( c / gcd )
// y = y1 * ( c / gcd )



// Function to implement the extended euclid algorithm =>same as done before
int gcd_extend(int a, int b, int& x, int& y){
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	int g = gcd_extend(b, a%b, x, y);

	int x1 = x;
	int y1 = y;

	x = y1;
	y = x1 - (a / b) * y1;

	return g;
}

// Function to print the solutions of the given equations ax + by = c
void print_solution(int a, int b, int c){
	if (a == 0 && b == 0) {
		if (c == 0) 
			cout<< "Infinite Solutions Exist"<< endl;
		else 
			cout<< "No Solution exists"<< endl;
	}
	
	int x, y;
	int gcd = gcd_extend(a, b, x, y);

	if (c % gcd != 0) {
		cout<< "No Solution exists"<< endl;
	}else{
		cout << "x = " << x * (c / gcd) << ", y = " << y * (c / gcd) << endl;  //x = x1 * ( c / gcd )  //y = y1 * ( c / gcd )
	}
}

int main(void)
{
	int a, b, c;

	a = 4;
	b = 18;
	c = 10;

	print_solution(a, b, c);
	return 0;
}





        
