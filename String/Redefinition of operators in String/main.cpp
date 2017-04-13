#include "String.h"
int main ()
{

    String s1("dasdas", 6);
    s1.print();
    String s2 = s1;
    cout<<"Result from s1==s2    = " <<(s1==s2) << endl;
    cout<<(s1 == s2) << endl;
    s2.print();
    String s3(s2);
    s3.print();
    s3.concat("C++");
    String s4("aaa", 3);
    cout<<"Result from s1==s3    = " <<(s1==s3) << endl;
    cout<<"Result from s1 < s3   = " <<(s1 < s3) << endl;
    cout<<"Result from s1 > s4   = " <<(s1 > s4) << endl;
    cout<<"Result from s1 <= s3  = " <<(s1 <= s3) << endl;
    cout<<"Result from s1 >= s3  = " <<(s1 >= s3) << endl;
    s1 += s4;
    cout<<"Result from s1 += s4  = " <<s1.GetData()<< endl;
    String s5 ("abcab", 5);
    String s6 ("ca", 2);
    cout << (s5 -= s6);
    String s7;
    cin >> s7;
    s3.print();

    return 0;
}