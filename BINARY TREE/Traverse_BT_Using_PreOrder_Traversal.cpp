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
//FN TO BUILD TREE
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

//FN TO TRAVERSE THE TREE USING PREORDER TRAVERSAL =>> ROOT, LEFT, RIGHT.
void preOrder(Node* root){
    //base case to stop recursion
    if(root == NULL){
        return;
    }
    cout << root->data << " "; //Print the root data.
    preOrder(root->left); //call for print left subtree
    preOrder(root->right);//call for print right subtree

}
int main(){
  //                   Ro L  L  R R L  L  R R  L  R            Ro-> Root, L-> Left, R-> Right 
vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root = buildTree(preorder); //Tree Built.
preOrder(root); //Traverse the tree using preorder traversal.
    return 0;
}
// Output:-
//Ro L Ro L R    ||sequence of print 
// 1 2 3  4 5
// TC - O(N) . where N -> No of nodes in the tree.