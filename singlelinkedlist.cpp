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
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;
        Node *nodebaru = new Node;
        nodebaru->noMhs = nim;
        nodebaru->next = NULL;

        if (START == NULL || nim < START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplikasi nomor tidak diijinkan\n";
                return;
            }
            nodebaru->next = START;
            START = nodebaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while (current != NULL && nim > current->noMhs)
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi nomor tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }
        nodebaru->next = previous->next;
        previous->next = nodebaru;
    }

}