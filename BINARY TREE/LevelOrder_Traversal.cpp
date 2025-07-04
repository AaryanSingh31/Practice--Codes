
#include <iostream>
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
//FN TO BUILD TREE
Node* buildTree(vector<int> nums){
      idx++;
    if(nums[idx]==-1) return NULL;

    Node* root = new Node(nums[idx]);
    root->left = buildTree(nums);
     root->right = buildTree(nums);
     return root;
}
//************** LEVEL ORDER TRAVERSAL (ITERATION BASED APPROACH). PRINT ALL THE LEVELS IN A SINGLE LINE.********************/
queue<Node*> q;
void levelOrder(Node* root){
    q.push(root);
    while(q.size()>0){
        Node* currNode = q.front();
        q.pop();
      cout<<currNode->data<<" ";
     if(currNode->left != NULL){ //if There is left child of the current node,
        q.push(currNode->left);  //then push it into the queue
     } 
     if(currNode->right != NULL){
        q.push(currNode->right);
     }  
   }
}
//********************************LEVEL ORDER BUT THE DIFFERENT LEVEL ARE PRINTED IN DIFFERENT LINES ****************************/
void lvlOrderWithNewL(Node* root){
    while(!q.empty()){
        q.pop();
    }
    q.push(root);
    q.push(NULL); // To mark the end of the current level
    while(!q.empty()){
        Node* NewNode = q.front();
        q.pop();
        if(NewNode==NULL){
            if(q.size()!=0){
                cout<<endl; // Print a new line if there are more nodes in the queue
                q.push(NULL); // Push NULL to mark the end of the next level
                continue; //Continue with the current iteration
            } else{ //queue is empty i.e, we have printed all the values of queue
                break; //break from the current iteration
            }
        }
        cout<<NewNode->data<<" ";
        if(NewNode->left!=NULL){
             q.push(NewNode->left); //
        }
        if(NewNode->right!=NULL){
             q.push(NewNode->right); //
    }
  }
}
int main (){
vector<int> nums = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root = buildTree(nums);
levelOrder(root); //output : 1 2 3 4 5
cout<<endl;
lvlOrderWithNewL(root); // Print the level order traversal with new lines for each level.
//output:-
/*   1
     2 3
     4 5
 */
cout<<endl;

    return 0;
}
// Time Complexity - O(N) where N is the number of nodes in the tree.

