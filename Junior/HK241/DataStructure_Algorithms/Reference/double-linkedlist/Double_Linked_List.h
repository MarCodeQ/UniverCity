 #ifndef __Double_Linked_List_H__
#define __Double_Linked_List_H__

#include "main.h"

class Double_Linked_List
{
public:
    class Node;
protected:
    Node* head, *tail;  //! Node đầu tiên và Node cuối cùng
    int size;           //! kích thước của 1 
public:
    //! khởi tạo
    Double_Linked_List();
    Double_Linked_List(const Double_Linked_List& others);
    ~Double_Linked_List();
    int Count();
    bool Empty();
    //! các hàm chỉnh sửa dữ liệu
    void Insertion(int data, int index);
    void Deletion(int index);

    //! cách hàm lấy dữ liệu
    int Get(int index);
    int IndexOf(int data);
    bool Contains ( int data );

    //! các hàm sort tăng dần nha
    void SelecetionSort();
    //void MergerSort(); //~ hàm này qua lý thuyết sort sẽ có

    //! các hàm hay dùng
    Double_Linked_List Concat(const Double_Linked_List& others);
    Double_Linked_List SubDouble_Linked_List(int from, int to);
    void Reverse();

    //! hàm dislay cấu trúc [Size=2,DataHead=1,DataTail=2,DataNode : 1->2->nullptr]
    string Dislay();

    //! các hàm làm thêm bài tập
public:
    class Node{
    public:
        int data;   //! dữ liệu
        Node* next; //! trỏ tới node tiếp theo (phía sau)
        Node* prev; //! con trỏ phái trước
    public:
        Node(int data = 0, Node* next = nullptr, Node* prev = nullptr)
        :data(data), next(next), prev(prev){}
    };
};




#endif // __Double_Linked_List_H__