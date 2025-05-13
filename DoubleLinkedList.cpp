#include <iostream>
using namespace std;

// membuat struktur untuk object double linkedlist
struct Node
{
     // deklarasi noMhs dan name untuk menampung data
    int noMhs;
    string name;
      // deklarasi pointer next dan pref untuk penunjukkan data sebelum dan sesudah
    Node *next;
    Node *prev;

};

// deklarasi pointer START dan pemberian nilai
Node*START=NULL;

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
            cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
            return;
        }
        

    }

}    