#include "String.h"
#include <iostream>

int main()
{
    using namespace std;
    /* Constructor */
    String a;
    a = "asdf";
    String b = "zxcv";
    String c = b;   //Copy Constructor
    String e('x',10);
    String d = a;   //Copy Constructor
    /* Overload "<<" */
    cout << "a=" << a << endl
    << "b=" << b << endl
    << "c=" << c << endl
    << "d=" << d << endl;
    cout << "e=" << e << endl;
    /* Iterator */
    for (String::Iterator i=a.begin();i!=a.end();i++) cout << *i << endl;
    for (String::Iterator i=a.rbegin();i!=a.begin();i--) cout << *(i-1) << endl;
    /* at() length() size()*/
    cout << "Test at()\n";
    for (int i=0;i<a.length();i++) a.at(i) = 'z';
    for (int i=0;i<a.size();i++) cout << a.at(i)  << endl;
    /* [] */
    cout << "Test []\n";
    for (int i=0;i<a.length();i++) a[i] = 'y';
    for (int i=0;i<a.size();i++) cout << a[i]  << endl;
    /* front() */
    cout << "Test front()\n";
    cout << a.front() << endl;
    a.front() = 'm';
    cout << a.front() << endl;
    /* back */
    cout << "Test back()\n";
    cout << a.back() << endl;
    a.back() = 'n';
    cout << a.back() << endl;
    for (int i=0;i<a.size();i++) cout << a[i] << endl;
    /* c_str() */
    cout << "Test c_str()\n";
    cout << "String <<\n";
    cout << a << endl;
    char* cs = a.c_str();
    cout << "char <<\n";
    cout << cs << endl;
    /* empty() */
    cout << "Test empty()\n";
    cout << "a.empty() <<\n";
    cout << a.empty() << endl;
    String f;
    cout << "f.empty() <<\n";
    cout << f.empty() << endl;
    /* append() */
    cout << "Test append()\n";
    cout << "a.append(b) <<\n";
    cout << a.append(b) << endl;
    cout << "a.append('x') <<\n";
    cout << a.append('x') << endl;
    cout << "a.append(\"mnbv\")\n";
    cout << a.append("mnbv") << endl;
    /* push_back() */
    cout << "Test push_back()\n";
    cout << "a.push_back(b) <<\n";
    cout << a.push_back(b) << endl;
    cout << "a.push_back('x') <<\n";
    cout << a.push_back('x') << endl;
    cout << "a.push_back(\"mnbv\")\n";
    cout << a.push_back("mnbv") << endl;
    /* Move Constructor and "+" */
    cout << "Test Move Constructor\n";
    String g = a + b;
    cout << g << endl;
    return 0;
}