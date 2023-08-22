//whenever I need to rease elements from a set using a while loop:

while(itr != s.end()){
    ...some code...
    itr = s.erase(itr);  //IMP trick
}

//Another method:

while(itr != s.end()){
    ...some code...
    s.erase(itr++);  //IMP trick
}
