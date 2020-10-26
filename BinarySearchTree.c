#include "BinarySearchTree.h"

BinarySearchTree newBinarySearchTree()
{
    BinarySearchTreeImp* bst;
    bst = (BinarySearchTreeImp*)malloc(sizeof(BinarySearchTreeImp));
    
    if(bst == NULL)
    {
        printf("error");
    }
    
    bst->root = NULL;  
    return bst;
}

//Free the BinarySearchTree and any nodes that still exist in the tree.
void freeBinarySearchTree(BinarySearchTree tree)
{
        freeBinarySearchTree(tree);
        free(tree);
}


//Allocate a new node and store "value" as the Element in the node.  Return the address of the node.
NodeT *allocateNode(Element value)
{
    NodeT* new;
    new = (NodeT*)malloc(sizeof(NodeT));
    
    if (new == NULL)
    {
        printf("Error in allocating node");
        exit(0);
    }
    
    new->element = value;
    new->left = NULL;
    new->right = NULL;
    
    return new;
}

//Recursive algorithm for searching for a node with key value equal to searchValue.  Return a pointer to the node if you find it or return NULL if it does not exist.
NodeT *search(NodeT *p, int searchValue)
{
    //node is empty
    if(p == NULL || p->element.accountNumber == searchValue)
    {
        return p;
    }
    else
    {
        if(searchValue < p->element.accountNumber)
        {
            return search(p->left, searchValue);
        }
         else
        {
           return search(p->right, searchValue);
        }
    }
    
}

//Create a node to store the given Element and add it as a leaf in the BinarySearchTree.  Do not worry about balancing the tree for this project.
//Return true if the insert worked successfully, and return false if the node already existed in the tree.
int insert(NodeT **pp, Element value)
{
 
    if(*pp == NULL) //node position is empty so create a node containing value
    {
       *pp = allocateNode(value);
       return TRUE;
    }
   
    
     if (value.accountNumber == (*pp)->element.accountNumber)
        {
            return FALSE;
        }
      
        if(value.accountNumber < (*pp)->element.accountNumber)
        {
            return insert (&((*pp)->left), value);         
        }
        else
        {
            return insert (&((*pp)->right), value);
        } 
         
    
}

//Recursivly print the key values of all nodes in the subtree rooted at p in increasing order.
void printInOrder(NodeT *p)
{
    
    if(p == NULL)
    {
        return;
    }
    else
    {
  
        printInOrder(p->left);
        printf("%d %.2lf\n", p->element.accountNumber, p->element.accountBalance);
        printInOrder(p->right);
        
     }
          
}

//Recursivly print the key values of all nodes in the subtree rooted at p according to a preorder traversal.
void printPreOrder(NodeT *p)
{
    
    if(p == NULL)
    {
        return;
    }
    else
    {
        printf("%d %.2lf\n", p->element.accountNumber, p->element.accountBalance);
        printPreOrder(p->left);
        printPreOrder(p->right);
    }
}
