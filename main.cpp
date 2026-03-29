#include <iostream>
#include <string>
using namespace std;

struct Student{
    string id;
    string name;
    float gpa;
};

struct Node{
    Student Data;
    Node* next;
};

class DanhSachQuanLy{
private:
    Node* head;

public:
    DanhSachQuanLy(){head = nullptr;}

    // Void to add the new student
    void AddStudent(Student st){
        Node* newNode = new Node();
        newNode->Data = st;
        newNode->next = head;
        head = newNode;
    }  

    bool DeleteStudent( string id){
        if (head == nullptr) return false; // In case the empty list
        // In case the node needs to be delete at the head
        if (head->Data.id == id){
            Node *tmp = head;
            head = head->next;
            delete tmp; // release memory
            return true;
        }
        // In case the node needs to be delete at middle or the end
        Node* curr = head;
        Node* prev = nullptr;
        while ( curr != nullptr && curr->Data.id != id){
            prev = curr;
            curr = curr->next;
        }
        // Not found the node that needs to be delete
        if (curr == nullptr) return false;
        // Found the node to be delete
        prev->next = curr->next;
        delete curr;
        return true;
    }

    // Function to find a student
    bool FindStudent( string id ){
        if (head == nullptr) return false;// Empty list

        Node* curr = head;
        // founding
        while ( curr != nullptr && curr->Data.id != id){
            curr = curr->next;
        }

        if (curr == nullptr) return false;// Not found
        return true;// Founded
    }
};

int main(){

    return 0;
}