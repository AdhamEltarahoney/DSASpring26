// 3 depth first search, wednesday bfs

// pre, inorder, postorder -> recursive traversals


#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;

    Node(int v){
        value = v;
        left = nullptr;
        right = nullptr;
    }
};


void preorder(Node* root){ //node, left, right
    //we are passing in the root

    if (root == nullptr){
        return;
    }
    cout<<root->value<<" ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node* root){ //left, node, right
    //we are passing in the root

    if (root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}



void postorder(Node* root){ //left, right, node
    //we are passing in the root

    if (root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<" ";

}
//BFS
void bfs(Node* root){
    if (root == nullptr) return; //tree is empty
    queue<Node*> q;
    q.push(root);

    while (!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<< current->value<<" ";
        if (current->left != nullptr){
            q.push(current->left);
        }
        if (current->right != nullptr){
            q.push(current->right);
        }
    }


}

int main() {


    //        8
    //   3        10
    // 1   6          14
    //bfs: 8,3,10,1,6,14

    //inorder: 1.3.6.8.10,14
    // preorder: 8,3,1,6,10,14
    //postorder: 1,6,3,14,10,8
    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->right->right = new Node(14);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout<<"BFS: ";
    bfs(root);
    cout<<endl;


    return 0;
}


