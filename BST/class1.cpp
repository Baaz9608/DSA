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

Node*maxValue(Node*root){
    if(!root) return nullptr;
    Node*temp = root;

    while (temp->right)
    {
        temp = temp->right;
    }
    
    return temp;
}

Node* deleteFromBST(Node* root, int &target){
    // target ko search kerna hai
    if(!root) return nullptr;

    if(root->data == target){

        // 4 cases
        if(!root->left and !root->right){
            delete root;
            return nullptr;
        }else if(root->left and !root->right){
            Node*childSubtree = root->left;
            delete root;
            return childSubtree;
        }else if(!root->left and root->right){
            Node*chidlSubtree = root->right;
            delete root;
            return chidlSubtree;
        }else{
            Node*maxi = maxValue(root->left);
            root->data = maxi->data;
            delete maxi;
            // return root;  galat tarika hai
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }else if(root->data > target){
        root->left = deleteFromBST(root->left, target);
         
    }else{
        root->right = deleteFromBST(root->right, target);
         
    }
}

int main(){
    Node* root = nullptr;
    creatingBST(root);
    return 0;
}