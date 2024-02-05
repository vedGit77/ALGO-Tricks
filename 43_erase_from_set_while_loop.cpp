//whenever I need to erase elements from a set using a while loop:

auto itr = s.begin();
while(itr!=s.end()){
    if(...condn for erase...)
        s.erase(itr++);
    else
        itr++;
}
