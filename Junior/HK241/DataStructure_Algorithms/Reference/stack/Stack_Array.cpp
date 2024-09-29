#include "main.h"

template <typename T> 
class Stack_Array
{
private:
    T* array;  //! ngăn xếp
    int Size;  //! kích thước hiện tại
    const int MAXSIZE; //! kích thước tối đa
public:
    Stack_Array(/* args */);
    ~Stack_Array();

    bool empty();
    int size();
    T top();
    void push(int );
    void pop();
};

//! tùy vào tham số truyền vào mà maxsize thay đổi
//! cấp phát mảng
//^ O(1)
template <typename T>
Stack_Array<T>::Stack_Array(/* args */):MAXSIZE(1000), Size(0)
{
    //! tạo ra không gian để sử dụng và khởi tạo tất cả các giá trị stack 0
    array = new int[MAXSIZE]{0};
}

//! thu hồi cấp phát động
//^ O(1)
template <typename T>
Stack_Array<T>::~Stack_Array()
{
    delete[] array;
    Size = 0;
}

//! xem thử stack có rỗng không
//^ O(1)
template <typename T>
bool Stack_Array<T>::empty(){
    return (Size == 0);
}

//! số lương phần tử trong stack
//^ O(1)
template <typename T>
int Stack_Array<T>::size(){
    return Size;
}

//! get phần tử đầu trong stack
//^ O(1)
template <typename T>
T Stack_Array<T>::top(){
    if(this->empty()) throw("Empty");   //~ không có sao lấy
    return array[Size - 1];
}


//! thêm một phần tử vào đầu stack
//^ O(1)
template <typename T>
void Stack_Array<T>::push(int data){
    if(this->MAXSIZE == Size) throw("FULL");  //~ đầy rồi
    array[Size++] = data;
}

//! xóa phần tử đầu tiên tay đổi size
//^ O(1)
template <typename T>
void Stack_Array<T>::pop(){
    if(this->empty()) throw("Empty");    //~ không có sao xóa
    Size --;    
}


int main(int argc, char ** argv) {

    cout << "Check ARRAY\n";
    Stack_Array<int> stack_array;
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