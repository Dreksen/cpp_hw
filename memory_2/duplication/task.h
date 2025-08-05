//# Duplication
//
//Реализуйте две функции -- `DeDuplicate` и `Duplicate`
//
//* Функция `DeDuplicate` принимает `vector<unique_ptr<string>> in` и возвращает `vector<shared_ptr<string>> out`, такой что:
//- `*in[i] == *out[i]` -- значения объектов на i-й позициях совпадает.
//- Каждое уникальное значение создано только в одной копии и все ссылки ведут на него.
//
//* Функция `Duplicate` производит обратное преобразование.

#include <unordered_map>
#include "vector"
#include "string"
#include "memory"
using namespace std;
vector<shared_ptr<string>> DeDuplicate(const vector<unique_ptr<string>>& in) {
    unordered_map<string, shared_ptr<string>> unique_map;
    vector<shared_ptr<string>> out;
    for (const auto& ptr : in) {
        if (ptr) {
            auto it = unique_map.find(*ptr);
            if (it == unique_map.end()) {
                auto newptr = make_shared<string>(*ptr);
                unique_map[*ptr] = newptr;
                out.push_back(newptr);
            } else {
                out.push_back(it->second);
            }
        }
    }
    return out;
}

vector<unique_ptr<string>> Duplicate(const vector<shared_ptr<string>>& in) {
    vector<unique_ptr<string>> out;
    for (const auto& ptr : in) {
        if (ptr) {
            out.push_back(make_unique<string>(*ptr));
        }
    }

    return out;
}
