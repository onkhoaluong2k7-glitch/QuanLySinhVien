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
};

int main(){

    return 0;
}