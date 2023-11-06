#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <map>

bool compare(std::string a, std::string b) {
    return a.length() > b.length();
}



int get_multi(std::string str1, std::string str2, const std::map<char, int>& pair_list) {
    int num_a = 0;
    int num_b = 0;
    for (char c : str1) {
        int gap = c - 'a';
        num_a = num_a | 1 << gap;
    }
    for (char c : str2) {
        int gap = c - 'a';
        num_b = num_b | 1 << gap;
    }
    if (num_a & num_b) {
        return 0;
    }
    else {
        return str1.length() * str2.length();
    }
}

int get_max_multi(std::vector<std::string>& a) {
    std::sort(a.begin(), a.end(), compare);
    std::cout<< "sort" <<std::endl;
    std::map<char, int> pair_list;
    for (int i = 0; i < 26; i++) {
        char symbol = 'a' + i;
        pair_list[symbol] = i;
    }
    int max_value = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i].length() * a[j].length() <= max_value) { // early_stop
                break;
            }
            int temp_value = get_multi(a[i], a[j], pair_list);
            if (max_value < temp_value) {
                max_value = temp_value;
            }
        }
    }
    
    return max_value;
}












void main() {
    std::vector<std::string> a = { "a","aa","aaa","aaaa"};
    int max_value = get_max_multi(a);
    std::cout << max_value;
}