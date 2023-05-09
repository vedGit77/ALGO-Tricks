1. if we are using multiset (or multimap):
   say we have {1,2,2,2,3,4} in the multiset
   if we do => set_name.erase(2) => ALL 2's are erased
   to erase a single element => set_name.erase(set_name.lower_bound(2))
     
//time complexity of next/prev = O(log N)
      
2. auto itr = next(mp.begin(), k); // returns kth iterator forward from specified iterator (begin in this case) => for map/set/multimap/multiset

3. auto mid = next(mp.begin(), k);
   auto p = prev(mid, v);   // gives Vth iterator backwards from the specified iterator (mid in this case)

4. in set/map => we can NOT do like vectors => ie:
   auto itr = v.begin()+4; -> {this +4} can do in vectors, but NOT in set/map
   
   so, if we want the last iterator -> simply do-> auto itr = s.rbegin(); ->instead of traversing whole set/map
   
   BUT-> another issue -> say now we want to delete this last iterator of the set
   we can NOT do -> { auto itr = s.rebgin(); s.erase(itr); }
   we can NOT do this because itr is NOT general iterator, its reverse iterator -> NOT used in 'erase' in cpp
   
   in such a case, do this-> { auto itr = prev(s.end()); s.erase(itr); }
   this wil work!
   
