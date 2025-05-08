
#include <iostream>
#include <string.h>
using namespace std;

class Node 
{
    public:
    int noMhs;
    Node *next;
};
class LinkedList
{
    Node *START;
    public:
    LinkedList()
    {
        START = NULL;
    }
    void addNode()
    {
        int nim;
        cout << "\nMasukan Nomer Mahasiswa: ";
        cin >> nim;
        Node *nodebaru = new Node;
        nodebaru->next = NULL;
    }
};