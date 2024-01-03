#include <iostream>
#include <string>

using namespace std;


class node{

    string day;
    string title;
    
    public:
        node* next;
        node* prev;

        node(string d=" ",string t=" "){
            day=d;
            title=t;
        }
        void display(){
            cout<<" [ "<<day<<","<<title<<" ] ";
        }
};

class list{

    public:
        node* head;
        list(){
            head=nullptr;
        }
        bool isEmpty(){
            return head==NULL;
        }

        void insertfront(node* ins){

            if(isEmpty()){
                head=ins;
                head->next=nullptr;
                head->prev=nullptr;
            }
            else{
                ins->next=head;
                ins->prev=nullptr;
                head=ins;

                ins=ins->next;
                ins->prev=head;
            }

        }

        void insertat(node* ins,int index){
            int count=1;
            
            node* temp=head;
            while(temp->next!=nullptr&&count<index){
                temp=temp->next;
                count++;
            }

            if(index==count){
          
                
                
                ins->next=temp;
                ins->prev=temp->prev;

                temp->prev=ins;

                temp=ins->prev;
                temp->next=ins;
            }
            else{
                
                cout<<"\n\n\t\t Invalid Index bro";

            }

        }
        
        void insertlast(node* ins){
            if(isEmpty()){

                head=ins;
                head->next=nullptr;
                head->prev=nullptr;

            }
            else{
                node* temp=head;
                
                while(temp->next!=nullptr){
                    temp=temp->next;
                }

                ins->prev=temp;
                ins->next=nullptr;
                
                temp->next=ins;

            }


        }

        void delfront(){
            if(isEmpty()){
                cout<<"Nothing to del"<<endl;
            }

            else{
                node* temp=head;
                if(temp->next!=nullptr){
                    temp=temp->next;
                    temp->prev=nullptr;
                    delete head;
                    head=temp;
                }

                else{
                    delete head;
                    head=nullptr;
                }
                

            }
        }

        void delback(){
            if(isEmpty()){
                cout<<"\nNothing to del"<<endl;
            }

            else{
                
                node* temp=head;
                node* del;
                if(temp->next!=nullptr){
                    while(temp->next!=nullptr){
                        temp=temp->next;
                    }
                    temp=temp->prev;
                    del=temp->next;

                    temp->next=nullptr;

                    delete del;
                    
                }

                else{
                    delete head;
                    head=nullptr;
                }

            }
        }

        void delat(int index){
            int count=1;
            node* temp=head;
            node* del;
            
            if(isEmpty()){
                cout<<"\nNothing to del"<<endl;
            }

            else if(index==1){
                delfront();
            }

            else{

                while(temp->next!=nullptr&&count<index){
                temp=temp->next;
                count++;
                }

                if(count==index){
                    
                    del=temp;
                    

                    if(del->next==nullptr){
                        delback();
                    }
                    else{
                        temp=temp->prev;
                        temp->next=temp->next->next;
                        temp=temp->next;
                        temp->prev=temp->prev->prev;

                        delete del;
                    }
                    

                }

                else{
                    cout<<"\n\n\t\t Invalid Index bro";
                }


            }
            

        }

        void displayforward(){
            
            node* temp=head;

            if(isEmpty()){
                cout<<"\t\t\n\n Nothing to display";
            }

            else{
                
                cout<<"\t\t\n\nList : ";
                temp->display();
                while(temp->next!=nullptr){
                    temp=temp->next;
                    temp->display();
                }

                cout<<"\n";

            }
            
        }

        void displaybackward(){
            
            node* temp=head;

            if(isEmpty()){
                cout<<"\t\t\n\n Nothing to display";
            }

            else{
                
                cout<<"\t\t\n\nList : ";
                while(temp->next!=nullptr){     
                    temp=temp->next;
                }


                temp->display();
                while(temp->prev!=nullptr){
                    temp=temp->prev;
                    temp->display();
                }

                cout<<"\t\t\n\n";

            }
            
        }


};



int main(){

    list something;

    something.displayforward();
    something.displaybackward();

    node* something1=new node("monday","1");
    node* something2=new node("tuesday","2");
    node* something3=new node("wednesday","3");
    node* something4=new node("thursday","4");
    node* something5=new node("friday","5");

    
    something.insertfront(something1);
    something.displayforward();
    something.displaybackward();
    
    something.insertlast(something3);
    something.displayforward();
    something.displaybackward();

    something.insertat(something2,2);
    something.displayforward();
    something.displaybackward();

    something.insertlast(something4);
    something.displayforward();
    something.displaybackward();

    something.insertlast(something5);
    something.displayforward();
    something.displaybackward();

    something.delfront();
    something.displayforward();
    something.displaybackward();

    something.delback();
    something.displayforward();
    something.displaybackward();

    something.delat(3);
    something.displayforward();
    something.displaybackward();

    something.delat(2);
    something.displayforward();
    something.displaybackward();


    
}