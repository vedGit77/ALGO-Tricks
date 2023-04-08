// Given a text txt[0. . .n-1] and a pattern pat[0. . .m-1],
// write a function that prints all occurrences of pat[] in txt[]. 
// You may assume that n > m.


hash(txt[s+1 .. s+m]) = ( d*{ hash(txt[s .. s+m-1]) – txt[s]* h } + txt[s + m] ) % q

// hash( txt[s .. s+m-1] ) : Hash value at shift s
// hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1) 

// d: Number of characters in the alphabet 
// q: A prime number 
// h: d^(m-1)

// Example: pattern length is 3 and string is “23456” 
// You compute the value of the first window (which is “234”) as 234. 
// How will you compute the value of the next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.



// d is the number of characters in the input alphabet
#define d 256

void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first window of text
	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) {

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j]) {
					break;
				}
			}

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
			if (j == M)
				cout << "Pattern found at index " << i<< endl;
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if (i < N - M) {
			t = ( d*(t - txt[i]*h) + txt[i + M]) % q;

			// We might get negative value of t, converting it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

int main()
{
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEK";

	// we mod to avoid overflowing of value but we should
	// take as big q as possible to avoid the collison
	int q = INT_MAX;

	// Function Call
	search(pat, txt, q);
	return 0;
}

