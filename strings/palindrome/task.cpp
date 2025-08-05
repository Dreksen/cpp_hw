#include "task.h"
// #include <iostream>
using namespace std;
/* **Постановка задачи**: написать функцию, которой на вход подается строка из ascii-символов;
функция возвращает true, если строка является палиндромом, и false, если не является.
При этом не нужно в проверке учитывать символы, не являющиеся буквами, а также не нужно учитывать регистр букв.
Пустая строка считается палиндромом.
*/

bool isalpha(unsigned char c) {
    if ((c >= 'a' && c <= 'z') or (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

unsigned char tolower(unsigned char c) {
    if (c >= 'A' and c <= 'Z')
        return c - 'A' + 'a';
    return c;
}


bool is_palindrome(const std::string& s) {
    int n = s.size();
    int i = 0, j = n - 1;
    while (i <= j) {
        // cout << i << ' ' << j << endl;
        if (!isalpha(s[i])) {
            i++;
            continue;
        }
        if (!isalpha(s[j])) {
            j--;
            continue;
        }
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
