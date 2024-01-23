#include <iostream>
#include <string>

using namespace std;

class stack{

    int top;
    char data[100];

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


        char stacktop(){
            
            
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


        void push(char x){
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
                //cout<<"\n\n\t\tPopped :"<<data[top];
                top-=1;

            }
        }

};

int getpres(char a){
    
    if(a=='+'||a=='-'){
        return 1;
    }

    else if(a=='*'||a=='/'){
        return 2;
    }

    else 
        return 0;
        

}




int main(){

    string a="2+2*4/2";

    string neww;


    stack stackk;


    stackk.createstack();
    stackk.push('#');

    for(char ch:a){
        if(isalnum(ch)){
            neww+=ch;
        }

        else{

            if(ch=='('){
                stackk.push(ch);
            }
            else if(ch==')'){
                while(stackk.stacktop()!='('){
                    neww+=stackk.stacktop();
                    stackk.pop();
                }
                stackk.pop();
            }
            else if(getpres(stackk.stacktop())>getpres(ch)||getpres(stackk.stacktop())==getpres(ch)) {
                neww+=stackk.stacktop();
                stackk.pop();
                stackk.push(ch);
            }
            else{
                stackk.push(ch);
            }
            
        }
        
    }

    while(stackk.stacktop()!='#'){
        neww+=stackk.stacktop();
        stackk.pop();
    }

    cout<<"\n\n\t\t"<<neww;
}


