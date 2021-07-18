#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string abbreviation(string a, string b) {

    unordered_map<long, int> aFreq;
    unordered_map<long, int> bFreq;
    bool yes = true;
    
    //find frequency of a letters
    for(int i=0;i<a.size();i++){
        if(a.at(i)<123 && a.at(i)>96){
            a.at(i) = a.at(i) - 32;
        }
        aFreq[a.at(i)]++;
    }
    
    //find frequency of b letters
    for(int i=0;i<b.size();i++){
        bFreq[b.at(i)]++;
    }

    //determine if letter freq of a is >= freq b
    for(int i=0;i<b.size();i++){
        cout<<b.at(i)<<"a "<<bFreq[b.at(i)]<<"b "<<aFreq[b.at(i)]<<"c ";
        if(aFreq[b.at(i)]<bFreq[b.at(i)]){
            yes = false;
            break;
        }
    }
    
    if(yes){
        return "YES";
    }
    return "NO";    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
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
