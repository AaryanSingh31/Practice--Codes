#include <iostream>
#include <vector>
using namespace std;
class Node {
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
Node * buildTree(vector<int> nums){
    idx++;
    if(nums[idx]==-1) return NULL;
    Node* root = new Node(nums[idx]);
    root->left = buildTree(nums);
    root->right = buildTree(nums);

    return root;
}

//FN TO TRAVERSE THE BT USING POSTORDER =>> LEFT, RIGHT, ROOT.
void postOrder(Node* root){
    //Base Case
    if(root == NULL){
        return;
    }
    postOrder(root->left); //traverse the left subtree
    postOrder(root->right);//traverse the right subtree
    cout<<root->data<<" "; //In postOrder Traversal, we print the root after traversing the left and right subtree.
}
int main(){
vector <int> nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root = buildTree(nums); //Built the tree.
postOrder(root); // Traverse the tree using postOrder
}
// OutPut:-
// L L R Ro Ro   || sequence of print
// 2 4 5 3  1 
// TC - O(N) . where N -> No of nodes in the tree.