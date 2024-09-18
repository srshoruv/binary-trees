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


Node* LCA(Node* root, int n1, int n2){
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2); 

    if (leftLCA && rightLCA) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int dis(Node* lca, int n) {

    if(lca == NULL) {
        return -1;
    }

    if (lca->data==n) {
        return 0;
    }

    int left = dis(lca->left, n);
    if (left != -1) {
        return left + 1;
    }

    int right = dis(lca->right, n);
    if (right != -1) {
        return right + 1;
    }

    return -1;
}

int minDis(Node* root, int n, int n1) {
    Node* lca = LCA(root,n,n1);

    int leftDis = dis(lca, n);
    int rightDis = dis(lca, n1);

    return leftDis + rightDis;

}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTrees(nodes);

    cout << minDis(root, 4,5);
    
}