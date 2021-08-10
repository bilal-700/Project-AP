#include <iostream>
#include <string>
 
using namespace std;
typedef enum { False, True } boolean; 

// LCS function returning the length of longest common sunsequence for S1[0..m-1], S2[0..n-1] and finding the LCS.
void LCS(string S1, string S2)
{
    int m = S1.size(); //m storing the size of string S1
    int n = S2.size(); //n storing the size of string S2
    int LCS_table[m + 1][n + 1];
 
    // Nested for loops are creating LCS_table[m+1][n+1].
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                LCS_table[i][j] = 0; //Initialzing the first row and column by zero
	    }
            else if (S1.at(i - 1) == S2.at(j - 1)) {
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1; //Case1: If both characters matches then diagnol entry plus one
	    }
            else {
                LCS_table[i][j] = max(LCS_table[i - 1][j], LCS_table[i][j - 1]); //Case2: If both characters do not match then find the maximum of left cell and upper cell
	    }
        }
    }

    int length = LCS_table[m][n];
    char subsequence[length + 1];
    subsequence[length] = '\0';

    int x = m, y = n;
    //for finding the longest common subsequence from the table
    while (x > 0 && y > 0) {
	if (S1[x - 1] == S2[y - 1]) {//If to characters are equal, move diagnolly up.
		subsequence[length - 1] = S1[x - 1];
      		x--;
      		y--;
      		length--;
    	}
	//If characters are not equal, then check the max of the upper and left cell and move towards it.
    	else if (LCS_table[x - 1][y] > LCS_table[x][y - 1])
      		x--;
    	else
      		y--;
    }

  cout << endl << "String no.1 = " << S1 << endl;
  cout << "String no.2 = " << S2 << endl;
  cout << endl << "Length of Longest Common Subsequence(LCS) = " << LCS_table[m][n];
  cout << endl << "Longest Common Subsequence(LCS) = " << subsequence << endl; //Printing the longest possible subsequences
}
 
int main()
{
    string S1 = "";
    string S2 = "";
    char key = ' ';
    boolean loop = True;
  
    while (loop){	
      cout << endl << "Enter the first string = ";
      getline(cin,S1);
      cout << "Enter the second string = ";
      getline(cin,S2);
      LCS(S1, S2);
      cout << endl;
      cout << "Enter 'r' to restart or any other key to exit" << endl;		
      cin >> key;
      if (key != 'r'){
	loop = False;
      }
      cin.clear();
      cin.ignore();
    }
    return 0;
}
