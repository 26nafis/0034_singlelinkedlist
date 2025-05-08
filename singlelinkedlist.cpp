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
}