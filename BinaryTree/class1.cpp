#include<iostream>
using namespace std;

class Node{
    public:
    int  data;
    Node*left, *right;

    Node(int val):data(val),left(nullptr), right(nullptr){};

};

Node* createTree(){
    cout<<"Enter the value for node: "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return nullptr;
    }

    // create root node
    Node* newNode = new Node(data);

    // step2: left subtree
    cout<<"left of Node "<<newNode->data<<endl;
    newNode->left = createTree();

    // step3: right subtree
    cout<<"right of Node "<<newNode->data<<endl;
    newNode->right = createTree();

    return newNode;
}

void preOrderTraversal(Node* root){
    // base case
    if(!root) return;

    cout<<root->data<<endl;

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node*root){
    if(!root) return;

    inOrderTraversal(root->left);
    cout<<root->data<<endl;

    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    // base case
    if(!root) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<endl;
}

#include<queue>

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
       
        int size = q.size();
        

        for(int i=0; i<size; i++){
            Node*temp = q.front();
            q.pop();
            cout<<temp->data<<" ";

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        cout<<endl;

    }
}

int main(){
    Node* root = createTree();
    cout<<"printing pre"<<endl;
    preOrderTraversal(root);
    cout<<"printing in"<<endl;
    inOrderTraversal(root);
    cout<<"printing post"<<endl;
    postOrderTraversal(root);
    cout<<"printing levelOrder"<<endl;
    levelOrderTraversal(root);
    return 0;
}