#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;

    Node(int val):data(val), left(nullptr), right(nullptr){};
};

#include<vector>

Node*insertVal(Node* root, int d){
    if(!root){
        root = new Node(d);
        return root;
    }

    if(d<root->data){
        root->left = insertVal(root->left, d);
    }else{
        root->right = insertVal(root->right, d);
    }
    return root;
}

void creatingBST(Node* root){
    cout<<"Enter data: "<<endl;
    int val;
    cin>>val;

    while(val != -1){
        root = insertVal(root, val);
        cin>>val;
    }
}

int minValue(Node*root, int &ans){
    if(!root) return 0;

    Node*temp = root;

    while(temp->left){
        ans = temp->data;
        temp = temp->left;
    }

    return ans;
     
}

int main(){
    Node* root = nullptr;
    creatingBST(root);
    return 0;
}