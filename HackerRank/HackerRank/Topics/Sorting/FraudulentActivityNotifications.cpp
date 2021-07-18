#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */
 
 // Complete the activityNotifications function below.
int getTwiceMedian( vector<int> &A, vector<int> &count,int d)
{
    vector<int> countfreq(count);

    for(int i=1; i< countfreq.size(); i++)// O(1);
    {
        countfreq[i] += countfreq[i-1];
    }

    int median;
    int a = 0;
    int b = 0;

    //d is even -> median = a+b
    if(d%2==0){ 
        int first = d/2;
        int second = first+1;
        int i = 0;
        for(;i<201;i++){
            if(first<=countfreq[i]){
                a = i;
                break;
            }
        }
        for(;i<201;i++){
            if(second<=countfreq[i]){
                b = i;
                break;
            }
        }
    } 
    else    //d is odd -> median = a + 0 = 2*(middle elem)
    {
        int first = d/2 + 1;
        for(int i=0;i<201;i++){
            if(first<=countfreq[i]){
                a = 2*i;
                break;
            }
        }
    }
    median = a + b;
    return median;
}
int activityNotifications(vector<int> A, int d) {
    int alerts = 0;
    vector<int> count(201, 0); //stores count of last 'd' numbers
    int n = A.size();

    for(int i =0; i<d; i++)
    {
        count[A[i]]++;
    }
    for(int i=d; i< n; i++)
    {
        int median = getTwiceMedian(A, count, d);
        if(A[i]>= median) alerts++;

        //update count array
        count[A[i]]++;
        count[A[i-d]]--;
    }
    return alerts;
}

/*My code has become fucked. Need to try again at a later point
int medianTimesTwo(vector<int> arr, int d){
    //sort
    //std::sort(arr.begin(), arr.end());
    
    //Find Median
    if(d%2==0){
        //debug code
        cout<<((arr[d/2] + arr[(d/2)-1]))<<"a ";
        return ((arr[d/2] + arr[(d/2)-1]));
    }
    //debug code
    cout<<arr[((d/2))]<<"b ";
    return (arr[((d/2))]*2);
}

int activityNotifications(vector<int> expenditure, int d) {
    vector<int> tempArr;
    int count = 0;
    int temp = 0;

    for(int i=0;i<expenditure.size();i++){
        if(i>=d){
            //debug code
            cout<<(medianTimesTwo(tempArr, d))<<"c "<<expenditure[i]<<"d ";
            if((medianTimesTwo(tempArr, d))<=expenditure[i]){
                count++;
            }
            tempArr.erase(tempArr.begin());
            //tempArr.push_back(expenditure[i]);
        }
        //else if (i<=d){
        if(tempArr.size()==0){
            cout<<expenditure[i]<<"g ";
            tempArr.push_back(expenditure[i]);
            cout<<tempArr[0]<<"h "<<tempArr.size()<<"i ";
        }
        else{
            cout<<tempArr.size()<<"z ";
            for(int j=0;j<tempArr.size();j++){
                cout<<tempArr.size()<<"y "<<tempArr[j]<<" "<<i<<"f ";
                if(expenditure[i]<tempArr[j]){
                    temp = expenditure[i];
                    tempArr.insert(j, temp);
                    break;
                }
            }
        }
        //tempArr.push_back(expenditure[i]);
        //}
    }
    
    return count;
}*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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