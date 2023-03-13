// Given an array of integers,
// every element appears k (k > 1) times EXCEPT for one, which appears p times (p >= 1  AND  p%k != 0). 
// Find that single one. 



int singleNumber(vector<int>& s) {
    vector<int> t(32);////Made a array contain 32 elements.
    int sz = s.size();
    int i, j, n;

    for (i = 0; i < sz; ++i)
    {
        n = s[i];
        for (j = 31; j >= 0; --j)
        {
            t[j] += n & 1;//Find the last digit.
            n >>= 1;
            if (!n)
                break;
        }
    }

    int res = 0;
    for (j = 31; j >= 0; --j)
    {
        n = t[j] % 3;//"3" represents k times. 
        if (n)
            res += 1 << (31 - j);
    }
    return res;
}
