#include <iostream>
#include <string>

using namespace std;
typedef enum { False, True } boolean; 

// LCS function returning the length of longest common sunsequence for S1[0..m-1], S2[0..n-1]
void LCS(string S1, string S2)
{
    int m = S1.size(); //m storing the size of string S1
    int n = S2.size(); //n storing the size of string S2
    int LCS_table[m + 1][n + 1];
    int i = 0;
    int j = 0;
    // Nested for loops are creating LCS_table[m+1][n+1].
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
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
	if (S1[x - 1] == S2[y - 1]) {
		subsequence[length - 1] = S1[x - 1];
      		x--;
      		y--;
      		length--;
    	}

    	else if (LCS_table[x - 1][y] > LCS_table[x][y - 1])
      		x--;
    	else
      		y--;
    }
    cout << endl << "Length of Longest Common Subsequence = " << LCS_table[m][n];
    cout << endl << "Longest Common Subsequence = " << subsequence << endl;
    
    x = m;
    y = n;
    int no_of_deletion = x - LCS_table[x][y];
    int no_of_insertion = y - LCS_table[x][y];
    
    char deleted_array[no_of_deletion + 1];
    deleted_array[no_of_deletion] = '\0';
    cout << endl << "Minimum number of deletions = " << no_of_deletion;
    no_of_deletion = 0;
    y = 0;
    
    cout << endl << "Deletions from String no.1 ("<< S1 << ") at indexes =";
    for(x = 0; x <= m; x++){
        if (subsequence[y] != S1[x]){
            deleted_array[no_of_deletion] = S1[x];
            no_of_deletion++;
            cout << " " << x + 1;
        } 
        else{
            y++;
        }
    }    
    cout << endl << "Deletions from String no.1 ("<< S1 << ") ="; 
    for(x = 0; x <= no_of_deletion; x++){
        cout <<  " " << deleted_array[x];
    }
    cout << endl;
    
    char inserted_array[no_of_insertion + 1];
    inserted_array[no_of_insertion + 1] = '\0';
    cout << endl << "Minimum number of insertions = " << no_of_insertion;
    no_of_insertion = 0;
    y = 0;
    
    cout << endl << "Insertions in String no.1 ("<< S1 << ") at indexes =";
    for(x = 0; x <= n; x++){
        if (subsequence[y] != S2[x]){
            inserted_array[no_of_insertion] = S2[x];
            no_of_insertion++;
            cout << " " << x + 1;
        }
        else{
            y++;
        }
    }
    cout << endl << "Insertion in String no.1 ("<< S1 << ") after deletions =";
    for(x = 0; x <= no_of_insertion; x++){
        cout <<  " " << inserted_array[x] ;
    }
    cout << endl;
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
