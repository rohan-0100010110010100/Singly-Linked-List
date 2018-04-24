#include <bits/stdc++.h>
#include <stack>

    using namespace std;

struct llist{
    struct llist* nque;
    struct llist* rque;
    long long data;
};

struct llist* last=NULL;

//Insertion in a llist
void addnode(struct llist** head, long long data) {
    struct llist* nptr;

    nptr = (struct llist*)malloc(sizeof(struct llist));
    nptr->data = data;
    nptr->nque = NULL;
    if ((*head) == NULL) {
        (*head) = nptr;
        last = (*head);
        return;
    } else {
        last->nque=nptr;
        last=last->nque;
    }

    return;

}

// Delete Duplicates in llist
void delDuplicate(struct llist** head) {
    struct llist** indirect = (struct llist**)malloc(sizeof(struct llist));

    struct llist** inner = (struct llist**)malloc(sizeof(struct llist));
    indirect = head;

    while ((*indirect) != NULL) {
        inner = indirect;
        while ((*inner)->nque != NULL) {
            if ((*inner)->nque-> data==(*indirect)->data) {
                (*inner)->nque=(*inner)->nque->nque;
            } else {
                inner=&(*inner)->nque;
            }
        }
        indirect=&(*indirect)->nque;
    }

}

//Reversing a llist
void reversellist(struct llist** head) {
    stack <llist*> s;
    struct llist** indirect = (struct llist**)malloc(sizeof(struct llist));

    indirect = head;

    s.push(NULL);

    while ((*indirect)->nque != NULL) {
        s.push((*indirect));
        indirect=&(*indirect)->nque;
    }

    (*head) = (*indirect);

    while (!s.empty()) {
        (*indirect)->nque = s.top();
        indirect=&(*indirect)->nque;
        s.pop();
    }

}

//Updating a particular element in llist
void update(struct llist** head, long long data, long long data2) {
    struct llist** indirect = (struct llist**)malloc(sizeof(struct llist));
    indirect = head;

    while ((*indirect)->data!=data) {
        indirect=&(*indirect)->nque;
    }

    (*indirect)->data = data2;
}

//Printing the llist
void printllist(struct llist* head) {
    struct llist* temp = head;
    while (temp != NULL) {
        printf("%lld  ", temp->data);
        temp = temp->nque;
    }

}

//Deleting a particular node in llist
void remove(struct llist** head, long long data) {
    struct llist** indirect = (struct llist**)malloc(sizeof(struct llist));
    indirect = head;

    while ((*indirect)->data!=data) {
        indirect = &(*indirect)->nque;

    }

    *indirect=(*indirect)->nque;
}

int main(int argc, char const * argv[]) {

    struct llist* que=NULL; // This is header of llist

    addnode( &que, 22);
    addnode( &que, 21);
    addnode( &que, 23);
    addnode( &que, 67);
    addnode( &que, 78);
    addnode( &que, 89);
    addnode( &que, 89);
    addnode( &que, 89);
    addnode( &que, 89);
    addnode( &que, 89);
    addnode( &que, 89);
    addnode( &que, 89);
    addnode( &que, 89);
    addnode( &que, 22);
    addnode( &que, 22);
    addnode( &que, 23);
    addnode( &que, 23);
    addnode( &que, 78);
    addnode( &que, 78);

    printllist(que);

    cout << endl;

    reversellist(&que);

    printllist(que);

    cout << endl;

    delDuplicate(&que);

    printllist(que);


    return 0;
}
