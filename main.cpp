#include <iostream>
#include <string>
#include <c
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
    
    bool isempty(){
        return head == nullptr;
    }

    void InputStudent(){
        Student a;
        cout << "Nhap ID:";
        cin >> a.id;
        cin.ignore();
        cout << "Nhap ten sinh vien :";
        getline(cin, a.name);
        cout << "Nhap gpa(chua co nhap 0.0): ";
        cin >> a.gpa;
        AddStudent(a);
    }

    void OutputStudent(){
        Node *curr = head;
        while (curr != nullptr){
            cout << curr->Data.id << " " << curr->Data.name << " " << curr->Data.gpa << endl; 
            curr = curr->next;
        }
    }
    ~DanhSachQuanLy(){
        while (head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main(){
    DanhSachQuanLy st;
    int option;
    do{
        cout << "\n============= Menu Quan Ly =============" << endl;
        cout << "0. Thoat he thong."<< endl;
        cout << "1. Them Sinh Vien." << endl;
        cout << "2. Hien thi danh sach." << endl;
        switch (option){
            case 1:
                st.InputStudent();
                break;
            case 2:
                st.OutputStudent();
                break;
            case 0:
                cout << "Dang thoat ..."<< endl;
                break;
            default :
                cout << "Lua chon khong hop le!!!" << endl;
                break;
        }
    } while (option != 0) ;
    return 0;
}