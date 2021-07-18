#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {

    int openP=0, closeP=0, openB=0, closeB=0, openS=0, closeS=0;

    for(int i=0; i<s.length();i++){
        switch (s.at(i)){
            case '{':
                openS++;
                break;
            case '}':
                closeS++;
                break;
            case '[':
                openB++;
                break;
            case ']':
                closeB++;
                break;
            case '(':
                openP++;
                break;
            case ')':
                closeP++;
                break;
        }
    }

    if(openP==closeP&&openB==closeB&&openS==closeS){
        return "YES";
    }

    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
