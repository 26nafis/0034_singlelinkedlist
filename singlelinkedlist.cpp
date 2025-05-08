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

    void deleteNode()
    {
        int nim;
        cout << "\nMasukkan nomor mahasiswa yang akan dihapus: ";
        cin >> nim;
        Node *previous, *current;
        if (!Search(nim, &previous, &current))
        {
            cout << "\nMahasiswa dengan nomor " << nim << " tidak ditemukan\n";
            return;
        }
        if (previous == current)
        {
            START = START->next;
        }
        else
        {
            previous->next = current->next;
        }
        delete current;
        cout << "\nMahasiswa dengan nomor " << nim << " berhasil dihapus\n";
    }
};

int main()
{
    LinkedList mhs;
    int ch;
    do
    {
        cout << "\nMenu";
        cout << "\n1. Tambah data";
        cout << "\n2. Hapus data";
        cout << "\n3. Tampilkan data";
        cout << "\n4. Cari data";
        cout << "\n5. Keluar";
        cout << "\nPilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            mhs.addNode();
            break;
        case 2:
            if (mhs.ListEmpty())
            {
                cout << "\nList Kosong\n";
                break;
            }
            mhs.deleteNode();
            break;
        case 3:
            mhs.traversal();
            break;
        case 4:
            if (mhs.ListEmpty())
            {
                cout << "\nList Kosong\n";
                break;
            }
            Node *previous, *current;
            int nim;
            cout << "\nMasukkan nomor mahasiswa yang akan dicari: ";
            cin >> nim;
            if (mhs.Search(nim, &previous, &current))
                cout << "\nMahasiswa dengan nomor " << nim << " ditemukan\n";
            else
                cout << "\nMahasiswa dengan nomor " << nim << " tidak ditemukan\n";
            break;
        case 5:
            cout << "\nKeluar dari program\n";
            break;
        default:
            cout << "\nPilihan tidak valid\n";
            break;
        }
    } while (ch != 5);

    return 0;
}