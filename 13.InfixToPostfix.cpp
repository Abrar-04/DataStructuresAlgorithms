#include <iostream>
#include <cstring>

using namespace std;



template<class t>
class Stack{
private:
    t *s;
    int top;
    int capacity;
public:
    Stack(int);
    void push(const t&);
    t pop();
    void peek(int);
    t topr();
    bool isEmpty();
    bool isFull();
    void display();

};

template<class t>
Stack<t>::Stack(int n):capacity(n){
    s = new t[capacity];
    top = -1;
}

template<class t>
t Stack<t>::topr()
{
    if(isEmpty()){cout<<"Stack empty"<<endl;}
    else{
  return s[top];}
}

template<class t>
void Stack<t>::push(const t& item){
    if(isFull()){
        cout<<"Stack Overflowed"<<endl;
    }else{
        s[++top] = item;
    }
}

template<class t>
t Stack<t>::pop(){
    if(isEmpty()){
        cout<<"Stack underflow"<<endl;
    }else{
        cout<<"the element popped was  "<< s[top]<<endl;
        return s[top--];
    }
}

template<class t>
void Stack<t>::peek(int d){
    if(top+1-d<0){
        cout<<"invalid peek operation"<<endl;

    }else{
        cout<<"ok so kid you asked for this "<<(s[top+1-d])<<endl;
    }
}

template<class t>
bool Stack<t>::isEmpty(){
        if(-1 == top){
            return true;
        }else{ return false;}

}

template<class t>
bool Stack<t>::isFull(){
    if(top == capacity - 1){
        return true;
    }else{
        return false;
        }
}

template<class t>
void Stack<t>::display(){
    if(isEmpty()){
        cout<<"Stacks empty dude"<<endl;

    }else{
        for(int i=0;i<=top;i++){
            cout<<s[i]<<"  ";
        }
        cout<<" <-- this is top nigg"<<endl;
    }
}

Stack <char> s(40);



    int pre(char x)
    {
        if(x=='+' || x=='-')
            return 1;
        else if(x=='*' || x=='/')
            return 2;
        return 0;
    }

    bool isOperand(char x)
    {
        if(x=='+' || x=='-' || x=='*' || x=='/')
            return false;
        else
            return true;
    }

    char* infixtopost(char *infix)
    {
        int i=0,j=0;
        char *postfix;
        int len = strlen(infix);
        postfix = new char[30];

        while(infix[i]!='\0')
        {
            if(isOperand(infix[i]))
            {
                postfix[j++] = infix[i++];
            }
            else
            {
                if(pre(infix[i])>pre(s.topr()))
                {
                    s.push(infix[i++]);
                }
                else
                {

                    postfix[j++] = s.pop();

                }
            }
        }
        while(!s.isEmpty())
        {
            s.display();

            postfix[j++] = s.pop();
            postfix[j] = '\0';

        }
        return postfix;

    }


int main()
{
    char *infix="a+b*c-d/e";
    s.push('#');

    char *postfix = infixtopost(infix);

    cout<<postfix<<endl;





}