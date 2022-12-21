
#include <iostream>
#include <cstring>
using namespace std;

struct List {
    string name;
    string pos;
    List *next;
};

void createList(List *&Head) {
    List *P, *Last = NULL;
    char ch = 'y';
    while (ch == 'Y' || ch == 'y') {
        P = new List;
        cout << "Piece: "; cin >> P->name;
        cout << "Position: "; cin >> P->pos;
        P->next = NULL;
        if (Head == NULL) Head = P;
        else Last->next = P;
        Last = P;
        cout << "Add new piece (y/n): "; cin >> ch;
    }
}

void printList(List *P) {
    int i=0;
    while(P) {
        cout << ++i << ". " << P->name << " on " << P->pos << endl;
        P = P->next;
    }
}

void changePosition(string pos, string name, List *&Head) {
    List* P = Head;
    List* Pprev = NULL;
    if(P != NULL && pos.compare(P->pos) == 0) {
        Head = P->next;
        delete P; 
        return;
    } else {
    while(P != NULL && pos.compare(P->pos) != 0) {
        if(name.compare(P->name) == 0) P->pos = pos;
        Pprev = P;
        P = P->next;
    }
    if(P == NULL) return;
    Pprev->next = P->next;
    delete P;
    }
}

int main () {
    List *Head = NULL;
    createList(Head);
    cout << endl << endl;
    printList(Head);
    cout << endl << endl;
    changePosition("h1", "king", Head);
    printList(Head);
    
    return 0;
}
