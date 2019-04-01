#include <iostream>
#include <queue>

using namespace std;
struct node{
  node *left;
  node *right;
  int data;
};
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        cout<<q.front()->data<<" ";
        if(q.front()->left)
        {q.push(q.front()->left);}
        if(q.front()->right)
        {q.push(q.front()->right);}
        q.pop();
    }
}

void inorder(node* root)
{ if(root==NULL)
     {
         return;
     }
     if(root->left)
    inorder(root->left);
    cout<<root->data<<" ";
    if(root->right)
    inorder(root->right);
}
void preorder(node* root)
{ if(root==NULL)
     {
         return;
     }
     cout<<root->data<<" ";
     if(root->left)
    preorder(root->left);

    if(root->right)
    preorder(root->right);
}
void postorder(node* root)
{ if(root==NULL)
     {
         return;
     }
     if(root->left)
    postorder(root->left);

    if(root->right)
    postorder(root->right);

     cout<<root->data<<" ";
}
bool search(node* root,int data)
{   if(root==NULL)
     {return false;}
    if(root->data==data)
    {
      return true;

    }
    else if(root->data<=data)
    {
        return search(root->right,data);
    }
    else if(root->data>=data)
    return search(root->left,data);

}
node* getnewnode(int data)
{
    node *newnode = new node;
    newnode->data = data;
    return newnode;
}
node* insert(node* root,int data)
{
   if(root==NULL)
   {
       root=getnewnode(data);
   }
   else if(root->data<=data)
   {
     root->right = insert(root->right,data);

   }
   else
   {
       root->left = insert(root->left,data);
   }
   return root;
}
int main()
{
    node *root=NULL;
    int n;
    cin>>n;
    while(n--)
    {
      int t;
      cin>>t;
      root=insert(root,t);
    }
    levelorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);


    /*int x;
    cin>>x;
    if(search(root,x))
    {
        cout<<"Found";
    }
    else cout<<"Not Found";
    */
    return 0;
}
