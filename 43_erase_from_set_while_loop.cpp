//whenever I need to erase elements from a set using a while loop:


for (auto it = numbers.begin(); it != numbers.end(); ){   //for loop m DONT write it++
    if (*it % 2 == 0) {
        numbers.erase(it++);  //erase with it++
    }else{
        ++it;   //else mei it++
    }
}

