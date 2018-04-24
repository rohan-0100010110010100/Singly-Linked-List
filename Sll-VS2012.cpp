#include <iostream>
#include <conio.h>
#include <stack>
using namespace std;


struct queue {
    struct queue* nque;
    struct queue* rque;
    long long data;
};

struct queue* last = nullptr;


//Insertion in a linkedlist
void addnode(struct queue** head,long long data) {
    struct queue* nptr;

    nptr = (struct queue*) malloc(sizeof(struct queue));
    nptr->data = data;
    nptr->nque = nullptr;
    if((*head)==nullptr) {
        (*head)= nptr;
        last = (*head);
        return;
    } else
    {
        last->nque = nptr;
        last = last->nque;
    }

    return;

}

// Delete Duplicates in linkedlist
void delDuplicate(struct queue** head) {
    struct queue** indirect =  (struct queue**) malloc(sizeof(struct queue));
    struct queue** inner =  (struct queue**) malloc(sizeof(struct queue));
    indirect = head;
    while( (*indirect) !=nullptr) {
        inner = indirect;
        while((*inner)->nque!=nullptr) {
            if((*inner)->nque->data == (*indirect)->data) {
                (*inner)->nque = (*inner)->nque->nque;
            } else {
                inner = &(*inner)->nque;
            }
        }
        indirect = &(*indirect)->nque;
    }


}

//Reversing a linkedlist
void reverseList(struct queue** head) {
    stack<queue*>s;
    struct queue** indirect = (struct queue**)malloc(sizeof(struct queue));
    indirect =head;
    s.push(nullptr);
    while( (*indirect)->nque !=nullptr) {
        s.push((*indirect));
        indirect = &(*indirect)->nque;
    }
    (*head)=(*indirect);
    while(!s.empty()) {
        (*indirect)->nque=s.top();
        indirect = &(*indirect)->nque;
        s.pop();
    }

}


//Updating a particular element in linkedlist
void update(struct queue **head,long long data,long long data2) {
    struct queue** indirect =  (struct queue**) malloc(sizeof(struct queue));
    indirect = head;

    while( (*indirect)->data!= data) {
        indirect = &(*indirect)->nque;
    }

    (*indirect)->data = data2;
}

//Printing the linkedlist
void printList(struct queue *head)
{
    struct queue *temp = head;
    while(temp != nullptr)
    {
        printf("%lld  ", temp->data);
        temp = temp->nque;
    }
}



//Deleting a particular node in linkedlist
void remove(struct queue **head,long long data) {
    struct queue** indirect =  (struct queue**) malloc(sizeof(struct queue));
    indirect = head;

    while( (*indirect)->data!= data) {
        indirect = &(*indirect)->nque;

    }

    *indirect = (*indirect)->nque;
}



int main(int argc, char const *argv[])
{



    struct queue* que = nullptr; // This is header of linkedlist


    addnode(&que,22);
    addnode(&que,21);
    addnode(&que,23);
    addnode(&que,67);
    addnode(&que,78);
    addnode(&que,89);
    addnode(&que,89);
    addnode(&que,89);
    addnode(&que,89);
    addnode(&que,89);
    addnode(&que,89);
    addnode(&que,89);
    addnode(&que,89);
    addnode(&que,22);
    addnode(&que,22);
    addnode(&que,23);
    addnode(&que,23);
    addnode(&que,78);
    addnode(&que,78);
    printList(que);
    cout << endl;
    reverseList(&que);
    printList(que);
    cout << endl;
    delDuplicate(&que);
    printList(que);


    getchar();

    return 0;
}
