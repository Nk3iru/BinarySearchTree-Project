#include "BinarySearchTree.h"


int main()
{
    BinarySearchTree bs = newBinarySearchTree();
    Element e;
    
    FILE *f;
    f = fopen("smallInput.txt", "r");
    
    if (f == NULL)
    {
        printf("Could not open file");
        return -1;
    }

    char buffer[100];
    char temp_str[10];
    char temp_phrase[10];
    
    while(fgets(buffer, 100, f) != NULL)
    {
        //if file reads character 'C', it will parse through data from CREATE 
        if (buffer[0] == 'C')
        {
           e.accountBalance = 0;
           sscanf(buffer, "%s %d", temp_str, &e.accountNumber);
           insert(&bs->root, e);  
        }
        
        //if file reads character 'S', it will parse through data from SALE
        else if (buffer[0] == 'S')
        {
           sscanf(buffer,"%s %d %lf", temp_str, &e.accountNumber, &e.accountBalance); 
           NodeT* val = search(bs->root, e.accountNumber);
           
           val->element.accountBalance += e.accountBalance; //updates the value of the node
        }
        
        //if file reads character 'P', it will parse through the data that was previously called
       else if (buffer[0] == 'P')
        {
            sscanf(buffer, "%s %s", temp_str, temp_phrase);
            
            if(strcmp(temp_phrase, "PREORDER") == 0)
            {
                printf("List of accounts: \n");
                printPreOrder(bs->root);
            }
            if(strcmp(temp_phrase, "INORDER") == 0)
            {
                printf("Balance of accounts: \n");
                printInOrder(bs->root);
            }
        }
 
    }
    fclose(f);
    return 0;
}
