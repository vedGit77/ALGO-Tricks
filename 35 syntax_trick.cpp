1. if we are using multiset (or multimap):
   say we have {1,2,2,2,3,4} in the multiset
   if we do => set_name.erase(2) => ALL 2's are erased
   to erase a single element => set_name.erase(set_name.lower_bound(2))
     
//time complexity of next/prev = O(log N)
      
2. auto itr = next(mp.begin(), k); // returns kth iterator forward from specified iterator (begin in this case) => for map/set/multimap/multiset

3. auto mid = next(mp.begin(), k);
   auto p = prev(mid, v);   // gives Vth iterator backwards from the specified iterator (mid in this case)
