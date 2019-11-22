#include <iostream>
using napespace std;


struct Node {
    int val;
    Node *next;
}

class List {
    
    private:
        node *head;
        node *tail;
    public:
        List() {
            head = NULL;
            tail = NULL;
        }
    void add_last(int n) {
        

        Node* temp = new Node;
        temp->value = n;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }

    }

    void display() {
        Node* temp = new Node;
        temp = head;
        while (temp!=NULL) {
            cout<<temp->data;
            temp = temp->next;
        }
    }

}

int main() {
    
    List list1;
    list1.add_last(10);
    list1.add_last(5);
    return 0;

}