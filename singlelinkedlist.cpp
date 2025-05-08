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

    bool ListEmpty()
    {
        return START == NULL;
    }

    bool Search(int nim, Node **previous, Node **current)
    {
        *previous = START;
        *current = START;
        while (*current != NULL && nim != (*current)->noMhs)
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return (*current != NULL);
    }

    void traversal()
    {
        if (ListEmpty())
            cout << "\nList Kosong\n";
        else
        {
            cout << "\nList dalam list adalah:\n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }

}