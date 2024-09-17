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

bool rootToPath(Node* root, int n, vector<int> &path) {
    if(root==NULL) {
        return false;
    }
    path.push_back(root->data);
    if(root->data == n) {
        return true;
    }
    int left = rootToPath(root->left, n, path);
    int right = rootToPath(root->right, n, path);

    if(left || right) {
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2) {
    vector<int> path1;
    vector<int> path2;
    
    rootToPath(root, n1, path1);
    rootToPath(root, n2, path2);

    for (int i=0, j=0; i<path1.size(), j<path2.size(); i++,j++) {
        if (path1[i] != path2[j]) {
            return -1;
        }

        return path1[i];
    }

    return -1;
}

int main () {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTrees(nodes);

    cout << LCA(root, 4,5);
    
}