#include <iostream>
#include <string>

using namespace std;

struct node{
    string name;
    node* next;
    node* prev;
};

class list{

    node* head;
    node* last;

    public:
        list(){
            head=nullptr;
            last=nullptr;
        }

        bool isEmpty(){
            return head==nullptr;
        }

        void insertfront(){
            node* ins=new node;
            cout<<" \n\n[F] Enter name: ";
            cin>>ins->name;
            if(isEmpty()){
                head=ins;
                head->next=head;
                head->prev=head;

                last=head;
            }
            else{
                
                
                
                ins->prev=head->prev;
                ins->next=head;

                head->prev=ins;
                last->next=ins;

                head=ins;
                


            }
        }

        void insertback(){
            node* ins=new node;
            cout<<" \n\n[B] Enter name: ";
            cin>>ins->name;

            if(isEmpty()){
                head=ins;
                head->next=head;
                head->prev=head;

                last=head;
            }

            else{
                
                last->next=ins;
                ins->prev=last;

                head->prev=ins;
                ins->next=head;

                last=ins;


            }

        }

        void insertat(){
            node* ins=new node;
            int index;

            cout<<" \n\n[A] Enter name: ";
            cin>>ins->name;
            cout<<" [A] Enter Index: ";
            cin>>index;

            int count=1;

            node* temp=head;
            while(temp->next!=head&&count<index){
                temp=temp->next;
                count++;
            }

            if(index==1){

                
                
                ins->prev=head->prev;
                ins->next=head;

                head->prev=ins;
                last->next=ins;

                head=ins;
                
            }
            else if(count==index){
                ins->prev=temp->prev;
                ins->next=temp;

                temp->prev=ins;
                temp=temp->prev->prev;
                temp->next=ins;
            }
            else if(index-count==1){
                last->next=ins;
                ins->prev=last;

                head->prev=ins;
                ins->next=head;

                last=ins;
            }

            else{
                cout<<"\n\n\t\tIndex doesnt exist bro\n\n";
            }
            
        }

        void delfront(){
            if(isEmpty()){
                cout<<"\n\n\t\tNothing to del";
            }

            else if(head->next==head){
                delete head;
                head=nullptr;
                last=nullptr;
            }

            else{
                node* temp=head;
                temp=temp->next;
                temp->prev=last;
                last->next=temp;
                delete head;
                head=temp;
            }
        }

        void delback(){
            if(isEmpty()){
                cout<<"\n\n\t\tNothing to del";
            }
            else if(last->prev==last){
                delete last;
                last=nullptr;
                head=nullptr;
            }

            else{
                node* temp=last;
                temp=temp->prev;

                temp->next=head;
                head->prev=temp;

                delete last;
                last=temp;


            }


        }

        void delat(){
            
            int index;
            cout<<" \n\n[D] Enter Index: ";
            cin>>index;
            
            if(isEmpty()){
                cout<<"\n\n\t\tNothing to del";
            }

            node* temp=head;
            int count=1;
            while(temp->next!=head&&count<index){
                temp=temp->next;
                count++;
            }

            if(index==1){

                delfront();
            }

            else if(temp->next==head&&count==index){
                delback();
            }

            else if(count==index){
                cout<<"es";
                node* del=temp;
                temp=temp->prev;
                temp->next=del->next;

                temp=del->next;
                temp->prev=del->prev;

                delete del;

            }

            else{
                cout<<"\n\n\t\tIndex doesnt exist bro\n\n";
            }

        }


        void search(){
            if(isEmpty()){
                cout<<"\n\n\t\tWhat to search bro";
            }
            else{
                string find;
                cout<<"\n\n[S] Enter keyword : ";
                cin>>find;
                
                int count=1;
                node* temp=head;
                while(temp->next!=head&&temp->name!=find){
                    temp=temp->next;
                    count++;
                }

                if(temp->name==find){
                    cout<<"\n\n\t\tFOUND at index"<<count;
                }
                else{
                    cout<<"Doesn't exist bro"<<endl;
                }
            }
        }

        void displayforward(){

            if(isEmpty()){
                cout<<"\n\n\t\tNothing to display";

            }

            else{
                cout<<"\n\n\t\tList : ";
                node* temp=head;
                cout<<temp->name<<" ,";
                while(temp->next!=head){
                    
                    temp=temp->next;
                    cout<<temp->name<<" ,";
                }

            }
        }

        void displaybackward(){

            if(isEmpty()){
                cout<<"\n\n\t\tNothing to display";

            }

            else{
                cout<<"\n\n\t\tList : ";
                node* temp=head;
                
                while(temp->next!=head){
                    temp=temp->next;
                    
                }

                cout<<temp->name<<" ,";
                while(temp->prev!=last){
                    temp=temp->prev;
                    cout<<temp->name<<" ,";
                }
                

            }
        }



};


int main(){

    list something;
    something.insertfront();
    something.displayforward();
    something.displaybackward();


    something.insertfront();
    something.displayforward();
    something.displaybackward();

    something.insertfront();
    something.displayforward();
    something.displaybackward();
    
    something.insertfront();
    something.displayforward();
    something.displaybackward();
/*
    something.insertback();
    something.displayforward();
    something.displaybackward();
    
    something.insertback();
    something.displayforward();
    something.displaybackward();

    something.insertback();
    something.displayforward();
    something.displaybackward();
    
    something.insertback();
    something.displayforward();
    something.displaybackward();

    something.insertat();
    something.displayforward();
    something.displaybackward();

    something.insertat();
    something.displayforward();
    something.displaybackward();
    
    something.insertat();
    something.displayforward();
    something.displaybackward();
    
    something.insertat();
    something.displayforward();
    something.displaybackward();
    

    something.delfront();
    something.displayforward();
    something.displaybackward();

    something.delfront();
    something.displayforward();
    something.displaybackward();

    something.delfront();
    something.displayforward();
    something.displaybackward();

    something.delfront();
    something.displayforward();
    something.displaybackward();

    something.delfront();
    something.displayforward();
    something.displaybackward();

    something.delfront();
    something.displayforward();
    something.displaybackward();

   

    something.delback();
    something.displayforward();
    something.displaybackward();

    something.delback();
    something.displayforward();
    something.displaybackward();
    
    something.delback();
    something.displayforward();
    something.displaybackward();
    
    something.delback();
    something.displayforward();
    something.displaybackward();
    
    something.delback();
    something.displayforward();
    something.displaybackward();

 


    something.delat();
    something.displayforward();
    something.displaybackward();

    something.delat();
    something.displayforward();
    something.displaybackward();

    something.delat();
    something.displayforward();
    something.displaybackward();

    something.delat();
    something.displayforward();
    something.displaybackward();

    something.delat();
    something.displayforward();
    something.displaybackward();

    */
    
    something.search();

}