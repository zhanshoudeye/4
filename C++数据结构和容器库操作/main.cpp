#include <iostream>
//栈
template<typename T>
class stack {
    private:
    T* array;
    int size;
    int top_index;
    public:
    stack() :top_index(-1),size(0),array(nullptr){}
    //创建一个栈
    void init(int num)
    {
        array = new T[num];
        size = num;
    }
    //检查是否为空
    bool isEmpty() {
        return top_index == -1;
    }
    //独取栈顶元素
    T top()
    {
        if(isEmpty()){std::cout<<"stack is empty"<<std::endl;return T();}
        return array[top_index];
    }
    //清除全部内容
    void clear()
    {
        top_index = -1;
    }
    //从栈顶弹出元素
    void pop()
    {
        if(isEmpty()){std::cout<<"stack is empty"<<std::endl;}
        else{top_index--;}
    }
    //从栈顶增加元素
    void push(T value)
    {
        if(top_index>=size-1){std::cout<<"stack is full"<<std::endl;}
        else{
            top_index++;
            array[top_index] = value;
        }
    }
    ~stack(){delete[]array;}
};
//队列
template<typename T>
class queue {
    private:
    T* array;
    int top_index;
    int tail_index;
    int size;
    public:
    queue():top_index(0),tail_index(-1),array(nullptr),size(0){}
    //创建一个队列
    void init(int num) {
        array = new T[num];
        size = num;
    }
    //判断是否为空
    bool isEmpty() {
        return top_index == tail_index+1;
    }
    //访问队头元素
    T front() {
        if(isEmpty()){return T();}
        else{return array[top_index];}
    }
    //入队
    void push(T value) {
        if (tail_index>=size-1){std::cout << "queue is full" << std::endl;}
        else {
            array[tail_index] = value;
            tail_index++;
        }
    }
    //出队
    void pop() {
        if(isEmpty()){std::cout<<"queue is empty"<<std::endl;}
        top_index++;
    }
    //清除全部内容
    void clear() {
        top_index=0;
        tail_index=-1;
    }

    ~queue(){delete[]array;}
};
//映射
template<typename K, typename V>
class map {
private:
    K* key;
    V* value;
    int size;
    bool* visited;

public:
    map():key(nullptr),value(nullptr),size(0),visited(nullptr){}
    //创建一个映射
    void init(int num) {
        key = new K[num];
        value = new V[num];
        visited = new bool[num];
        size = num;
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
    }

    ~map() {
        delete[] key;
        delete[] value;
        delete[] visited;
    }
    //检查访问指定的元素
    V operator[](K key1) {
        for (int i = 0; i < size; i++) {
            if (visited[i] && key[i] == key1) {
                return value[i];
            }
        }
       return V();
    }

    //清除全部内容
    void clear() {
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
    }
    //新建一个键值对
    void insert(K key1, V value1) {
        for (int i = 0; i < size; i++) {
            if (!visited[i]) {
                visited[i] = true;
                key[i] = key1;
                value[i] = value1;
            }
        }

    }
    //删除某一个键值对
    void remove(K key1) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (visited[i] && key[i] == key1) {
                visited[i] = false;
                found = true;
                break;
            }
        }
        if (found==false) {
            std::cout<<"key not found"<<std::endl;
        }
    }
};
//双向链表
template<typename T>
class list {
    private:
    T* array;
    int size;
    bool* visited;
    public:
    list():array(nullptr),size(0),visited(nullptr){}
    //创建一个双向链表
    void init(int num) {
        array=new T[num];
        size=num;
        visited=new bool[num];
        for(int i=0;i<num;i++) {
            visited[i]=false;
        }
    }
    //在中间某一位置插入元素
    void insert(T value,int location) {
        if (location>=size||location<0) {std::cout<<"location out of range"<<std::endl;}
        T temp=array[location];
        array[location]=value;
        for (int i=location+1;i<size-1;i--) {
            if (visited[i+1]==false) {
                break;
            }
            else {
                array[i+1]=array[i];
            }
        }
        array[location+1]=temp;
    }
    //在中间某一位置删除元素
    void remove(int location) {
        if (location>=size||location<0) {std::cout<<"location out of range"<<std::endl;}
        for (int i=location;i<size-1;i++) {
            if (visited[i+1]==false) {
                visited[i]=false;
                break;
            }
            else {
                array[i]=array[i+1];
            }
        }
    }
    //销毁链表
    void clear() {
        delete[] array;
        delete[] visited;
    }
    ~list() {
        delete[] array;
        delete[] visited;
    }
};
//优先队列
template<typename T>
class priority {
    private:
    T* array;
    int top_index;
    int tail_index;
public:
    priority():array(nullptr),top_index(0),tail_index(-1){}
    //创建
    void init(int num) {
        array = new T[num];
    }
    //访问队头元素
    T front() {
        return array[top_index];
    }
    //入队
    void push(T value) {
        tail_index++;
        array[tail_index]=value;
        for (int i=tail_index;i>0;i--) {
          if (array[i]>array[i-1]) {
              T temp=array[i];
              array[i]=array[i-1];
              array[i-1]=temp;
          }
          else {break;}
        }
    }
    //出队
    void pop() {
        top_index++;

    }
    //清除全部内容
    void clear() {
        top_index=0;
        tail_index=-1;
    }
    ~priority(){delete[]array;}
};
class HashMap {
    private:
    map<char*,int> hash;
    public:
    HashMap(){hash.init(10);}
    void insert(char* key, int value) {
        hash.insert(key,value);
    }
    int search(char* key) {
        return hash[key];
    }
};

int main() {
}