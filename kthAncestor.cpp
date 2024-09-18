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

int kthAnce(Node* root, int node, int k) {
    if (root == NULL) {
        return -1;
    }

    if(root->data == node) {
        return 0;
    }

    int leftDist = kthAnce(root->left, node, k);
    int rightDist = kthAnce(root->right, node, k);

    if(leftDist == -1 && rightDist == -1) {
        return -1;
    }

    int validVal = leftDist == -1? rightDist : leftDist;
    if (validVal + 1 == k) {
        cout << root ->data << endl;
    }

    return validVal + 1;
}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTrees(nodes);

    cout << kthAnce(root, 4,5);
    
}