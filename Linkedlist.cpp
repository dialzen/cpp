#include <iostream>
#include <string>
using namespace std;


struct Node {
    int value;
    Node *next;
};

class List {
    
    private:
        Node *head;
        Node *tail;
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

    void add_fr(int val){
        
        Node* temp = new Node;
        temp->value = val;
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }

    }

    void display() {
        Node* temp = new Node;
        temp = head;
        while (temp!=NULL) {
            cout<<temp->value<<" ";
            temp = temp->next;
        }
    }

    int pop() {
        Node* temp = new Node;
        temp = head->next;
        head = temp;
    }

    void validate(string s){
        for (auto i : s)
            cout<<i<<" ";
    } 

};


int main() {
    
    List list1;
    list1.add_last(10);
    list1.add_last(5);
    list1.add_fr(3);
    list1.add_fr(3);
    list1.pop();
    list1.display();
    list1.validate("Hoo");
    return 0;
}
