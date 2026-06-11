#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node* buildTree(vector<int> preOrder){
    idx++;
    if(preOrder[idx] == -1){
        return NULL;
    }
    //create root Node
    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

//main logic
void topView(Node* root){
    queue<pair<Node*,int>> q; //to store the node and horizontal distance
    map<int, int> mp; //to store the first occurence of the Hori distance.

    q.push({root, 0}); //push the root and origin distance
    while(!q.empty()){
        auto [curr, currHoridist] = q.front();
        q.pop();
        //if 1st occurence store it with hori dist
        if(mp.find(currHoridist) == mp.end()){
            mp[currHoridist] = curr->data;
        }
        //level order traversal
        if(curr->left != NULL){
            q.push({curr->left, currHoridist-1}); //-1 from dist means moving on the left Node
        }
        if(curr->right != NULL){
            q.push({curr->right, currHoridist+1}); //+1 from dist means moving on the right Node

        }
    }
    for(auto &it : mp){
        cout<<it.second<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> preOrder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);
    topView(root);
}

    