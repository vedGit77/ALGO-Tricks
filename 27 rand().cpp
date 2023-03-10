To generate random numbers:


int a = rand(); 
Here { 0 <= a < RAND_MAX } -> where RAND_MAX is a large value ... varies with implementation 


int a = rand()%n;
Here { 0 <= a <= n-1 } -> to get in range [0,n)

                                        
int range = maxi - mini + 1;
int a = rand()%range + mini;
Here { mini <= a <= maxi } -> to get in range [mini,maxi]
  
