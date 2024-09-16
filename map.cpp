#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    map<int,string> m;
    m[101] = "Shoruv";
    m[102] = "Tasdik";
    m[103] = "Arian";

    for (auto it:m) {
        cout << it.first << "," << it.second << endl;
    }
}