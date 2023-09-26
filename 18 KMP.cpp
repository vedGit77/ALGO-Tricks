// QUESTION:
// Given a text txt[0..N-1] and a pattern pat[0..M-1] => You may assume that N > M. 
// prints all occurrences of pat[] in txt[]




// COMPLEXITY:
// The worst-case complexity => Naive algorithm => O(m*n). 
// The worst-case complexity => KMP algorithm => O(n).




// The basic => KMP’s algorithm => whenever we detect a mismatch (after some matches), 
// we already know some of the characters in the text of the next window. 
// We take advantage of this information to avoid matching the characters that we know will anyway match. 




// Example:
// Input:  txt[] =  “AABAACAADAABAABA”
//         pat[] =  “AABA”
// Output: 0, 9, 12





// Matching Overview:

// txt = “AAAAABAAABA” 
// pat = “AAAA”

// We compare first window of txt with pat
// txt = “{AAAA}ABAAABA” 
// pat = “AAAA”  [Initial position]
// We find a match. This is same as Naive String Matching.

// In the next step, we compare next window of txt with pat.
// txt = “A{AAAA}BAAABA” 
// pat =  “AAAA” [Pattern shifted one position]

// This is where KMP does optimization over Naive. In this second window, we only compare fourth A of pattern
// with fourth character of current window of text to decide whether current window matches or not. Since we know 
// first three characters will anyway match, we skipped matching first three characters. 

// Need of Preprocessing?
  
// An important question arises from the above explanation, how to know how many characters to be skipped. To know this, 
// we pre-process pattern and prepare an integer array lps[] that tells us the count of characters to be skipped.

// Preprocessing Overview:
// preprocess pat[] => constructs an auxiliary lps[] of size m (same as the size of the pattern) => used to skip characters while matching.
// name lps indicates the **longest proper prefix which is also a suffix**.
// A proper prefix is a prefix with a whole string not allowed. 
//     For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”. Proper prefixes are “”, “A” and “AB”. 
//     Suffixes of the string are “”, “C”, “BC”, and “ABC”.
// We focus on **sub-strings of patterns that are both prefix and suffix**.
// For each sub-pattern pat[0..i] (i = 0 to m-1) => lps[i] stores => length of MAX matching proper prefix which is also a suffix of the sub-pattern pat[0..i].

//  =>  lps[i] = the longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]

// Examples of lps[] construction:
// =>“AAAA”, lps[] is [0, 1, 2, 3]
// =>“ABCDE”, lps[] is [0, 0, 0, 0, 0]
// =>“AAACAAAAAC”, lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4] 





// Preprocessing Algorithm:
// => Calculate values in lps[]. For that => keep track of the length of the longest prefix suffix value (use len variable for this) for the PREVIOUS index
// => initialize lps[0] and len as 0
// => If pat[len] and pat[i] match, we increment len by 1 and assign the incremented value to lps[i].
// => If pat[i] and pat[len] do not match 
//      a) len>0 => update len to lps[len-1]
//      b) len==0 => do => lps[i]=0 and i++



// Illustration of preprocessing (or construction of lps[]):

// pat[] = “AAACAAAA”

// len = 0, i  = 0.
// lps[0] is always 0, we move 

// to i = 1
// len = 0, i  = 1.

// Since pat[len] and pat[i] match, 
// do len++, 
// store it in lps[i] and do i++.
// len = 1, lps[1] = 1, i = 2

// len = 1, i  = 2.

// Since pat[len] and pat[i] match, 
// do len++, 
// store it in lps[i] and do i++.
// len = 2, lps[2] = 2, i = 3

// len = 2, i  = 3.

// Since pat[len] and pat[i] do not match, and len > 0, 
// len = lps[len-1] = lps[1] = 1

// len = 1, i  = 3.

// Since pat[len] and pat[i] do not match and len > 0, 
// len = lps[len-1] = lps[0] = 0

// len = 0, i  = 3.

// Since pat[len] and pat[i] do not match and len = 0,  
// Set lps[3] = 0 and i = 4.
// We know that characters pat 

// len = 0, i  = 4.

// Since pat[len] and pat[i] match, 
// do len++, 
// store it in lps[i] and do i++. len = 1, lps[4] = 1, i = 5

// len = 1, i  = 5.

// Since pat[len] and pat[i] match, 
// do len++, 
// store it in lps[i] and do i++.

// len = 2, lps[5] = 2, i = 6
// len = 2, i  = 6.

// Since pat[len] and pat[i] match, 
// do len++, 
// store it in lps[i] and do i++.

// len = 3, lps[6] = 3, i = 7
// len = 3, i  = 7.

// Since pat[len] and pat[i] do not match and len > 0,
// set len = lps[len-1] = lps[2] = 2

// len = 2, i  = 7.

// Since pat[len] and pat[i] match, \
// do len++, 
// store it in lps[i] and do i++.
// len = 3, lps[7] = 3, i = 8

// We stop here as we have constructed the whole lps[].








// Implementation of KMP algorithm:
// Unlike the Naive algorithm, where we slide the pattern by one and compare all characters at each shift, 
// we use a value from lps[] to decide the next characters to be matched. The idea is to NOT match a character that we know will anyway match.

// How to use lps[] to decide the the number of characters to be skipped?

// We start the comparison of pat[j] with j = 0 with characters of the current window of text.
// We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.

// When we see a mismatch
// We know that characters pat[0 ... j-1] match with txt[i-j ... i-1] 

// => (Note that j starts with 0 and increments it only when there is a match).
// => We also know (from the above definition) that lps[j-1] is the count of characters of pat[0…j-1] that are both proper prefix and suffix.
// From the above two points => confirmed => we do NOT need to match these lps[j-1] characters with txt[i-j … i-1] => we know that they already match.






// Below is the illustration of the above algorithm:

// txt[] = “AAAAABAAABA” , pat[] = “AAAA”
// lps[] = {0, 1, 2, 3} 

// i = 0, j = 0

// txt[] = “AAAAABAAABA” 
// pat[] = “AAAA”
// txt[i] and pat[j] match, do i++, j++

// i = 1, j = 1

// txt[] = “AAAAABAAABA” 
// pat[] = “AAAA”
// txt[i] and pat[j] match, do i++, j++

// i = 2, j = 2

// txt[] = “AAAAABAAABA” 
// pat[] = “AAAA”
// pat[i] and pat[j] match, do i++, j++

// i = 3, j = 3

// txt[] = “AAAAABAAABA” 
// pat[] = “AAAA”
// txt[i] and pat[j] match, do i++, j++

// i = 4, j = 4

// Since j == M, print pattern found and reset j,                ********IMP********
// j = lps[j-1] = lps[3] = 3

// Here unlike Naive algorithm, we do not match first three 
// characters of this window. Value of lps[j-1] (in above step) gave us index of next character to match.

// i = 4, j = 3

// txt[] = “AAAAABAAABA” 
// pat[] =  “AAAA”
// txt[i] and pat[j] match, do i++, j++

// i = 5, j = 4

// Since j == M, print pattern found and reset j, j = lps[j-1] = lps[3] = 3

// Again unlike Naive algorithm, we do not match first three 
// characters of this window. Value of lps[j-1] (in above step) gave us index of next character to match.

// i = 5, j = 3

// txt[] = “AAAAABAAABA” 
// pat[] =   “AAAA”
// txt[i] and pat[j] do NOT match and j > 0, change only j
// j = lps[j-1] = lps[2] = 2

// i = 5, j = 2

// txt[] = “AAAAABAAABA” 
// pat[] =    “AAAA”
// txt[i] and pat[j] do NOT match and j > 0, change only j
// j = lps[j-1] = lps[1] = 1 

// i = 5, j = 1

// txt[] = “AAAAABAAABA” 
// pat[] =     “AAAA”
// txt[i] and pat[j] do NOT match and j > 0, change only j
// j = lps[j-1] = lps[0] = 0

// i = 5, j = 0

// txt[] = “AAAAABAAABA” 
// pat[] =      “AAAA”
// txt[i] and pat[j] do NOT match and j is 0, we do i++.            *******IMP*******

// i = 6, j = 0

// txt[] = “AAAAABAAABA” 
// pat[] =       “AAAA”
// txt[i] and pat[j] match, do i++ and j++

// i = 7, j = 1

// txt[] = “AAAAABAAABA” 
// pat[] =       “AAAA”
// txt[i] and pat[j] match, do i++ and j++

// We continue this way till there are sufficient characters in the text to be compared with the characters in the pattern...






void KMPStringSearch(char* pat, char* str) {
    int M = strlen(pat);
    int N = strlen(str);
  
    int lps[M];
    computeLPSArray(pat, M, lps);
  
    int i = 0; 
    int j = 0;
    while (i < N) {
        if (pat[j] == str[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            printf("Found pattern at index %d ", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != str[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
  
void computeLPSArray(char* pat, int M, int* lps) {
        int len = 0;
  
    lps[0] = 0;   
       int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else{
           if (len != 0) {
                len = lps[len - 1];
           }
            else             {
                lps[i] = 0;
                i++;
            }
        }
    }
}

