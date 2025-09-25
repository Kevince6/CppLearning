#include <iostream>
#include <vector>
#include <memory> //引入智能指针来管理链表
using namespace std;

struct Node
{
    int data;
    unique_ptr<Node> next;
    Node(int val) : data(val), next(nullptr) {} // C++中，结构体可以进行初始化,也可以析构。C中空指针写作nullptr.
};

class Linklist
{
private:
    unique_ptr<Node> head;

public:
    Linklist() : head(nullptr) {} // 要习惯C++风格的初始化。

    void InsertFront(int val)
    {
        unique_ptr<Node> newNode = make_unique<Node>(val); // C++风格的指针写法。
        newNode->next = move(head);
        head = move(newNode);
    }

    void InsertTail(int val)
    {
        auto NewNode = make_unique<Node>(val);
        if (head == nullptr)
            head = move(NewNode);
        else
        {
            Node *temp = head.get(); // 用.get方法去获得裸指针
            while (temp->next)
                temp = temp->next.get();
            temp->next = move(NewNode);
        }
    }

    void DeleteNode(int val)
    {
        if (!head)
            return;
        if (head->data == val)
        {
            head = move(head->next);
            return;
        }
        Node *temp = head.get();
        while (temp->next && temp->next->data != val)
            temp = temp->next.get();
        if (temp->next)
        {
            temp->next = move(temp->next->next);
        }
    }

    Node *search(int val)
    {
        Node *temp = head.get();
        while (temp)
        {
            if (temp->data == val)
                return temp;
            temp = temp->next.get();
        }
        return nullptr;
    }

    void print()
    {
        Node *temp = head.get();
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next.get();
        }
        cout << "NULL" << endl;
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