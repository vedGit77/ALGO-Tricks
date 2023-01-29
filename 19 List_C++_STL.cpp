// doubly linked list

// => As compared to vector, the list has slow traversal
// => but once a position has been found, insertion and deletion are quick


// Iteration:
list<int> g;
list<int>::iterator it;
for (it = g.begin(); it != g.end(); ++it)   //begin and end
    cout <<" "<< *it;
  

//push:
g.push_back(i);
g.push_front(i);


//Front and back:
g.front();
g.back();


//pop
g.pop_front();
g.pop_back();
 

//reverse
g.reverse();


//sort
g.sort();
