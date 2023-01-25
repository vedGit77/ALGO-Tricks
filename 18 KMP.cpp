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


