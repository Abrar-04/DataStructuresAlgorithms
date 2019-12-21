#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};
class linkqueue
{
private:
    Node *front,*rear;
public:
    linkqueue(){front=rear=NULL;}
    ~linkqueue();

    void insert(int x);
    int remove();
    bool isEmpty();
    int search(int key);
    void display();
};

bool linkqueue::isEmpty()
{
    if(front==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void linkqueue::display()
{
    Node *p = front;
    while(p)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

void linkqueue::insert(int x)
{
    Node *t = new Node;
    t->data = x;
    t->next=NULL;

    if(isEmpty())
    {
        front=rear=t;

    }
    else
    {
        rear->next=t;
        rear=t;
    }

}

int linkqueue::remove()
{
    int x=-1;
    if(isEmpty())
    {
        cout<<"Queue is empty"<<endl;

    }
    else
    {
        Node *t = front;

        //if the element being deleted is last element
        if(front==rear)
        {
            front=NULL;
            rear=NULL;
        }
        else
        {
            front=front->next;
        }

        x = t->data;
        delete t;
        return x;
    }
}

int linkqueue::search(int key)
{
    int x=-1;
    Node *p = front;
    while(p)
    {
        if(p->data==key)
        {
            x=p->data;
        }
        p=p->next;
    }
    return x;
}

linkqueue::~linkqueue()
{
    Node *p = front;
    while(p)
    {
        front=front->next;
        delete p;
        p=front;
    }
}

main() {
    int value,x;
    linkqueue q;
    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40);
    q.insert(50);
    cout << "\nthe queue elements are \n";
    q.display();
    int e = q.remove();
    cout << "\nremoved element is\n" << e << endl;
    cout << "\nnow list is\n";
    q.display();
    int y = q.remove();
    cout << "\nNow removed element is\n" << y <<endl;
    cout << "\nnow list is\n";
    q.display();
    cout<<"\n Enter the element to search"<<endl;
    cin>>x;
    value = q.search(x);
    if(value==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"The element "<<value<<" was found"<<endl;
    }
}