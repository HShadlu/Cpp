#include <bits/stdc++.h> 
using namespace std; 
  

class node  
{  
    public: 
    int data;  
    node *left;  
    node *right;  
    node(){
	}
};  
  

node* newNode (int data)  
{  
    node* temp = new node(); 
  
    temp->data = data;  
    temp->left = temp->right = NULL;  
  
    return temp;  
}  
  
// A recursive function to construct Full from pre[]. preIndex is used  
// to keep track of index in pre[].  
node* constructTreeUtil (int pre[], int* preIndex,  
                                int low, int high, int size)  
{  
    // Base case  
    if (*preIndex >= size || low > high)  
        return NULL;  
  
    // The first node in preorder traversal is root. So take the node at  
    // preIndex from pre[] and make it root, and increment preIndex  
    node* root = newNode ( pre[*preIndex] );  
    *preIndex = *preIndex + 1;  
  
    // If the current subarry has only one element, no need to recur  
    if (low == high)  
        return root;  
  
    // Search for the first element greater than root  
    int i;  
    for ( i = low; i <= high; ++i )  
        if ( pre[ i ] > root->data )  
            break;  
  
    // Use the index of element found in preorder to divide  
        // preorder array in two parts. Left subtree and right subtree  
    root->left = constructTreeUtil ( pre, preIndex, *preIndex,  
                                         i - 1, size );  
    root->right = constructTreeUtil ( pre, preIndex, i, high, size );  
  
    return root;  
}  
  
// The main function to construct BST from given preorder traversal.  
// This function mainly uses constructTreeUtil()  
node *constructTree (int pre[], int size)  
{  
    int preIndex = 0;  
    return constructTreeUtil (pre, &preIndex, 0, size - 1, size);  
}  
  
// A utility function to print inorder traversal of a Binary Tree  
void printInorder (node* node)  
{  
    if (node == NULL)  
        return;  
    printInorder(node->left);  
    cout<<node->data<<" ";  
    printInorder(node->right);  
}  

void printPreorder( node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right);  }
 
 
 
void printPostorder( node* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 

node* search( node* root, int key) 
{ 
    // Base Cases: root is null or key is present at root 
    if (root == NULL || root->data == key) 
       return root; 
     
    // Key is greater than root's key 
    if (root->data < key) 
       return search(root->right, key); 
  
    // Key is smaller than root's key 
    return search(root->left, key); 
} 
 
node* insert(node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    
    return node; 
}  
node * minValueNode( node* root) 
{ 
    node *current = root; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
node* deleteNode(node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->data) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->data) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->data= temp->data; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
}  
int main ()  
{  
    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    node *root = constructTree(pre, size);  
  
    cout<< search(root,7)->data;
    insert(root,22);
    printInorder(root);
    deleteNode(root,22);
    printInorder(root);
    
  
    return 0;  
}  
  
