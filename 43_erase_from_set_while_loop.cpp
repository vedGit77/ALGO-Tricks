//whenever I need to erase elements from a set using a while loop:

WITH FOR LOOP:

for (auto it = numbers.begin(); it != numbers.end(); ){   //for loop m DONT write it++
    if (*it % 2 == 0) {
        numbers.erase(it++);  //erase with it++
    }else{
        ++it;   //else mei it++
    }
}


WITH WHILE LOOP:

while(itr != s.end()){
    ...some code...
    s.erase(itr++);  //IMP trick
}
