
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class Queue{
private:
    class queueNode{
    public:
        T data;
        queueNode* next;
        queueNode(int data) : data(data){

        };
    };
    queueNode* tail;
    queueNode* head;
    T _size;
public:
    int size(){
        return _size;
    }
    Queue() : head(nullptr), tail(nullptr), _size(0) {

    }
    void push(T data){
        if(_size <= 0) {
            head = new queueNode(data);
            _size++;
            tail=head;
            return;
        }
        tail->next = new queueNode(data);
        _size++;
        tail = tail->next;
    }
    T pop(){
        if(_size <= 0) throw "Queue is empty";
        int data = head->data;
        queueNode* tmp = head;
        head=head->next;
        delete tmp;
        _size--;
    }
    T front(){
        return head->data;
    }
    T back(){
        return tail->data;
    }
    ~Queue(){};
};
template  <typename T>
class priorityQueue{
private:
    class priorityQueueNode{
    public:
        int priority;
        T _data;
        priorityQueueNode* next;
        priorityQueueNode(int data, int priority):
                _data(data),
                priority(priority),
                next(NULL){};
        priorityQueueNode(priorityQueueNode &n): _data(n._data), next(n.next){}
        priorityQueueNode() : _data(0), next(nullptr){};
    };
public:
    int length;
    priorityQueueNode* head;
    priorityQueue(): length(0), head(nullptr){}

    void print(){
        priorityQueueNode* tmp = head;
        for(int i =0; i < length; i++){
            std::cout << tmp->_data << " ";
            tmp=tmp->next;
        }
        std::cout << "\n";
        priorityQueueNode* tmp1 = head;
        for(int i =0; i < length; i++){
            std::cout << tmp1->priority << " ";
            tmp1=tmp1->next;
        }
        std::cout << "\n";
        std::cout << "\n";
    }
    void insert(T data, int priority){
        priorityQueueNode* _new = new priorityQueueNode(data, priority);
           if(length >= 2) {
            priorityQueueNode* tmp = head;
            bool start = true;
            for(int i = 0; i < length - 1; i++){
                if (start){
                    if(_new->priority > head->priority){
                        _new->next=head;
                        head=_new;
                        break;
                    }
                    start = false;
                }

                if(_new->priority >= tmp->next->priority){
                    _new->next = tmp->next;
                    tmp->next = _new;
                    break;
                } else if(i != length - 2) {
                    tmp = tmp->next;
                } else {
                    _new->next=nullptr;
                    tmp->next->next = _new;
                }


            }

            length++;
        }
        if (length == 1){
            if(head->priority < _new->priority) {
                priorityQueueNode* tmp2 = head;
                _new->next = head;
                head = _new;
                length++;
            } else {
                head->next = _new;
                _new->next = nullptr;
                length++;
            }
        }
       if(length == 0){
           head = _new;
           _new->next = nullptr;
           length++;
       }
    }
    T pull(){
            T result = head->_data;
            head = head->next;
            length--;
            return result;
    }

};
void ReadInput(std::string filename, Queue<char> &queue){
    std::ifstream fin(filename);
    std::string input;
    std::getline(fin, input);
    for(int i =0; i < input.length(); i++){
        queue.push((char)input[i]);
    }
    fin.close();
}
Queue<char>& Conversion(Queue<char> input){
    Queue<char> output;
    priorityQueue<char> tmp;
    int n = input.size();
    char current;
    for(int i =0; i < n; i++){
        current = input.pop();
        if(current != '*'){
            tmp.insert(current, (int)current);
        } else {
            if(tmp.length > 0)
                output.push(tmp.pull());
        }
    }
    return output;
}
void WriteCollection(std::string filename, Queue<char> output){
    std::ofstream fout(filename);
    for(int i = 0; i < output.size(); i++){
        fout << output.pop();
    }
    fout.close();
}
int main() {
    Queue<char> queue;
    ReadInput("input.txt", queue);

    Queue<char>& final = Conversion(queue);

    WriteCollection("output.txt", final);

    return 0;
}
