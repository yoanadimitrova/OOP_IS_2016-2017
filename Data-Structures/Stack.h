#include <iostream>

using namespace std;

template<typename T>
struct Node
{
    T data; // int, double, customClass
    Node<T>*  next; // sochi kum nullptr ako nqmame elementi; sochi kum sledvashtiq elem

    Node(const T& _data, Node<T>* _next = nullptr) // moje i T _data, no const T& _data ni osigurqva, che nqma da go promenim
    {
        //Google why const reference
        data = _data;
        next = _next;
    }
};

template<typename T>
class Stack
{
public:
    // vupreki, che ne e dinamechno pak si pravim 4-kata
    Stack();
    Stack(const Stack&);
    Stack operator=(const Stack&);
    ~Stack();

    T pop(); // vrushta dannite v nachaloto
    T top() const;
    void push(const T& data);
    size_t len() const; // vrushta razmera // const zashtot ne promenqme nishto
    bool isEmpty() const;

private:
    Node<T>* first; // ukazatel kum 1-viq elem
    void copyReverse(const Stack&);
    size_t size;
    void copy(const Stack&);
    void init();
    void empty();
};

template<typename T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        Node<T>* temp = first; // temp i first sa edno neshto; pazim stoinostta na first v temp
        T data = temp -> data;
        first = first -> next; // poitera veche ne sochi kum purviq,a kum sledvashtiq
        delete temp; // iztrivame tozi, koito e bil predhoden; taka nqma memory leak
        this -> size--; // moje i samo size--;
        return data; // vrushtame novata stoinost
    }
    else
    {
        cout << "Empty stack." << endl;
        return NULL;
    }

}

/*
// ako e void pop()
template<typename T>
void Stack<T>::pop()
{
    if(isEmpty())
    {
        Node<T>* temp = first; // temp i first sa edno neshto; pazim stoinostta na first v temp
        first = first -> next; // poitera veche ne sochi kum purviq,a kum sledvashtiq
        delete temp; // iztrivame tozi, koito e bil predhoden; taka nqma memory leak
        this -> size--;
    }
    else
    {
        cout << "Empty stack." << endl;
    }
}
*/

template<typename T>
T Stack<T>::top() const
{
    if(!isEmpty())
    {
        return first -> data;
    }
    // ne pishem else za da moje da stigne do vtoriq return
    return NULL;
}

template<typename T>
void Stack<T>::push(const T& data)
{
    Node<T>* add = new Node(data,  this -> first);
    // Node<T>* add; // iskame ukazatel kum Node; nov node
    // add -> data = data;
    // add -> next = this -> first;

    if(add)
    {
        this -> first = add;
        this -> size++;
    }
}

template<typename T>
size_t Stack<T>::len() const
{
    return this -> size;
}

template<typename T>
void Stack<T>::isEmpty()
{
    return this -> first == nullptr; // ili return this -> size == 0;
}

template<typename T>
void Stack<T>::copyReverse(const Stack& st) // kopirame steka no naobratno i taka posledniqt elem stava 1-vi
{
    is(!isEmpty())
    {
        this -> empty();
    }

    Node<T>* temp = st -> first; // temp sochi kum 1-viq elem
    for(size_t i = 0; i < st.len(); i++)
    {
        this -> push(temp->data);
        temp = temp -> next;
    }
}

template<typename T>
void Stack<T>::copy(const Stack& st) // 1 -> 2 -> 3 -> 4
{
    Stack<T> reverse; // pravim empty stack
    reverse.copyReverse(st); // 4 -> 3 -> 2 -> 1
    this -> copyReverse(reverse); // 1 -> 2 -> 3 -> 4
}

template<typename T>
void Stack<T>::init()
{
    this -> first == nullptr;
    this -> size = 0;
}

template<typename T>
void Stack<T>::empty()
{
    size_t sizeOne = this -> size;
    for(size_t i = 0; i < sizeOne; i++)
    {
        // za void pop
        // cout <<  this -> top() << endl;
        // this -> pop();
        this -> pop();
    }
}