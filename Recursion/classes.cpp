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

void printArray(int arr[], int size, int index){
    if(index>=size) return;

    printArray(arr, size, index+1);
    cout<<arr[index]<<" ";
}

bool searchInArray(int *arr, int size, int index, int target){
    if(index>=size) return false;

    if(arr[index] == target) return true;

    bool ans = searchInArray(arr, size, index+1, target);
    return ans;
}

#include<limits.h>
void minNumber(int *arr, int size, int index, int &ans){
    if(index>=size) return;

    ans = min(ans,arr[index]);
    minNumber(arr, size, index+1, ans);
    
}

void evenNumber(int*arr, int size, int index, vector<int>&ans){
    if(index>=size) return;

    if(arr[index]>0 and arr[index]%2==0){
        ans.push_back(arr[index]);
    }
    evenNumber(arr,size,index+1,ans);
}

int indexOfTarget(int*arr, int size, int index, int &target){
    if(index>=size) return -1;
    if(arr[index] == target){
        return index;
    }
    int ans = indexOfTarget(arr,size,index+1, target);
    return ans;
}

void indicesOfTargets(int *arr, int size, int index, int &target){
    if(index>=size) return;

    if(arr[index] == target){
        cout<<index<<",";
    }

    indicesOfTargets(arr,size,index+1,target);
}

vector<int> indices(int *arr, int size, int index, int &target){
    vector<int> ans;
    if(index>=size) return ans;

    if(arr[index] == target){
        ans.push_back(index);
    }

    vector<int>aageKaAns = indices(arr, size, index+1, target);

    vector<int> finalAns;
    for(auto x:ans){
        finalAns.push_back(x);
    }
    for(auto x:aageKaAns){
        finalAns.push_back(x);
    }
    return finalAns;
}

void findDigits(int &num,vector<int>&ans){
    if(num==0) return;

    int digit = num%10;
    num = num/10;
    findDigits(num,ans);
    ans.push_back(digit);
    cout<<digit<<" ";
}

void makingNumberFromVector(vector<int>&vect,int index, int &ans){
    if(index>=vect.size()) return;

    ans = ans*10+vect[index];
    makingNumberFromVector(vect, index+1, ans);
}

void storeString(string&str, char target, int index=0){
    if(index>=str.length()) return;
    if(str[index] == target){
        cout<<index<<" ";
    }

    storeString(str, target, index+1);
}

bool checkSortedArray(int*arr, int size, int index=1){
    if(index>=size) return true;

    if(arr[index]<arr[index-1]) return false;
     
    bool ans = checkSortedArray(arr, size, index+1);
    return ans;
}

int binSearch(int *arr, int start, int end, int target){
    // base case
    if(start>end) return -1;

    int mid = start + (end - start)/2;

    if(arr[mid] == target){
        return mid;
    }else if(arr[mid]>target){
        return binSearch(arr,start, mid-1,target);
    }else{
        return binSearch(arr, mid+1, end,target);
    }
}

int main(){

    int a[] = {2,4,5,6};
    // cout<<checkSortedArray(a,4);
    cout<<binSearch(a,0,4,0);


    // string str = "shahbaz";
    // storeString(str, 'a');
    // cout<<endl;

    // int num = 1234;
    // vector<int>cont;
    // findDigits(num,cont);
    
    // cout<<endl;
    // for(auto elem:cont){
    //     cout<<elem<<" ";
    // }
    // cout<<endl;
    // cout<<checkSortedArray(cont,cont.size());
    // cout<<endl;
    // int answer = 0;
    
    // makingNumberFromVector(cont,0, answer);
    // cout<<answer;
    // cout<<endl;
    // int arr[]={10,20,3,-2,50};
    // printArray(arr, 5,0);
    // cout<<endl<<searchInArray(arr,5,0,3)<<endl;
    // int ans = INT_MAX;
    // minNumber(arr, 5,0,ans);
    // cout<<ans<<endl;
    // vector<int> temp;
     
    // evenNumber(arr, 5,0,temp);
    // for(auto x:temp){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    // int target = 50;
    // cout<<indexOfTarget(arr,5,0,target)<<endl;
    // int vect[] = {2,3,4,2,2,2,2,5,6,2,2};
    // target = 2;
    // indicesOfTargets(vect,11,0,target);
    // vector<int> ansi= indices(arr, 11,0,target);
    // for(auto x:ansi){
    //     cout<<x<<" ";
    // }

    // cout<<factorial(5)<<endl<<endl;
    // counting1(9);
    // cout<<endl<<endl;
    // counting2(9);
    // cout<<endl<<endl;
    // cout<<power(2,1)<<endl<<endl;
    // cout<<powerOfNeg(2,-5)<<endl<<endl;
    // cout<<fib(3)<<endl<<endl;
    // printingFib(-1);
    // cout<<endl<<endl;
    return 0;
}