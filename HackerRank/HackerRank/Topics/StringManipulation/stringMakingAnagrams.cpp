 #include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {

int arA[128], arB[128], diff=0;//65-122

    for(int i=64;i<123;i++){
        arA[i]=0;
        arB[i]=0;
    }

    for (int i = 0; i < a.length(); i++) {
        arA[a.at(i)]++;
    }
    for (int i = 0; i < b.length(); i++) {
        arB[b.at(i)]++;
    }
    for(int i=0; i<128;i++){
        if(arA[i]!=arB[i]){
            if(arA[i]-arB[i]>0){
                diff=diff+(arA[i]-arB[i]);
            }
            else{
                diff=diff+(arB[i]-arA[i]);
            }
        }
    }

    return diff;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
