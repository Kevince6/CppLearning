#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int val) : data(val), next(nullptr) {} // C++中，结构体可以进行初始化。C中空指针写作nullptr.
};

class Linklist
{
private:
    Node *head;

public:
    Linklist() : head(nullptr) {} // 要习惯C++风格的初始化。

    void InsertFront(int val)
    {
        Node *newNode = new Node(val); // C++风格的指针写法。
        newNode->next = head;
        head = newNode;
    }

    void InsertTail(int val)
    {
        Node *temp = head;
        if (temp == nullptr)
            head = new Node(val);
        else
        {
            while (temp->next)
                temp = temp->next;
            temp->next = new Node(val);
        }
    }

    void DeleteNode(int val)
    {
        if (!head)
            return;
        if (head->data == val)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;
        if (temp->next)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    Node *search(int val)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    ~Linklist()
    {
        Node *temp = head;
        while (temp)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main()
{
    Linklist p;
    p.InsertFront(1);
    p.InsertFront(2);
    p.InsertFront(3);
    p.print();
    cout << p.search(2)->next->data << endl;
    p.DeleteNode(2);
    p.InsertTail(4);
    p.InsertTail(5);
    p.print();
    return 0;
}