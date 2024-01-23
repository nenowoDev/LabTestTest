#include <iostream>
#include <string>

using namespace std;

class Stack{
    int top;
    int data[100];

    public:
        Stack(){
            top=-1;
        }
        bool isEmpty(){
            return top==-1;
        }
    
        void push(int x){
            if(isEmpty()){
                top+=1;
                data[top]=x;
            }
            else{
                top+=1;
                data[top]=x;
            }
        }

        void pop(){
            if(isEmpty()){

            }
            else{
                top-=1;
            }
        }

        int stacktop(){
            if(isEmpty()){
                return 0;
            }
            else{
                return data[top];

            }
        }


        
};

int main(){

    string a="22*45*6*+25*/";

    Stack coolppl;
    for(char ch:a){
        if(isdigit(ch)){
            coolppl.push(static_cast<double>(ch)-static_cast<double>('0'));
        }
        else{
            int temp=coolppl.stacktop();
            coolppl.pop();
            int temp2;
            if (ch == '+') {
                int temp2 = coolppl.stacktop() + temp;
                coolppl.pop();
                coolppl.push(temp2);
            } 
            else if (ch == '-') {
                int temp2 = coolppl.stacktop() - temp;
                coolppl.pop();
                coolppl.push(temp2);
            } 
            else if (ch == '*') {
                int temp2 = coolppl.stacktop() * temp;
                coolppl.pop();
                coolppl.push(temp2);
            } 
            else if (ch == '/') {
                if (temp != 0) {
                    int temp2 = coolppl.stacktop() / temp;
                    coolppl.pop();
                    coolppl.push(temp2);
                } 
                else {
                    cout << "Error: Division by zero" << endl;
                }
            }

        }
    }

    
    cout<<coolppl.stacktop();
    coolppl.pop();
    

    
}