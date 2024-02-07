
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node*lchild;
  struct node*rchild;
};

struct node*create()
{
    int x,lchild,rchild;
    struct node*newnode;
    printf("Enter data\n");
    scanf("%d",&x);
    if(x!=-1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        printf("Enter lchild of %d\n",x);
        newnode->lchild=create();
         printf("Enter rchild of %d\n",x);
        newnode->rchild=create();
        return newnode;
    }
    else
        return 0;
};

void postOrder( struct node *tree, int * count) {
    if (tree != NULL) {
        *count = *count + 1;
        postOrder(tree->lchild,count);
        postOrder(tree->rchild,count);
    }
}

int main()
{  int ele;
    struct node*root;
    root=create();
    int count = 0;
    postOrder(root,&count);
    printf("Number of nodes in graph are %d\n",count);

    return 0;
}
