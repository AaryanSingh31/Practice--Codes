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
//FN TO TRAVERSE THE TREE USING INORDER TRAVERSAL =>> LEFT, ROOT, RIGHT.
void inOrder(Node* root){
    //base case 
    if(root == NULL){
        return;
    }
    inOrder(root->left); //Traverse the left subtree
    cout<< root->data << " "; //In InOrder Traversal, we print the root after traversing the left subtree.
     inOrder(root->right);//Traverse the right subtree
}
int main(){             
    vector<int> nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(nums); //built the BT
    inOrder(root); //traverse and print the BT using InOrder Traversal.
    return 0;
}
// OutPut:-
// L Ro L Ro R ||sequence of print 
// 2 1  4 3  5
// TC - O(N) . where N -> No of nodes in the tree.