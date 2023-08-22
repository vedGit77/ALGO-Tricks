//whenever I need to rease elements from a set using a for/while loop:

for (auto it = numbers.begin(); it != numbers.end(); ) {
    if (.....){
        it = numbers.erase(it);    //this is the TRICK !!!! => VVIMP
    }else{
        ++it;
    }
}

//another way we can write it:

for (auto it = numbers.begin(); it != numbers.end(); ) {
    if (.....){
        numbers.erase(it++);    //this is the TRICK !!!! => VVIMP
    }else{
        ++it;
    }
}
