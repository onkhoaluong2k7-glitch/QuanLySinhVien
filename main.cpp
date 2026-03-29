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
    
    void AddStudent(Student st){
        Node* newNode = new Node();
        newNode->Data = st;
        newNode->next = head;
        head = newNode;
    }

};

int main(){

    return 0;
}