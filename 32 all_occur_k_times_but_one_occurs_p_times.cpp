// Given an array of integers,
// every element appears k (k > 1) times EXCEPT for one, which appears p times (p >= 1  AND  p%k != 0). 
// Find that single one. 



int fun(vector<int>& s) 
{
    vector<int> t(32);    //array of 32 elements-> considering 32-bit integers -> stores how many times a number occurred (by incrementing elements in t by 1) -> example: number is 3 -> in binary -> 11 -> so t[31]++ and t[30]++
    int sz = s.size();
    int i, j, n;

    for (i = 0; i < sz; i++)   //for each array element
    {
        n = s[i];
        for (j = 31; j >= 0; j--)  //IMP=> [31 ---> 0]
        {
            t[j] += (n&1);  // update t[j] by finding the last digit
            n = n>>1;
            
            if (n==0)
                break;
        }
    }

    int res = 0;
    for (j = 31; j >= 0; j--)
    {
        n = t[j]%k; //now n will be either 0 or p ---> logical ---> 0 when numbers containing that bit occurred in multiples of k ---> p when the number occurring p times also has that bit set
        
        if (n != 0)
            res += ( 1 << (31-j) );
    }
    return res;
}
