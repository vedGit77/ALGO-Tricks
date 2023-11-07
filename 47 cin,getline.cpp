// problem with cin => does NOT consider string with ' '

string s;
cin>>s;
cout<<s<<endl;

// vedant gupta =>input
// vedant  =>output


// solved using getline => getline breaks ONLY when i press 'ENTER'

string s;
getline(cin, s);
cout<< s <<endl;

// vedant gupta =>input
// vedant gupta =>output
