#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int myAtoi(string str) {
    // leellenőrízzük, hogy van-e más karakter a str-ben, mint a whitespace
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') break;

        if (i == str.length() - 1) return 0;
    }

    // létrehozunk egy buffert, ami tárolni fogja az str data-t.
    stringstream os;

    // belemásoljuk az str data-ját a ss-be.
    os << str;

    int num;

    // majd a ss data-ját a int változóba, amely automatikusan elvégzi az átalakításokat, hiszen az ss tudja, hogyan kell operálni az alapvető típusokkal.
    // abban az esetben, ha overflow lenne, akkor az INT_MIN-t, vagy INT_MAX-t téríti.
    os >> num;

    return num;
}

int main() {
    string str{ "       " };

    cout << myAtoi(str) << endl;

    return 0;
}