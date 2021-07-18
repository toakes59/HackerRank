#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'stepPerms' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
 
//faster way
static int steps(int n) {
    int arr[3] = {1,2,4};
    if (n < 4) return arr[n - 1];
    for (int i = 5; i <= n; i++){
        arr[(i + 1) % 3] = arr[0] + arr[1] + arr[2];
    }
    return arr[0] + arr[1] + arr[2];
}

//Too Slow
/*
int stepPerms(int n) {
    int ret = 0;
    
    if(n>3){
        ret = stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3);
    }
    else if(n==3){
        return 4;
    }
    else if(n==2){
        return 2;
    }
    else{
        return 1;
    }
    
    return ret%10000000007;
}*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));

    for (int s_itr = 0; s_itr < s; s_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int res = steps(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
