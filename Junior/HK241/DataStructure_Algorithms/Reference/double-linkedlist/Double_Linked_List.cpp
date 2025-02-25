#include "Double_Linked_List.h"


//* tùy vào tham số truyền vào mà ta có thể có nhiều contructor
//* Thông thường thì chỉ cần rỗng và tham số truyền vào chính nó
//^ độ phức tạp O(1)
Double_Linked_List::Double_Linked_List()
:head(nullptr), tail(nullptr), size(0){

};

//* so chép tất cả các dữ liệu other sang this
//* luôn khởi tạo head tail và size trước khi xử lí
//^ độ phức tạp O(n)
Double_Linked_List::Double_Linked_List(const Double_Linked_List& others)
:head(nullptr), tail(nullptr), size(0){
    Node* temp = others.head;
    for(int i = 0; i < others.size; i++)
    {
        this->Insertion(temp->data, i); //! chèn tại cuối
        temp = temp->next;  //! dịch ptr temp
    }
}

//* số lượng node có trong Double_Linked_List
//^ độ phức tạp O(1)
int Double_Linked_List::Count(){
    return size;
}

//* Double_Linked_List có rỗng không
//^ độ phức tạp O(1)
bool Double_Linked_List::Empty(){
    return size == 0;
}

//* xóa tất cả các phần tử Node đang còn trong Double_Linked_List
//* hàm này tương đương với clear nhưng chỉ gọi ghi kết thúc phạm vi
//* có thể dùng hàm remove để xử lý
//^ độ phức tạp O(n)
Double_Linked_List::~Double_Linked_List(){
    Node* temp; //~ node mẫu
    //! có thể dùng hàm Deletion như phần contructor phía trên
    while(size != 0){
        //! dịch ptr head trước khi xóa không sẽ bị lỗi Dangling pointer
        temp = head;
        head = head->next;
        delete temp;
        size --;
    }
    //! xóa hết rồi gán lại ban đầu thôi có thể có hay không thì cũng được 
    //! nhưng hàm clear thì phải có
    head = tail = nullptr;
    size = 0;
}

//* insert có 5 TH: index ngoài phạm vi, danh sách rỗng, chèn đầu, chèn cuối, chèn mid
//* cuối and mid có thể chung nhau
//* đầu và rỗng có thể chung nhau
//* data : dữ liệu cần chèn, index là vị trí (vị trí đầu tiên 0, cuối cùng là size)
//^ độ phức tạp O(n)
void Double_Linked_List::Insertion(int data,int index){

    //! trường hợp index nằm ngoại phạm vi
    if(index < 0 || index > this->size) out_of_range("Index of Linked List is invalid!");
    
    Node* newNode = new Node(data);
    //! Double_Linked_List đang rỗng (empty)
    //^ độ phức tạp O(1)
    if(this->size == 0){
        head = tail = newNode;
    }

    //! Insert ở đầu danh sách (head)
    //^ độ phức tạp O(1)
    else if(index == 0){
        newNode->next = head;  
        head->prev = newNode;
        head = newNode;
    }

    //! Insert ở cuối danh sách (tail)
    //^ độ phức tạp O(1)
    else if(index == this->size){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    //! Insert ở giữa danh sách (mid) - các trường hợp còn lại
    //^ độ phức tạp O(N)
    else{
        Node* temp = head;
        //! tìm kiếm node thứ index - 1 (node trước newNode cần insert)
        for(int i = 1 ; i < index; i++) temp = temp->next;
        //! newNode trỏ đến node index
        newNode->next = temp->next;
        //! node index - 1 trỏ đến NewNode
        temp->next = newNode;
        //! NewNode prev trỏ node index - 1;
        newNode->prev = temp;
        //! index prev trỏ NewNode
        newNode->next->prev = newNode;
    }
    this->size ++;  //! tăng số lượng node
}

//* Deletion có 5 TH: index ngoài phạm vi, danh sách còn 1 node, chèn đầu, chèn cuối, chèn mid
//* cuối and mid gộp chung
//^ độ phức tạp O(n)
void Double_Linked_List::Deletion(int index){
    
    //! trường hợp index nằm ngoại phạm vi
    if(index < 0 || index >= this->size) out_of_range("Index of Linked List is invalid!");

    Node* deleteNode; // lưu node cần xóa

    //! Double_Linked_List đang có 1 phần tử
    //^ độ phức tạp O(1)
    if(this->size == 1){
        deleteNode = head;
        head = tail = nullptr;
    }
    //! Delete ở đầu danh sách (head)
    //^ độ phức tạp O(1)
    else if(index == 0){
        deleteNode = head;
        head = head->next;
        head->prev = nullptr;
    }
    //! Delete ở cuối danh sách (tail) or Delete ở giữa danh sách (mid) - các trường hợp còn lại
    //^ độ phức tạp O(n)
    else{
        Node* temp = head;
        //! tìm kiếm node thứ index - 1 (node trước newNode cần insert)
        for(int i = 1 ; i < index; i++) temp = temp->next;
        //! deleteNode node cần xóa index
        deleteNode = temp->next;
        //! node index - 1 trỏ đến index + 1;
        temp->next = deleteNode->next;
        //! trường hợp node cuối cùng xóa đi tail -> cập nhật tail lên node trước node Index - 1
        if(index == this->size - 1) tail = temp;
        //! xét thử node index có nullptr không rồi xét node index + 1 prev trỏ node index - 1
        else temp->next->prev = temp;
    }
    delete deleteNode;
    this->size --; //! giảm số lượng node

}


//^ độ phức tạp O(n)
int Double_Linked_List::Get(int index){
    //! trường hợp index nằm ngoại phạm vi
    if(index < 0 || index >= this->size) out_of_range("Index of Linked List is invalid!");

    Node* temp;
    //! duyệt từ node head -> node size / 2 theo chiều xuôi
    if(index <= size / 2){
        temp = head;
        //! Get node thứ index (node cần tìm)
        for(int i = 0 ; i < index; i++) temp = temp->next;   
    }
    //! duyệt từ node tail -> node size / 2 theo chiều ngược
     else{
        //! Get node thứ index (node cần tìm)
        temp = tail;
        for(int i = 0 ; i < size - index; i++) temp = temp->prev;           
    }  
    return temp->data;   
}

//^ độ phức tạp O(n)
int Double_Linked_List::IndexOf(int data){
    Node* temp = head;
    //! IndexOf node đầu tiên có data = với data truyền vào
    for(int i = 0 ; i < this->size; i++){
        if(temp->data == data){
            return i;
        }
        temp = temp->next;   
    }  
    //! không tìm thấy vị trí
    return -1;   
}

//^ độ phức tạp O(n)
bool Double_Linked_List::Contains ( int data ){
    Node* temp = head;
    //! Contains tìm kiếm thử data có nằm trong link list hay không
    for(int i = 0 ; i < this->size; i++){
        if(temp->data == data){
            return true;
        }
        temp = temp->next;   
    }  
    //! không tìm thấy vị trí
    return false;   
}

//* hàm này có 2 cách là swap data và swap Node
//* phần này dùng swap data còn swap node tự làm nha khá là khoai
//^ độ phức tạp O(n^2)
void Double_Linked_List::SelecetionSort(){
    Node* node_I = head;
    while(node_I != nullptr){
        Node* node_J = node_I->next;
        while(node_J != nullptr){
            if(node_I->data > node_J->data) swap(node_I->data, node_J->data);
            node_J = node_J->next;
        }
        node_I = node_I->next;
    }
}

//* hàm này sẽ tạo ra 2 Double_Linked_List mới từ this và other và hợp chúng lại
//^ độ phức tạp O(max(size this, size other))
Double_Linked_List Double_Linked_List::Concat(const Double_Linked_List& others){
    Double_Linked_List h1(*this);
    Double_Linked_List h2(others);

    // nếu size this khác không
    if(h1.size != 0){
        h1.tail->next = h2.head;
        h2.head->prev = h1.tail;
    }
    else h1 = h2;
    return Double_Linked_List(h1);
}

//* Deletion có 3 TH: lỗi range, lỗi logic, cắt
//^ độ phức tạp O(n)
Double_Linked_List Double_Linked_List::SubDouble_Linked_List(int from, int to){
    if(from < 0 || from >= size || to <= 0 || to > size) out_of_range("Index of Link List is invalid!");
    else if(from >= to) logic_error("Invalid range");

    Double_Linked_List result;
    Node* temp = head;
    //! tìm đến vị trí cần cắt
    for(int i = 0 ; i < from; i++){
        temp = temp->next;
    }

    for(int i = from; i < to; i++){
        result.Insertion(temp->data, i - from); // insert tail
        temp = temp->next;
    }
    return Double_Linked_List(result);
}


//^ độ phức tạp O(n)
void Double_Linked_List::Reverse(){
    if(this->size <= 1) return;
    //! curr là con trỏ hiện tại, pre là con trỏ phía trước
    Node* curr = this->head;
    Node* pre = this->head->next;
    for(int i = 0; i < this->size - 1; i++){
       
        //! lưu lại node i + 2
        Node* temp = pre->next;
        //! next trỏ node i + 1 tới node i
        //! prev node i tới node i + 1
        pre->next = curr;
        curr->prev = pre;
        //! gán curr thành node i + 1 và pre thành node i + 2 (tăng lên)
        curr = pre;
        pre = temp;
        
    }
    //! cập nhật lại node đầu thành node cuối
    this->head->next = nullptr;
    this->tail = this->head;
    //! cập nhật node cuối thành node đầu
    curr->prev = nullptr;
    this->head = curr; //! node cuối đang là curr
}



//^ độ phức tạp O(n)
string Double_Linked_List::Dislay(){
    string result = "[Size=" + to_string(size)
                    + ",DataHead=" + (head ? to_string(head->data) : "nullptr")
                    + ",DataTail=" + (tail ? to_string(tail->data) : "nullptr")
                    + ",DataNode: ";
    if(this->size == 0) return result + "nullptr]";
    Node* temp = head;
    result += "\n           next: ";
    for(int i = 0 ; i < this->size; i++){
        result += to_string(temp->data) + "->";
        temp = temp->next;  
        if(i == this->size - 1) result += "nullptr"; 
    }  
    result += "\n           prev: ";
    temp = tail;
    for(int i = 0 ; i < this->size; i++){
        result += to_string(temp->data) + "->";
        temp = temp->prev;  
        if(i == this->size - 1) result += "nullptr]"; 
    }  
    return result;
}