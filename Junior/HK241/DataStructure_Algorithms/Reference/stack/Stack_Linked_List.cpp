

#include "main.h"

template <typename T> 
class Stack_Linked_List
{
private:
    class Node;
private:
    Node* head;
    int Size;
public:
    Stack_Linked_List(/* args */);
    ~Stack_Linked_List();

    bool empty();
    int size();
    T top();
    void push(T );
    void pop();

private:
    class Node{
    public:
        T data;
        Node* next;
        Node(T data, Node* next):data(data), next(next){}
    };
};


//^ O(1)
template <typename T> 
Stack_Linked_List<T>::Stack_Linked_List(/* args */):Size(0), head(nullptr)
{
}

//* xóa tất cả các phần tử Node đang còn trong Singly_Linked_List
//* hàm này tương đương với clear nhưng chỉ gọi ghi kết thúc phạm vi
//* có thể dùng hàm remove để xử lý
//^ độ phức tạp O(n)
template <typename T> 
Stack_Linked_List<T>::~Stack_Linked_List()
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
    head = nullptr;
    Size = 0;
}

//! xem thử stack có rỗng không
//^ O(1)
template <typename T> 
bool Stack_Linked_List<T>::empty(){
    return (Size == 0);
}

//! số lương phần tử trong stack
//^ O(1)
template <typename T> 
int Stack_Linked_List<T>::size(){
    return Size;
}

//! get phần tử đầu trong stack
//^ O(1)
template <typename T> 
T Stack_Linked_List<T>::top(){
    if(this->empty()) throw("Empty");   //~ không có sao lấy
    return head->data;
}


//! thêm một phần tử vào đầu stack không bao giờ full
//! chèn ở đầu linked list
//^ O(1)
template <typename T> 
void Stack_Linked_List<T>::push(T data){
    head = new  Stack_Linked_List<T>::Node(data, head);
    Size ++;
}

//! xóa phần tử đầu tiên tay đổi size
//! xóa ở đầu linked list
//^ O(1)
template <typename T> 
void Stack_Linked_List<T>::pop(){
    if(this->empty()) throw("Empty");    //~ không có sao xóa
    Stack_Linked_List<T>::Node* temp = head;
    head = head->next;
    delete temp;
    Size --;
}


int main(int argc, char ** argv) {

    cout << "Check Link List\n";
    Stack_Linked_List<int> stack_array;
    stack_array.push(1);
    stack_array.push(2);
    stack_array.push(3);
    cout << "empty : " << (stack_array.empty() ? "true" : "false") << '\n';
    cout << "top : " << stack_array.top() << '\n';
    cout << "size : " << stack_array.size() << '\n';
    stack_array.push(4);
    stack_array.pop();
    stack_array.pop();
    cout << "top : " << stack_array.top() << '\n';
    cout << "size : " << stack_array.size() << '\n';
    stack_array.pop();
    stack_array.pop();
   cout << "empty : " << (stack_array.empty() ? "true" : "false") << '\n';

    return 0;
}