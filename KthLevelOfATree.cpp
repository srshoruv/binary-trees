#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTrees(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTrees(nodes);
    currNode->right = buildTrees(nodes);

    return currNode;
}

void kthHelper(Node* root, int k, int currNode){
    if (root==NULL) {
        return;
    }

    if(currNode==k) {
        cout << root->data << " ";
        return;
    }

    kthHelper(root->left, k, currNode+1);
    kthHelper(root->right, k, currNode+1);
}

void kthLevel(Node* root, int k) {
    return kthHelper(root, k, 1);
}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTrees(nodes);

    kthLevel(root, 3);
    
}