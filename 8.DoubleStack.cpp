#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};
class stack
{
private:
    Node *top;
    int len =0;
public:
    stack(){top=NULL;};
    void push(int x);
    int pop();
    void display();
};

void stack::push(int x)
{
    Node *t = new Node;
    if(t==NULL){cout<<"Stack full "<<endl;return;}
    if(len==0)
    {
        t->next=t->prev=NULL;
        t->data=x;
        top=t;
    }
    else
    {
        t->data=x;
        t->next=top;
        top->prev=t;
        top=t;
    }

    len++;
}

int stack::pop()
{
    int x = -1;
    if(top==NULL){cout<<"stack is empty"<<endl;return -1;}
    Node *t = top;
    x = top->data;
    if(top->next){top = top->next;top->prev=NULL;}
    delete t;
    return x;
}

void stack::display()
{
    Node *t = top;
    while(t)
    {
        cout<<t->data<<endl;
        t=t->next;
    }
}

int main() {
stack stk;
stk.push(10);
stk.push(20);
stk.push(30);
stk.display();
cout<<"the element popped is "<<stk.pop()<<endl;
return 0;
}