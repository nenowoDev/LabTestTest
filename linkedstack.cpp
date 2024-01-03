#include <iostream>
#include <string>

using namespace std;

struct node{

    int name;
    
    node* next;

};

class stack{
    private:
        node* top;
        node* head;
    public:
        stack(){
            top=nullptr;
        }
        bool isEmpty(){
            return head==nullptr;
        }
        void push(node* ins){
            if(isEmpty()){
                top=ins;
                top->next=nullptr;
                head=top;
            }
            else{
                top->next=ins;
                top=top->next;
                top->next=nullptr;
            }
        }
        void pop(){
            if(isEmpty()){
                cout<<"\n\n\t\tNOTHING BRO";

            }
            else if(head==top){
                cout<<"\n\n\t\tPopped : "<<top->name;
                delete head;
                head=nullptr;
                top=nullptr;
            }
            else{
                node* temp=head;
                while(temp->next!=top){
                    temp=temp->next;
                }

                cout<<"\n\n\t\tPopped : "<<top->name;
                delete top;
                top=temp;
                
            }
        }
        void stacktop(){
            if(isEmpty()){
                cout<<"\n\n\t\tEMPTY";
            }
            else{
                cout<<"\n\n\t\t"<<top->name;
            }
            
        }
};

int main(){
    stack a;

    node* one=new node;
    one->name=1;

    node* two=new node;
    two->name=2;

    node* three=new node;
    three->name=3;

    node* four=new node;
    four->name=4;

    node* five=new node;
    five->name=5;

    a.push(one);
    a.stacktop();

    a.push(two);
    a.stacktop();

    a.push(three);
    a.stacktop();

    a.pop();
    a.pop(); 
    a.pop();
    a.pop();

    a.push(four);
    a.stacktop();

    


}