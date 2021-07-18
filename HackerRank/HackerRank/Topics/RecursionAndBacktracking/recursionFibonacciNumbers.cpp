#include <iostream>

using namespace std;

int fibonacci(int n) {
    // Complete the function.
    int ret = 0;
    
    if(n>1){
        ret = fibonacci(n-1) + fibonacci(n-2);
    }
    else if(n==0){
        return 0;
    }
    else{
        return 1;
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}