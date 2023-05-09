// Submask of a given mask is a mask whose set bits are a subset of the given mask. 
// For eg=> 1010, 1000, 0010 are submasks of 1011, while 1100 is not a submask.


int new_mask = mask;

while(new_mask != 0)
{
    new_mask = (new_mask-1) & mask;
    cout<<new_mask<<endl;
}
