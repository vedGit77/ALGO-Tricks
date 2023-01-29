// For both next_permutation and prev_premutation => time complexity = O(N)


// next_permutation:
//used to rearrange the elements in the range [first, last) into the next lexicographically greater permutation
//NOTE => see above => last index is NOT included

int arr[] = { 1, 2, 3 };

do {
    cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
} while (next_permutation(arr, arr + 3));



// prev_permutation:
// used to rearranges the elements in the range [first, last) into the previous lexicographically-ordered permutation
//NOTE => see above => last index is NOT included

int arr[] = { 1, 2, 3 };
 
sort(arr, arr + 3);
reverse(arr, arr + 3);  //sort and reverse since we want prev perm

do {
    cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
} while (prev_permutation(arr, arr + 3));
