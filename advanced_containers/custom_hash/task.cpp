#include "task.h"
using namespace std;


void PopulateHashMap(
    std::unordered_map<SuperKey, std::string>& hashMap,
    const std::vector<std::pair<SuperKey, std::string>>& toAdd
) {
    for (const auto& it : toAdd) {
        hashMap[it.first] = it.second;
    }
}

