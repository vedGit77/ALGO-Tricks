string find in STL => can be used to check 






int main()
{
	string s1 = "geeksforgeeks a computer science";
	string s2 = "geeks";

	size_t found = s1.find(s2);
	if (found != string::npos)
		  cout << "First occurrence is " << found << endl;

	found = s1.find(s2, found+1);
	if (found != string::npos)
		cout << "Next occurrence is " << found << endl;

	return 0;
}
