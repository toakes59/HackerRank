/*#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 

long arrayManipulation(int n, vector<vector<long>> queries) {
    long maxVal = 0;
    vector<long> calcArr(n);
    for(int i=0; i<n; i++){
        calcArr[i]=0;
    }
    
    //for loop that goes through all the queries
    for(int i = 0; i<queries.size(); i++){
        //for loop that goes throught the range a to b and adds k to them
        //where a = queries[i][0]-1, b = queries[i][1]-1, and k = queries[i][2]
        for(int j=queries[i][0]; j<=queries[i][1]; j++){
            //Performs calc on calcArr index
            calcArr[j-1]+=queries[i][2];
            
            //checks to see if the current calcArr value is larger than max
            if(maxVal<calcArr[j-1]){
                maxVal=calcArr[j-1];
            }
        }
    }
    
    return maxVal;
}*/
#include <iostream>

using namespace std;

//faster method from the help of the comments section
int main() {
    long int N,K,p,q,sum,i,j,max=0,x=0;

    cin>>N>>K;
    long int *a=new long int[N+1]();

    for(i=0;i<K;i++)
    {
        cin>>p>>q>>sum;
        a[p]+=sum;
        if((q+1)<=N) a[q+1]-=sum;
    }

    for(i=1;i<=N;i++)
    {
       x=x+a[i];
       if(max<x) max=x;

    }

    cout<<max;
    return 0;
}

/*
//Too slow
long arrayManipulation(int n, vector<vector<long>> queries) {
    long maxVal = 0;
    vector<long> calcArr(n);
    for(int i=0; i<n; i++){
        calcArr[i]=0;
    }
    
    //for loop that goes through all the queries
    for(int i = 0; i<queries.size(); i++){
        //for loop that goes throught the range a to b and adds k to them
        //where a = queries[i][0]-1, b = queries[i][1]-1, and k = queries[i][2]
        for(int j=queries[i][0]; j<=queries[i][1]; j++){
            //Performs calc on calcArr index
            calcArr[j-1]+=queries[i][2];
            
            //checks to see if the current calcArr value is larger than max
            if(maxVal<calcArr[j-1]){
                maxVal=calcArr[j-1];
            }
        }
    }
    
    return maxVal;
}

int main()
{
	int arrSize = 0;
	int minSwaps = 0;

	cout << "Enter Array: " << endl;
	cin >> arr;

	int* arr = new int[arrSize];

	minSwaps = minSawps(&arr, 0);

	cout << "Minimum Sawps is: " << minSwaps <<endl;

	return 0;
}

/*#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

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
*/
