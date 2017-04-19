#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


struct tree{ //You need a data structure in order to implement a Tree
    int data;
    struct tree *child,*sibling;
};

//Preorder Visit
void preorder(struct tree*p){ 
    if(p==NULL)return;
    printf(" %d",p->data);
    preorder(p->child);

    preorder(p->sibling);
}
struct tree* search(struct tree* root,int data){ 
    if(root==NULL) //If root is NULL abort
        return 0;
    if(data==root->data) //If there's required data assign it to data
        return root;
    struct tree* t = search(root->child,data);
    if(t==NULL)
         t = search(root->sibling,data);
    return t;

}

struct tree* createNode(int data){
    struct tree* newnode= (struct tree*)malloc(sizeof(struct tree));
    newnode->child=NULL;
    newnode->sibling=NULL;
    newnode->data=data;
    return newnode;
}

struct tree* createnary(struct tree* root,int data[]){

    //check if node exists

    struct tree * newnode = search(root,data[0]);
    //if it doesn't exist
    if(newnode==NULL)
    {
        newnode= createNode(data[0]);
    }

    struct tree* parent=newnode;
    /////Now we create child's node
    int j;
    for(j=0;j<data[1];j++)
    {
        //For first son
        if(j==0)
        {
             parent->child= createNode(data[j+2]);
             parent = parent->child;
        }
        //And for the others...
        else
        {
            parent->sibling=createNode(data[j+2]);
            parent = parent->sibling;
        }

    }

    if(root==NULL)
            root = newnode;
    return root;


}

