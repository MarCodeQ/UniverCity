

#include "main.h"

template <typename T> 
class Queue_Linked_List
{
public:
    class Node;
private:
    Node* head, *tail;
    int Size;

public:
    Queue_Linked_List(/* args */);
    ~Queue_Linked_List();

    bool empty();
    int size();
    T peek();
    void Enqueue(T );
    void Dequeue();

public:
    class Node{
    public:
        T data;
        Node* next;
        Node(T data, Node* next):data(data), next(next){}
    };
};


//^ O(1)
template <typename T>
Queue_Linked_List<T>::Queue_Linked_List(/* args */):Size(0), head(nullptr), tail(nullptr)
{

}

//* xóa tất cả các phần tử Node đang còn trong Singly_Linked_List
//* hàm này tương đương với clear nhưng chỉ gọi ghi kết thúc phạm vi
//* có thể dùng hàm remove để xử lý
//^ độ phức tạp O(n)
template <typename T>
Queue_Linked_List<T>::~Queue_Linked_List()
{
    Node* temp; //~ node mẫu
    //! có thể dùng hàm Deletion như phần contructor phía trên
    while(Size != 0){
        //! dịch ptr head trước khi xóa không sẽ bị lỗi Dangling pointer
        temp = head;
        head = head->next;
        delete temp;
        Size --;
    }
    //! xóa hết rồi gán lại ban đầu thôi có thể có hay không thì cũng được 
    //! nhưng hàm clear thì phải có
    head = tail = nullptr;
    Size = 0;
}

//! xem thử stack có rỗng không
//^ O(1)
template <typename T>
bool Queue_Linked_List<T>::empty(){
    return (Size == 0);
}

//! số lương phần tử trong stack
//^ O(1)
template <typename T>
int Queue_Linked_List<T>::size(){
    return Size;
}

//! get phần tử đầu trong stack
//^ O(1)
template <typename T>
T Queue_Linked_List<T>::peek(){
    if(this->empty()) throw("Empty");   //~ không có sao lấy
    return head->data;
}


//! chèn ở cuối linked list
//^ O(1)
template <typename T>
void Queue_Linked_List<T>::Enqueue(T data){
    if(this->Size == 0){
        head = tail = new Node(data, nullptr);
    }
    else{
        tail->next = new Node(data, nullptr);
        tail = tail->next;
    }
    this->Size ++;
}

//! xóa ở đầu linked list
//^ O(1)
template <typename T>
void Queue_Linked_List<T>::Dequeue(){
    if(this->empty()) throw("Empty");    //~ không có sao xóa
    Node* temp = head;
    head = head->next;
    delete temp;
    this->Size --;
}


int main(int argc, char ** argv) {

    cout << "Check ARRAY\n";
    Queue_Linked_List<int> queue_Linked_List;
    queue_Linked_List.Enqueue(1);
    queue_Linked_List.Enqueue(2);
    queue_Linked_List.Enqueue(3);
    cout << "empty : " << (queue_Linked_List.empty() ? "true" : "false") << '\n';
    cout << "peek : " << queue_Linked_List.peek() << '\n';
    cout << "size : " << queue_Linked_List.size() << '\n';
    queue_Linked_List.Enqueue(4);
    queue_Linked_List.Dequeue();
    queue_Linked_List.Dequeue();
    cout << "peek : " << queue_Linked_List.peek() << '\n';
    cout << "size : " << queue_Linked_List.size() << '\n';
    queue_Linked_List.Dequeue();
    queue_Linked_List.Dequeue();
   cout << "empty : " << (queue_Linked_List.empty() ? "true" : "false") << '\n';

    return 0;
}