#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};


struct Node *head=NULL,*tail=NULL;


void display(){
    struct Node *temp=head;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=head);
}


void displayRecur(struct Node *temp){
    static int flag=0;
    if(temp!=head || flag==0){
        flag=1;
        printf("%d ", temp->data);
        displayRecur(temp->next);
    }
    flag=0;
}


void insertAtEnd(int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        tail=head;
    }
    else{
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
}


void insertAtFront(int num){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        tail=head;
        return;
    }
    newNode->next=head;
    struct Node *temp=head;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=newNode;
    head=newNode;
}


void insertAtPosition(int num, int pos){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=num;
    if(head==NULL){
        head=newNode;
        newNode->next=head;
        tail=newNode;
        return;
    }
    if(pos==1){
        newNode->next=head;
        struct Node *temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
        //Instead of writing the above line for getting into the last node we can take help of tail pointer to work with it
        //tail->next=newNode;
        head=newNode;
    }
    else{
        struct Node *temp=head,*after=NULL;
        int k=pos-2;
        while(k--){
            temp=temp->next;
        }
        after=temp->next;
        temp->next=newNode;
        newNode->next=after;
    }
}


int getLength(){
    struct Node *temp=head;
    if(head==NULL)
        return -1;
    int cnt=0;
    do{
        cnt++;
        temp=temp->next;
    }while(temp!=head);
    return cnt;
}


void deleteNode(int ind){
    if(ind<1 || ind>getLength()+1){
        printf("Invalid Index!");
        return;
    }
    if(ind==1){
        struct Node *temp=head,*delNode=head;
        int x=temp->data;
        while(temp->next!=head)
            temp=temp->next;
        if(temp==head){
            free(head);
            head=NULL;
            printf("%d is deleted successfully", x);
            return;
        }
        head=head->next;
        temp->next=head;
        free(delNode);
        printf("%d is deleted successfully", x);
    }
    else{
        struct Node *temp=head,*prev=NULL;
        int ctr=1;
        while(temp){
            if(ctr==ind)
                break;
            ctr++;
            prev=temp;
            temp=temp->next;
        }
        int x=temp->data;
        prev->next=temp->next;
        free(temp);
        printf("%d is deleted successfully", x);
    }

}
int main(){
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    display();
    return 0;
}
