#include <iostream>

using namespace std;

//Templates:

template <class T>
T getMax(T a, T b)
{
    return a > b ? a : b;
}

void swap (int& a, int& b);
template <typename T>
void swap_t(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << getMax <int> (5,6);
    cout << getMax<double> (5.4, 6.0);
    int a = 3;
    int b = 5;
    swap_t<int>(a, b);
//    cout << swap_t;
    return 0;
}
