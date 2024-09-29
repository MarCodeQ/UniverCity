

#include "main.h"

template <typename T> 
class Queue_Array
{
private:
    T* array;
    int Size;
    int index;
    const int MAXSIZE;
public:
    Queue_Array(/* args */);
    ~Queue_Array();

    bool empty();
    int size();
    T top();
    void Enqueue(T );
    void Dequeue();
};

//! tùy vào tham số truyền vào mà maxsize thay đổi
//! cấp phát mảng
//^ O(1)
template <typename T> 
Queue_Array<T>::Queue_Array(/* args */):MAXSIZE(1000), Size(0), index(0)
{
    //! tạo ra không gian để sử dụng và khởi tạo tất cả các giá trị stack 0
    array = new int[MAXSIZE]{0};
}

//! thu hồi cấp phát động
//^ O(1)
template <typename T> 
Queue_Array<T>::~Queue_Array()
{
    delete[] array;
    Size = 0;
}

//! xem thử stack có rỗng không
//^ O(1)
template <typename T> 
bool Queue_Array<T>::empty(){
    return (Size == 0);
}

//! số lương phần tử trong stack
//^ O(1)
template <typename T> 
int Queue_Array<T>::size(){
    return Size;
}

//! get phần tử đầu trong stack 
//^ O(1)
template <typename T> 
T Queue_Array<T>::top(){
    if(this->empty()) throw("Empty");   //~ không có sao lấy
    return array[index];
}


//! thêm một phần tử vào cuối stack
//^ O(1)
template <typename T> 
void Queue_Array<T>::Enqueue(T data){
    if(this->MAXSIZE == Size) throw("FULL");  //~ đầy rồi
    array[Size + index] = data;
    Size ++;
}

//! xóa phần tử đầu tiên tay đổi size
//^ O(1)
template <typename T> 
void Queue_Array<T>::Dequeue(){
    if(this->empty()) throw("Empty");    //~ không có sao xóa
    Size --;
    index = (index + 1) % MAXSIZE;
}


int main(int argc, char ** argv) {

    cout << "Check ARRAY\n";
    Queue_Array<int> queue_Array;
    queue_Array.Enqueue(1);
    queue_Array.Enqueue(2);
    queue_Array.Enqueue(3);
    cout << "empty : " << (queue_Array.empty() ? "true" : "false") << '\n';
    cout << "top : " << queue_Array.top() << '\n';
    cout << "size : " << queue_Array.size() << '\n';
    queue_Array.Enqueue(4);
    queue_Array.Dequeue();
    queue_Array.Dequeue();
    cout << "top : " << queue_Array.top() << '\n';
    cout << "size : " << queue_Array.size() << '\n';
    queue_Array.Dequeue();
    queue_Array.Dequeue();
   cout << "empty : " << (queue_Array.empty() ? "true" : "false") << '\n';

    return 0;
}