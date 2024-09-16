#include <iostream>
#include <vector>
#include <queue>
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

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    
}

void postorder(Node* root) {
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        if(curr == NULL) {
            cout << endl;
            if(Q.empty()) {
                break;
            }
            Q.push(NULL);
        } else {
            cout << curr->data << " ";

            if(curr->left) {
                Q.push(curr->left);
        }

            if(curr->right) {
                Q.push(curr->right);
        }
        
        }
        
    }
}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int count = max(left,right) + 1;
    
    return count;
}

int count(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}

int sum(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}

int digm(Node* root) {
    if (root==NULL) {
        return 0;
    }

    int currDigm = height(root->left) + height(root->right) + 1;
    int leftDg = digm(root->left);
    int rightDg = digm(root->right);

    return max(currDigm, max(leftDg, rightDg));
}

pair<int,int> digm2(Node* root) {
    if (root==NULL) {
        return make_pair(0,0);
    }

    pair<int,int> leftInfo = digm2(root->left);
    pair<int,int> rightInfo = digm2(root->right);

    int currDig = leftInfo.second + rightInfo.second + 1;
    int finalDig = max(currDig, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDig, finalHt);

}

int main() {
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTrees(nodes);
    
    // postorder(root);

    // levelorder(root);

    cout << digm2(root).first;

}