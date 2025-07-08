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
int main(){
vector<int> nums1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
vector<int> nums2 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
 int idx1 = -1, idx2 = -1;
    Node* root1 = buildTree(nums1, idx1);
    Node* root2 = buildTree(nums2, idx2);
    if(isIdentical(root1, root2)){
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }
    return 0;
}