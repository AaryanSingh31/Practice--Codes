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
   if(nums[idx]==-1){
    return NULL;
   }
   Node* root = new Node(nums[idx]);
   root->left = buildTree(nums);
   root->right = buildTree(nums);

   return root;
}
//FN TO CALCULATE THE HEIGHT OF THE TREE I.E, THE MAX DISTANCE OF ROOT FROM A LEAF. (EACH LEVEL CONTAIN 1 UNIT HEIGHT)
int height(Node* root){
    //base case
    if(root==NULL) return 0; //if the tree is empty, then height is 0.

    // TAKING HELP OF RECURSION FOR SOLVING THE HEIGHT OF LEFT AND RIGHT SUBTREE
    int leftHt = height(root->left); //calculate the height of left subtree.
    int rightHt = height(root->right); //calculate the height of right subtree.
    /*APNE LEVEL KA KAAM*/ 
    return max(leftHt, rightHt) + 1; //return the max of left and right subtree height + 1 for the ROOT node. 
}

int main(){
    vector<int> nums = {1, 2, 3, -1, -1, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(nums);
    cout << "Height of the tree: " << height(root) << endl;
    return 0;
}
// OUTPUT:-
// Height of the tree: 4