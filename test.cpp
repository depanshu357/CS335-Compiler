#include <iostream>
#include <string>

using namespace std;

extern "C" void func(){
    string a = "Hello";
    string b = "World";
    cout << (a > b);
}

int main(){
    func();
}