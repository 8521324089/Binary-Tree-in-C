#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
}*pre;

struct node* copy(int element);
struct node* change(struct node *root,struct node *temp,int pos);
struct node* insert(struct node *root,int element);
struct node* delete(struct node *root,int element);
void pre_order(struct node *leave);
void in_order(struct node *leave);
void post_order(struct node *leave);
void traverse(struct node *leave,int element);


int main()
{
    struct node *root=NULL;
    printf("Enter your Choise\n");
    int c,element;
    do
    {
        printf("Add=1,Delete=2,Preorder=3,Inorder=4,Postorder=5,Exit='Any other key' = ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            printf("Enter the element = ");
            scanf("%d",&element);
            root=insert(root,element);
            break;
        case 2:
            printf("Enter the element = ");
            scanf("%d",&element);
            root=delete(root,element);
            break;
        case 3:
            pre_order(root);
            break;
        case 4:
            in_order(root);
            break;
        case 5:
            post_order(root);
            break;
        
        default:
            printf("Exiting!!!\n");
            break;
        }
    } while (c==1||c==2||c==3||c==4||c==5);
    
    return 0;
}


struct node* copy(int element)
{
    struct node *leave;
    leave=(struct node*)malloc(sizeof(struct node));
    leave->data=element;
    leave->left=NULL;
    leave->right=NULL;
    return leave;
}
void traverse(struct node *leave,int element)
{
    if(leave==NULL)
    {
        return;
    }
    traverse(leave->left,element);
    if(leave->data<element)
    pre=leave;
    traverse(leave->right,element);
    

}

struct node* change(struct node *root,struct node *temp,int pos)
{
    traverse(temp,temp->data);
    if(pos==0&&root->left==NULL)
    {    
        return(root->right);
    }
    delete(temp,pre->data);
    pre->right=temp->right;
    pre->left=temp->left;
    if(pos==0)
    {    
        root=pre;
        return(pre);
    }
    if(pos==1)
    {
        root->right=pre;
        return(root);
    }
    else if(pos==2)
    {
        root->left=pre;
        return(root);
    }
}

struct node* insert(struct node *root,int element)
{
    if(root==NULL)
        {   
            root=copy(element);
            return root;
        }
    if(root->data<element)
    {
        if(root->right!=NULL)
        insert(root->right,element);
        else
        {
            root->right=copy(element);
            return root;
        }
    }
    else if(root->data>element)
    {
        if(root->left=NULL)
        insert(root->left,element);
        else
        {
            root->left=copy(element);
            return root;
        }
    }
    else
    {
        printf("Same element don't insert in Binary TREE\n");
        return root;
    }
    return root;
}

struct node* delete(struct node *root,int element)
{
   if(root==NULL)
    {   
        printf("Tree have no element\n");
        return(NULL);
    }
    else
    {
        if(root->data<element)
        {
            if(root->right!=NULL)
            {
                if(root->right->left==NULL&&root->right->right==NULL&&root->right->data==element)
                {
                    root->right=NULL;
                    return root;
                }
                else if(root->right->data==element)
                {
                    root=change(root,root->right,1);
                    return(root);
                }
                delete(root->right,element);
            }
            else
            {
                printf("Item don't present in tree\n");
                return root;
            }
        }
        else if(root->data>element)
        {
            if(root->left!=NULL)
            {
                if(root->left->left==NULL&&root->left->right==NULL&&root->left->data==element)
                {
                    root->left=NULL;
                    return root;
                }
                else if(root->left->data==element)
                {
                    root=change(root,root->left,2);
                    return(root);
                }
                delete(root->left,element);
            }
            else
            {
                printf("Item don't present in tree\n");
                return root;
            }
        }
        else if(root->data==element)
        {
            root=change(root,root,0);
            return(root);
        }
    }
    return root;
}
    
void pre_order(struct node *leave)
{
    if(leave==NULL)
    {
        return;
    }
    printf("%d\t",leave->data);
    pre_order(leave->left);
    pre_order(leave->right);
}

void in_order(struct node *leave)
{
    if(leave==NULL)
    {
        return;
    }
    in_order(leave->left);
    printf("%d\t",leave->data);
    in_order(leave->right);

}

void post_order(struct node *leave)
{
    if(leave==NULL)
    {
        return;
    }
    post_order(leave->left);
    post_order(leave->right);
    printf("%d\t",leave->data);
}
