// problem: https://www.hackerrank.com/challenges/tree-top-view/problem?isFullScreen=true


#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * _root){
        using namespace std;
        assert(_root);
        auto nodes = queue<pair<Node *, int>>();
        auto widthToData = map<int, int>();
        nodes.emplace(_root, 0);
        widthToData.insert({0, _root->data});
        auto node = nodes.front().first;
        auto width = nodes.front().second;
        while(!nodes.empty()){
            node = nodes.front().first;
            width = nodes.front().second;
            nodes.pop();
            if(node->left){
                nodes.emplace(node->left, width - 1);
            }
            if(node->right){
                nodes.emplace(node->right, width + 1);
            }
            widthToData.insert({width, node->data});
        }
        for(auto x : widthToData){
            std::cout << x.second << " ";
        }        
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);

    return 0;
}
