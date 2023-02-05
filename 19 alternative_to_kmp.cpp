// string find in STL => can be used to find a string in another => same use as KMP

// IMP => BUT KMP IS BETTER

// Time complexiy: KMP = O(N)
// 	         : str.find() = O(N*M)....size of strings is N and M


int main()
{
	string s1 = "geeksforgeeksfrgeeks a computer science";
	string s2 = "geeks";

	size_t found = s1.find(s2);  		//IMP-1 : size_t
	if (found != string::npos)   		//IMP-2 : string::npos
		  cout << "First occurrence is " << found << endl;  	//IMP-3 : found gives the index

	found = s1.find(s2, found+1);   //IMP-4 : found+1 for next occurrence 
	if (found != string::npos)
		cout << "Next occurrence is " << found << endl;
	
	found = s1.find(s2, found+2);   //IMP-5 : found+2 for next to next occurrence 
	if(found != string::npos)
		cout << "Next to next occurrence is " << found << endl;

	return 0;
}


// O/P:
// First occurrence is 0
// Next occurrence is 8
// Next to next occurrence is 15
