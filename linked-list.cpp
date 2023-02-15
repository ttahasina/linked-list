#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node *next;
};

void inputList(int sizeOfList, Node* addressOfStart)
{
    Node* current = addressOfStart;
    for (int i = 0; i < sizeOfList; i++)
    {
        string inp;
        cin >> inp;
        current->data = inp;
        if (i == sizeOfList - 1) // for last input
        {
            continue;
        }
        current->next = new Node();
        current = current->next;
    }
}

void displayList(Node* addressOfStart)
{
    Node* current = addressOfStart;
    while (current != nullptr)
    {
        cout << current->data << ", ";
        current = current->next;
    }
    cout << endl;
}

Node* insertInPosition(Node* addressOfStart, int position, string data)
{
    if (position == 1)
    {
        Node* newStartNode = new Node();
        newStartNode->data = data;
        newStartNode->next = addressOfStart;
        return newStartNode;
    }

    int currentPosition = 1;
    Node* current = addressOfStart;
    while (current != nullptr)
    {
        currentPosition++;
        if (currentPosition == position)
        {
            Node* newNode = new Node();
            newNode->data = data;

            Node* nextNode = current->next;

            current->next = newNode;
            newNode->next = nextNode;

            break;
        }
        current = current->next;
    }
    return addressOfStart;
}

Node* deleteFromPosition(Node* addressOfStart, int position)
{
    if (position == 1)
    {
        return addressOfStart->next;
    }

    int currentPosition = 1;
    Node* current = addressOfStart;
    while (current != nullptr)
    {
        currentPosition++;
        if (currentPosition == position)
        {
            Node* nextNode = current->next;
            current->next = nextNode->next;
            break;
        }
        current = current->next;
    }
    return addressOfStart;
}

int main()
{
    int sizeOfList;
    cout << "Enter the size of the list: ";
    cin >> sizeOfList;

    cout << "Enter the list" << endl;

    Node *start = new Node();

    inputList(sizeOfList, start);

    displayList(start);

    cout << "Enter the position to add: ";
    int pos;
    cin >> pos;
    cout << "Enter the data to add: ";
    string data;
    cin >> data;
    start = insertInPosition(start, pos, data);

    displayList(start);

    cout << "Enter a position to delete: ";
    cin >> pos;
    start = deleteFromPosition(start, pos);

    displayList(start);
}
