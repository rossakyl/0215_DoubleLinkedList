#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedlist
struct Node
{
    // deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
    // deklarasi pointer next dan prev untuk petunjuk ke data sebelum dan sesudahnya
    Node *next;
    Node *prev;
};

// deklarasi pointer START dan pemberian nilai
Node *START = NULL;

// deklarasi prosedur addNode
void addNode()
{
    // pembuatan node dan pemberian value untuk data noMhs dan name
    Node *newNode = new Node(); // step 1 Buat node baru
    cout << "\nEnter the roll number of the student: ";
    cin >> newNode->noMhs; // assign value to theh data field of the new node
    cout << "\nEnter the name of the student: ";
    cin >> newNode->name; // assign value to theh data field of the new node

    // insert the new Node in the list
    // kondisi jika star == null atau noMhs node baru <= noMhs start
    if (START == NULL || newNode->noMhs <= START->noMhs)
    {
        // step 2: insert the new node at the beginning
        // kondisi jika star tidak kosong dan noMhs node baru sama dengan noMhs start
        if (START != NULL && newNode->noMhs == START->noMhs)
        {
            cout << "\033[31mDuplicate roll number not allowed\033[0m" << endl;
            return;
        }
        // if the list is empty, make the new node the START
        // jika list kosong, maka node next nya adalah START
        newNode->next = START; // step 3: make the new node point to first node
        // kondisi jika start tidak memiliki nilai atau tidak kosong
        if (START != NULL)
        {
            START->prev = newNode; // step 4: make the first node point to the new node
        }
        // memberi nilai prev = null dan start = node baru
        newNode->prev = NULL; // step 5: make the new node point to null
        START = newNode;      // step 6: make the new node the first node
    }
    // kondisi jika semua kondisi if tidak terpenuhi
    else
    {
        // insert the new node in the middle or at the end
        // set nilai current = start dan nilai previous = null
        Node *current = START; // step 1.a: start from the first node
        Node *previous = NULL; // step 1.b: previous node is null initially

        // looping selama current != null dan noMhs dari current lebih kecil dari noMhs node baru
        while (current != NULL && current->noMhs < newNode->noMhs)
        {                            // step 1.c: traverse the list to find the correct position
            previous = current;      // step 1.d: move the previous to the current node
            current = current->next; // step 1.e: move the current to the next node
        }

        // set nilai next node baru = current dan prev node baru = previous
        newNode->next = current;  // step 4: make the next field of the new node point to the current node
        newNode->prev = previous; // step 5: make the previous field of the new node point to the previous node

        // kondisi jika current tidak sama dengan null
        if (current != NULL)
        {
            current->prev = newNode; // step 6: make the previous field of the current node point to the new node
        }

        // kondisi jika previous tidak sama dengan null
        if (previous != NULL)
        {
            previous->next = newNode; // step 7: make the next field of the previous node point to the new node
        }
        // kondisi jika if previous sama dengan null
        else
        {
            // if previous is still null, it means newNode is now the first node
            START = newNode;
        }
    }
}

// pembuatan function search umtuk mencari data
bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while (*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}


 
        
