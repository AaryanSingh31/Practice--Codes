//**********************************************BUILD A BINARY TREE USING PREORDER SEQUENCE*************************************************************** */

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
//FN TO CREATE THE BINARY TREE
Node* buildTree( vector<int> preOrder){
     idx++; //Update the idx.
    //Base case to stop recursion
    if(preOrder[idx]==-1){
        return NULL;
    }
   Node* root = new Node(preOrder[idx]); //Formation of a Node.
   //Build the left and right Subtree recursively
   root->left = buildTree(preOrder);  //This Recursive fn will form the left subtree.
   root->right = buildTree(preOrder); //This Recursive fn will form the right subtree.

   return root; //Connection of Left and Right Subtree to the Node.
   }
int main(){
vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root = buildTree(preorder); //Built the tree from the preorder traversal.
//since we have root of the tree .. we can traverse it or print it in any way we want.

    return 0;
}
/*
*******************************************************WHAT'S RETURN ROOT IS DOING*********************************************************

🧱 return root; ka matlab:
Ye line ka kaam hai iss level par bana hua node (i.e. root) ko return karna us function call ko jisne isse call kiya tha.
Har recursive call ek node banata hai, uske left aur right subtrees set karta hai, aur phir us pura node tree ko return karta hai.

🔄 Recursive Calls Mein Kya Hota Hai:
Har baar jab buildTree(preOrder) call hota hai:
- Ek Node banaya jaata hai (agar -1 nahi hai).
- Left subtree ke liye buildTree(preOrder) call hota hai → uska return value set hota hai root->left mein.
- Right subtree ke liye buildTree(preOrder) call hota hai → uska return value set hota hai root->right mein.
- Finally, root node return kar diya jaata hai → return root;
🧱 return root; ka matlab:
Ye line ka kaam hai iss level par bana hua node (i.e. root) ko return karna us function call ko jisne isse call kiya tha.
Har recursive call ek node banata hai, uske left aur right subtrees set karta hai, aur phir us pura node tree ko return karta hai.

🔄 Recursive Calls Mein Kya Hota Hai:
Har baar jab buildTree(preOrder) call hota hai:
- Ek Node banaya jaata hai (agar -1 nahi hai).
- Left subtree ke liye buildTree(preOrder) call hota hai → uska return value set hota hai root->left mein.
- Right subtree ke liye buildTree(preOrder) call hota hai → uska return value set hota hai root->right mein.
- Finally, root node return kar diya jaata hai → return root;

🧠 Ek line mein:
return root; ka matlab hai: “Mera kaam ho gaya, yeh lo mera bana hua node – ab tum isse jahan chaho jodo.”

*************************************************ROOT MEIN LEFT AUR RIGHT CONNECTION KAHA PE AUR KESE ASSIGN HO RHA HAI**************************************************

🔧 Kahaan ho raha hai connection
Code ka ye part dekho:
root->left = buildTree(preOrder);
root->right = buildTree(preOrder);

💡 Kya ho raha hai yahaan?
- Jab new Node(preOrder[idx]) se ek root node banta hai, toh us node ke left child aur right child ko set karne ke liye hum recursively buildTree ko call karte hain.
- Har call buildTree ka ek naye node ko return karta hai, ya NULL agar (-1) mile.
- Ye returned nodes ko root->left aur root->right mein assign kiya ja raha hai.

*/

