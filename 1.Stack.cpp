#include<iostream>
using namespace std;
template<class t>
class stack
{
private:
t *st;
int capacity;
int top;
public:
stack(int a);
~stack();
void push(t element);
t pop();
bool isempty();
void display();
int size();
t topelement();
};
//constructor
template<class t>
stack<t>::stack(int s)
{
capacity=s;
top=-1;
st=new t[capacity];
}
//destructor
template<class t>
stack<t>::~stack()
{
delete[] st;
}
//isempty function
template<class t>
bool stack<t>::isempty()
{
if(top==-1)
return true;
else
return false;
}
//size
template<class t>
int stack<t>::size()
{
return(top+1);
}
//display
template<class t>
void stack<t>::display()
{
if(isempty())
cout<<"stack is empty\n";
else
{
cout<<"elements in stack are";
for(int i=0;i<top;i++)
cout<<st[i]<<" ";
}
}
//top element
template<class t>
t stack<t>::topelement()
{
if(isempty())
cout<<"stack empty\n";
else
return st[top];
}
template<class t>
void stack<t>::push(t element)
{
if(top==(capacity-1))
cout<<"stack overflow\n";
else
{
top++;
st[top]=element;
}
}
template<class t>
t stack<t>::pop()
{
if(isempty())
cout<<"empty stack cannot be popped\n";
else
{
t x=st[top];
top--;
return x;
}
}
main()
{
stack<int>s(5);
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
s.display();
cout<<"\n size of the stack is \n"<<s.size();
cout<<"\ntop element of stack is\n"<<s.topelement();
float x=s.pop();
cout<<"\n popped element is :"<<x;
s.display();
cout<<"\n size of the stack is"<<s.size();
cout<<"\n topelement of the stack is "<<s.topelement();
}