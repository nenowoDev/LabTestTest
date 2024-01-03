#include <iostream>
#include <string>

using namespace std;

class stack{

    int top;
    int data[10];

    public:
        void createstack(){
            top=-1;
        }
        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top==10-1;
        }


        int stacktop(){
            
            
            return data[top];
            
            
        }

        void displ(){
            if(isEmpty()){
                cout<<"empty";
            }
            else{
                cout<<"\n\n\t\t";
                cout<<top;
                cout<<"\n\t\t"<<stacktop();
            }
        }


        void push(int x){
            if(isFull()){
                cout<<"\n\n\t\tFULL BRO";
            }
            else{
                top++;
                data[top]=x;
            }
        }


        void pop(){
            if(isEmpty()){
                cout<<"\n\n\t\tEMPTY BRO";
            }
            else{
                cout<<"\n\n\t\tPopped :"<<data[top];
                top-=1;

            }
        }

};


int main(){

    cout<<"\n\n\t\tSTACK";
    stack ok;

    ok.createstack();
    ok.displ();

    ok.push(55);
    ok.displ();

    ok.push(11);
    ok.displ();

    ok.push(22);
    ok.displ();

    ok.pop();
    ok.pop();
    ok.pop();
    ok.pop();
    ok.pop();

    ok.push(55);
    ok.displ();

    ok.push(11);
    ok.displ();

    ok.pop();

    ok.push(22);
    ok.displ();

    ok.pop();
    ok.pop();


    



}