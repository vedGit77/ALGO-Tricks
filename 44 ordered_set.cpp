//GENERAL NOTE: throughout the code-> jaha bhi header files wale part mei maine 'int' likha hai
//              i can change that to 'long long int' or 'doulbe' based on my requirement


//same as set
//can do extra operations: 
//1. order_of_key(k) : Number of items STRICTLY smaller than k .
//2. find_by_order(k) : K-th element in a set (counting from ZERO) -> returns an ITERATOR to it

//both in O(log N)

// below, i have implemented:
// insert, erase, order_of_key, find_by_order


//below this code, i will discuss how to implement ordered_set for duplicate elements as well


#include <iostream>
using namespace std;

//below 4 lines => make us able to run ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
  	//VVIMP=> **DONT** write ordered_set<int> o_set;
	ordered_set o_set; //declaration 

	// insert function to insert in ordered set same as SET STL
	o_set.insert(5);
	o_set.insert(1);
	o_set.insert(2);

	// Finding the second smallest element in the set using * because find_by_order returns an iterator
	cout << *(o_set.find_by_order(1)) << endl;

	// Finding the number of elements strictly less than k=4
	cout << o_set.order_of_key(4)<< endl;

	// Deleting 2 from the set if it exists
	if (o_set.find(2) != o_set.end())
		o_set.erase(o_set.find(2));

	return 0;
}



//for duplicate elements, a few changes will be made:
//1. typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_pair;
//   basically upar maine int likha tha-> idhar maine pair<int,int> likha hai -> and changed name from ordered_set to ordered_set_pair
//2. order_of_key(): returns the number of elements strictly less than the key. 
//   implementation-> 
//   while inserting-> insert {arr[i], i} -> where i is the index
//   while finding num of elements less than key-> pass a pair whose (first value is number which we want the result for) and (second value will contain a negative value e.g., -1) 
//   because the inserted pairs in the ordered_set_pair will have the value greater than equal to 0 as it denotes the indexes of the array.
//3. find_by_order(): index as a parameter and returns an iterator to the ith element (pair) in sorted order.



// Header files to implement ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// Declaring ordered_set for pair<int,int>
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_pair;

int main(){
	int arr[10] = {4, 7, 2, 4, 5, 8, 4, 1, 3, 5};
	
	//VVIMP => DONT write=> ordered_set_pair <pair<int,int>> mySet
	ordered_set_pair mySet;
	
	for(int i = 0; i < 10; i++){
		mySet.insert({arr[i], i});
	}

	// count of elements less than 5
	cout << "Count of elements less than 5: " <<
			mySet.order_of_key({5, -1}) << endl;

	// Print 8th element in the ordered set iterator to a pair
	auto itr = mySet.find_by_order(8);
	cout << "The 8th element in the ordered set is: " <<
			(*itr).first << endl;
	return 0;
}


