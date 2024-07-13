#include<iostream>
#include <string>
#include <cstring>
#include  <bits/stdc++.h>
using namespace std;
struct node
{
       string  key;
       string  val;
       node *parent;
       char color;
       node *left;
       node *right;
};
class RBtree
{
      node *root;
      node *q;
   public :
      RBtree()
      {
              q=NULL;
              root=NULL;
      }
      void insert(); //add node to tree
      void insertfix(node *&, node *&); //set color of added node in tree
      void rotateLeft(node *&, node *&);
      void rotateRight(node *&, node *&);
      void del(string );
      node* successor(node *);//return nearest node to input node
      void disp();
      void display( node *);
      int getindex(node *,node *);//return index of input node in inorder trace
      void search(string);
};
void RBtree::insert()
{    string s,key;
     int i=0;
     string delimiter = ":";
     size_t pos = 0;
     
     getline(cin,s);
     
	 pos = s.find(delimiter) ;
     key = s.substr(0, pos);
     
     s.erase(0, pos + delimiter.length());
     
     
     /////////////////////////////s=mean   key=key of word
     node *p,*q;
     node *t=new node;
     t->key=key;//key
     t->val=s;//mean
     t->left=NULL;
     t->right=NULL;
     t->color='r';
     p=root;
     q=NULL;
     if(root==NULL)//agar rishe nadarim pas hamin node ra rishe qrar midahim
     {     //cout<<"root is:"<<t->key<<endl;
           root=t;
           t->parent=NULL;
     }
     else //rb tree rishe darad pas node bayad dar jaye dorost instert shavad
     {
         while(p!=NULL)
         {
              q=p;
              if(p->key<t->key)
                  p=p->right;
              else
                  p=p->left;
         }
         t->parent=q;
         if(q->key<t->key)
              q->right=t;
         else
              q->left=t;
     }
     insertfix(root,t);
     //insertfix(t);
     
     
}

void RBtree::insertfix(node *&root, node *&pt)
{
    node *parent_pt = NULL;
    node *grand_parent_pt = NULL;
 
    while ((pt != root) && (pt->color != 'b') &&(pt->parent->color == 'r') )
    {
 
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
 
        /*  Case : A
            Parent of pt is left child
            of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left)
        {
 
            node *uncle_pt = grand_parent_pt->right;
 
            /* Case : 1
               The uncle of pt is also red
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color =='r')
            {
                grand_parent_pt->color = 'r';
                parent_pt->color = 'b';
                uncle_pt->color = 'b';
                pt = grand_parent_pt;
            }
 
            else
            {
                /* Case : 2
                   pt is right child of its parent
                   Left-rotation required */
                if (pt == parent_pt->right)
                {   
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                   pt is left child of its parent
                   Right-rotation required */
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color,
                           grand_parent_pt->color);
                pt = parent_pt;
            }
        }
 
        /* Case : B
           Parent of pt is right child
           of Grand-parent of pt */
        else
        {
            node *uncle_pt = grand_parent_pt->left;
 
            /*  Case : 1
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color ==
                                                    'r'))
            {
                grand_parent_pt->color = 'r';
                parent_pt->color = 'b';
                uncle_pt->color = 'b';
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                   pt is left child of its parent
                   Right-rotation required */
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                /* Case : 3
                   pt is right child of its parent
                   Left-rotation required */
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color,
                         grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
 
    root->color = 'b';
}

void RBtree::del(string x)
{
     if(root==NULL)
     {
           
           return ;
     }
     
     node *p;
     p=root;
     node *y=NULL;
     node *q=NULL;
     int found=0;
     while(p!=NULL&&found==0)
     {
           if(p->key==x){
		       
               found=1;
               }
           if(found==0)
           {    
                 if(p->key<x) p=p->right;
                 else
                    p=p->left;
           }
     }
     
     if(found==0)
     {
            
            return ;
     }
     else
     {
         //cout<<"\nDeleted Element: "<<p->key;
         //cout<<"\t mani:"<<p->val;
         //cout<<"\nColour: "; 
		 //if(p->color=='b')
            //cout<<"Black\n";
        // else  cout<<"Red\n"; 
		 /*
		 if(p->parent!=NULL) cout<<"\nParent: "<<p->parent->key;
         else  cout<<"\nThere is no parent of the node. "; 
         
		 if(p->right!=NULL) cout<<"\nRight Child: "<<p->right->key;
         else cout<<"\nThere is no right child of the node. "; 
		 
		 if(p->left!=NULL)  cout<<"\nLeft Child: "<<p->left->key;
         else  cout<<"\nThere is no left child of the node.  ";
         
         cout<<"\nNode Deleted."; */
		 if(p->left==NULL||p->right==NULL) y=p;
              
         else  y=successor(p);
         
		 
		     
         if(y->left!=NULL) q=y->left;
              
         else
         {
              if(y->right!=NULL)
                   q=y->right;
              else
                   q=NULL;
         }
         if(q!=NULL) q->parent=y->parent;
         
		      
         if(y->parent==NULL) root=q;
              
         else
         {
             if(y==y->parent->left)
                y->parent->left=q;
             else
                y->parent->right=q;
         }
         if(y!=p)
         {
             p->color=y->color;
             p->key=y->key;
             p->val=y->val;
         }
         
         
     }
}

node* RBtree::successor(node *p)// find nearest node to node p (vurudi) 
{
     node *y=NULL;
     if(p->left!=NULL)//yekbar be chap sepas ta jayi ke mishe be rast boro
     {
         y=p->left;
         while(y->right!=NULL)
              y=y->right;
     }
     else //yekbar be rast sepas ta jayi ke mishe be  chap boro
     {
         y=p->right;
         while(y->left!=NULL)
              y=y->left;
     }
     return y;
}

void RBtree::disp()//come here from int main
{    
     display(root);
}
void RBtree::display(node *p)//display a node info    (tree inorder displaye: left root right  )
{
     if(root==NULL)//root is null so tree is null
     {
          cout<<"-1";
          return ;
     }
     
     if(p!=NULL)// tree has nodes
     {          if(p->left) {//agar zirderakht chap darad namayesh bede  on ra
                display(p->left);
                 }
                
                cout<<p->key<<":";//khode node ra namyesh bede
                cout<<p->val<<"\t"; 
               
                
                
                if(p->right){//agar zirderakht rast darad namayesh bede  on ra
    
                      display(p->right);
                      }
    
     }
     
}
int RBtree::getindex(node *p,node *x){ // index node x dar peymayesh inorder ra peyda mikonad (unrecurcive)
	stack<node *> s; //stack tarif mikonim
    node *curr = root;
    int count=0; //save index 
   
    while (curr != NULL || s.empty() == false) { //ta zamani k stack khali nist va node null nashode node hara push karde zirderakht chap ra trace mikonim sepas node ra pop va bad zir derakhrt rast on
    	
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
 
        /* Current must be NULL at this point */
        curr = s.top();
        if (curr != NULL & curr->key==x->key ) {  return count;  }//node x peyda shod ,count index on ast
		s.pop();
        count=count+1;
        
 
        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
 
    } /* end of while */

}
void RBtree::search(string x) //search :) derakht ra ba komak  vizhegi BST(binary search tree)  peymayesh mikonad ta node morde nazar ra peyda konad
{
     if(root==NULL)
     {
           cout<<"-1" ;
           return  ;
     }
     
     node *p=root;
     int found=0;
     while(p!=NULL && found==0)
     {
            if(p->key==x)
                found=1;
            if(found==0)
            {
                 if(p->key<x) p=p->right;
                 else
                      p=p->left;
            }
     }
     if(found==0)
          cout<<"-1"; //node peyda nasho :(
     else{//node peyda shod pas index on ra ba getindex() namayesh midahad :)
     	node *r=root;
     	cout<<getindex(r,p);
	 }
     
    
    
}

void RBtree::rotateLeft(node *&root, node *&pt)
{
    node *pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL)
        pt->right->parent = pt;
 
    pt_right->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 
    pt_right->left = pt;
    pt->parent = pt_right;
}
 
void RBtree::rotateRight(node *&root, node *&pt)
{
    node *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;
}
 
 



int main()
{
    int n,m=0;
    
    RBtree obj;
    
    
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
       obj.insert();
	   
    	}
    	
    string delimiter =" ";
    size_t pos = 0;
	string s;
    cin>>m;
    cin.ignore();
	vector<string> v1;
	 
    for(int i=0;i<m;i++){
	getline(cin,s);
	v1.push_back(s);  
    } 
	
    for(vector<string>::iterator itr=v1.begin();itr!=v1.end();++itr)  {
	
     
     s=*itr;
     
     if(s[0]=='p' || s[0]=='P'){
     	obj.disp();
     	cout<<"\n";
	 }
	 else if(s[0]=='r' || s[0]=='R'){
	 	string key = s.substr(2);
     	obj.del(key);
	 
	 }
	 else if(s[0]=='s' || s[0]=='S'){
	 	string key = s.substr(2);
     	obj.search(key);
     	cout<<"\n";
	 }
	 
	
	}
	
	
		
    return 1;
}
