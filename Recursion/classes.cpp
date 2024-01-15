#include<iostream>
using namespace std;

int factorial(int n){
    // base case
    if(n==1){
        return n;
    }

    // processing and recursion call
    int ans = n*factorial(n-1);
    return ans;
}

void counting1(int n){
    // base case
    if(n==0) return;

    // processing from n to 1
    cout<<n<<" ";

    // recursion call
    counting1(n-1);

}

void counting2(int n){
    // base case
    if(n==0) return;


    // recursion call
    counting2(n-1);

    // processing from 1 to n
    cout<<n<<" ";
}

float powerOfNeg(float x, int n){
    if(n==0){
        return 1;
    }

    float ans = (1/x)*powerOfNeg(x,n+1);
    return ans;
}

int power(int x, int n){
    // base case
    if(n<=0) return 1;
    
    // processing ans recursion call
    int ans = x*power(x,n-1);
    
    return ans;
}

int fib(int n){
    // base case
    if(n==0 or n==1){
        
        return n;
    } 

    int ans = fib(n-2)+fib(n-1);
     
    return ans;
}

#include<vector>
void printingFib(int n){
    // vector<int> dp(n+1, 0);
    // dp[1] = 1;
    // for(int i=2; i<=n; i++){
    //     dp[i] = dp[i-1]+dp[i-2];
    // }
    // for(auto elem:dp){
    //     cout<<elem<<" ";
    // }
    if(n<0){
        cout<<"Invalid input, Please enter any positive number!!! -> ";
        cin>>n;

    }
    cout<<"Printing fibonacci number series: ";
    int prev2 = 0;
    if(n==0){
        cout<<prev2<<endl;
        cout<<n<<"th term: "<<prev2;
        return;
    }
    int prev1 = 1;
    if(n==1){
        cout<<prev2<<" "<<prev1;
        cout<<endl<<n<<"th term: "<<prev1;
        return;
    }
    cout<<prev2<<" "<<prev1<<" ";
    int curr = 0;
    for(int i=2; i<=n; i++){
        curr = prev1 + prev2;
        cout<<curr<<" ";
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<endl<<n<<"th term "<<curr;

}

int main(){
    cout<<factorial(5)<<endl<<endl;
    counting1(9);
    cout<<endl<<endl;
    counting2(9);
    cout<<endl<<endl;
    cout<<power(2,1)<<endl<<endl;
    cout<<powerOfNeg(2,-5)<<endl<<endl;
    cout<<fib(3)<<endl<<endl;
    printingFib(-1);
    cout<<endl<<endl;
    return 0;
}