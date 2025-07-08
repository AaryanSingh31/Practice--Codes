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

    Node* buildTree(vector<int> nums , int &idx){
        idx++;
        if(nums[idx]==-1) return NULL;
       
        Node* root = new Node(nums[idx]);
        root->left = buildTree(nums, idx);
        root->right = buildTree(nums, idx);
        return root;
    }
//FN TO CHECK IF THE SUBTREE IS IDENTICAL FROM THE SAME ROOT FOUND IN BIG TREE
 bool isIdentical(Node* root1, Node* root2){
        //base case
        if(root1 == NULL || root2 == NULL){ //if One of them is NULL then return false.
            return root1 == root2; //if both are NULL, they are identical, return true. else not.
        }
        //check data
        if(root1->data != root2->data) return false;
        //check left and right subtrees
        return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
        
//FN TO FIND IF THE TREE IS SUBTREE OF ANOTHER TREE OR NOT.
bool isSubtree(Node* root,Node* subroot){
    //Base case
     if(root==NULL || subroot == NULL){ //if one of them is null then false
        return root==subroot; //If both are NULL then true,
     }
 //chk if the data of the roots is equal and both the root and subroot are identical from the subroot    
     if(root->data == subroot->data && isIdentical(root, subroot)){
        return true;

     } 
     //return true if any of the left or right meet the conditiions.
     return isSubtree(root->left, subroot) || //Solve if the left of main tree is subtree of another tree.
             isSubtree(root->right, subroot); //Solve if the right of main tree is subtree of another tree.
}
    int main(){
vector<int> nums1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
vector<int> nums2 = {3,4,-1,-1,5,-1,-1};
 int idx1 = -1, idx2 = -1;
    Node* root1 = buildTree(nums1, idx1);
    Node* root2 = buildTree(nums2, idx2);
    if(isSubtree(root1, root2)){
        cout<<"Subtree Exists."<<endl; //Output
    } else{
        cout<<"NO Subtree Exists."<<endl;
    }
    return 0;
    }