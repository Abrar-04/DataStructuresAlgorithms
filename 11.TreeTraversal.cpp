#include <iostream>
using namespace std;
class circularQueue;
class bt;
class treenode
{
    friend class circularQueue;
    friend class bt;
    treenode *lchild;
    int data;
    treenode *rchild;
};

class circularQueue
{
    private:
    int capacity,count,rear,front;
    treenode **q;
    public:
    circularQueue(int c)
    {
        capacity = c;
        count = front = rear = 0;
        q = new treenode*[capacity];
    }
    ~circularQueue()
    {
        delete []q;
    }

    bool isempty();
    bool isfull();
    void insert(treenode * x);
    treenode* remove();
    void display();

};

bool circularQueue::isempty(){return front==rear?true:false;}
bool circularQueue::isfull(){return (((rear+1)%capacity)==front)?true:false;}

void circularQueue::insert(treenode *x)
{
    if(isfull())
    {
        cout<<"Queue overflow"<<endl;
    }
    else
    {
        rear = (rear+1)%capacity;
        q[rear] = x;
        count++;
    }
}

treenode* circularQueue::remove()
{
    if(isempty())
    {
        cout<<"Queue is empty nigg"<<endl;
    }
    else
    {

        front = (front+1)%capacity;
        count--;
        return q[front];

    }
}


class bt
{
    treenode *root=NULL;
public:
    void create();
    void preorder(){preorder(root);}
    void preorder(treenode * );
    void inorder(){inorder(root);}
    void inorder(treenode *);
    void postorder(){postorder(root);}
    void postorder(treenode *);
    void levelorder(){levelorder(root);}
    void levelorder(treenode *);
    void count();

};
void bt::create()
{
    treenode *t,*p;
    int x;
    circularQueue q(100);
    root=new treenode;
    cout << " enter root value"<<endl;
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.insert(root);
    while(!q.isempty())
    {
        p=q.remove();
        cout<<"enter the left child of"<< p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new treenode;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.insert(t);
        }
        cout<<"enter the right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new treenode;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.insert(t);

        }
    }

}
void bt::preorder(treenode * p)
{
    if(p)
    {

        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void bt::inorder(treenode * p)
{
    if(p)
    {

        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void bt::postorder(treenode * p)
{
    if(p)
    {

        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}
void bt::levelorder(treenode *p)
{
    circularQueue q(100);
    cout<<p->data<<" ";
    q.insert(p);
    while(!q.isempty())
    {
        p=q.remove();
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            q.insert(p->lchild);
        }
        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            q.insert(p->rchild);
        }
    }

}

int main()
{
    bt b;
    b.create();
    cout<<"predorder is ";
    b.preorder();
    cout<<endl;
    cout<<"indorder is ";
    b.inorder();
    cout<<endl;
    cout<<"postorder is ";
    b.postorder();cout<<endl;
    cout<<"level order is";
    b.levelorder();

    return 0;
}


