#include <iostream>
#include <vector>
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
// FN TO BUILD BT
Node* buildTree(vector<int> nums){
    idx++;
    if(nums[idx]==-1) return NULL;

    Node* root = new Node(nums[idx]);
    root->left = buildTree(nums);
    root->right = buildTree(nums);
    return root;
}
//FN TO GET TOTAL COUNT OF NODES
int count(Node* root){
    //base case
    if(root ==NULL) return 0;

    //recursion
    int lcount = count(root->left); //gets the count of left subtree.
    int rcount = count(root->right);//gets the count of right subtree.

    return lcount + rcount + 1; //apne level ka kaam +> left + right subtree ka count + root ka count(1) = Total nodes in the tree.
}
int main(){
    vector<int> nums = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(nums);
cout<<"Total no of Nodes in the tree : "<<count(root)<<endl;
    return 0;
}
// Output:-
// Total no of Nodes in the tree : 5
//TC -> O(N) where N = Total No of Nodes.