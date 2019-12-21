#include <iostream>

using namespace std;
template<class T>
class Node
{
    public:
    Node<T> *lchild;
    T data;
    Node<T> *rchild;
};

template<class T>
class bst
{
private:
    Node<T> *root;
public:
    bst(){root=NULL;}

    //inserting element in binary tree
    void insert( T key);

    //printing tree nodes in inorder method
    void inorder(Node<T> *p);

    //same method without parameter version
    void inorder(){inorder(root);}

    //finding height of node function
    int height(Node<T>* p);
    
 
    //function for searching for a node with the given value
    Node<T>* search (T key);
   
};

template<class T>
void bst<T>::insert(T key)
{
    Node<T> *t = root;
    Node<T> *p,*r=NULL;
    if(root==NULL)
    {
        p = new Node<T>;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t)
    {
        r=t;
        if(key>t->data)
        {
            t=t->rchild;
        }else if(key<t->data)
        {
            t=t->lchild;
        }else{return;}
    }
    p = new Node<T>;
    p->lchild=p->rchild=NULL;
    p->data=key;
    if(key>r->data)
        {
            r->rchild=p;
        }else
        {
            r->lchild=p;
        }

}

template<class T>
void bst<T>::inorder(Node<T> *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<endl;
        inorder(p->rchild);
    }
}

template<class T>
Node<T>* bst<T>::search(T key)
{
    Node<T> *t=root;

    while(t)
    {
        if(key==t->data){
            cout<<"\nfound "<<t->data;
            return t;}
        else if(key>t->data)
            t=t->rchild;
        else if(key<t->data)
            t=t->lchild;
    }
    return NULL;
}


int main()
{
    bst <int>b;

    b.insert(50);
    b.insert(20);
    b.insert(10);
    b.insert(30);
    b.insert(40);
    b.insert(60);
    b.inorder();
    b.search(40);

}