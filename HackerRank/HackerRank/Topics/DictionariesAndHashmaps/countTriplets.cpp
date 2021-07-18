#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
long triplets = 0;
unordered_map<long, int> freq;

//Debug code
ofstream fout(getenv("OUTPUT_PATH"));

//remove pairs + keep track of frequencies
for(long i=0;i<arr.size()-1;i++){
    if(arr[i]==arr[i+1]){
        freq[arr[i]]++;

        //Debug code
        //fout<<freq[arr[i]] << " a"<<i;
        arr.erase(arr.begin()+i);
        i--;
    }
}

triplets = triplets + (arr.size() - 2);

//This code does not account for the value being in multiple triplets
//need to complete below and go through to detrermine how many times
//a duplicate occurs in a triplet
fout<<triplets;
//Find Triplets and if frequency of a value is > 1, add (freq - 1) to 
//the total number of triplets
for(int i=0;i<arr.size()-1;i++){
   if(freq[arr[i]]>0){
       triplets = triplets + (freq[arr[i]]);
       fout<<triplets << " b";
   }
   
   if(freq[arr[i+1]]>0){
       triplets = triplets + (freq[arr[i+1]]);
       //Debug code
       fout<<triplets << " c";
   }
   
   if(freq[arr[i+2]]>0){
       triplets = triplets + (freq[arr[i+2]]);
       //Debug code
       fout<<triplets << " d";
   }
   //Debug code
   fout<<arr[i]<<freq[arr[i]]<<"e"<<arr[i+1]<<freq[arr[i+1]]<<"e"<<arr[i+2]<<freq[arr[i+2]]<<"e";
}
//Debug code
fout.close();

return triplets;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
