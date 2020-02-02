#include <iostream> 
#include <string>
#include <vector>
#pragma warning(disable : 4996)
 
using namespace std;
 
vector<string> str_vec = { "c=", "c-","dz=","d-","lj","nj","s=","z=" };
 
int main() {
    string _string;
    cin >> _string;
    int tot_num = 0;
 #include <iostream> 
#include <string>
#include <vector>
#pragma warning(disable : 4996)
 
using namespace std;
 
vector<string> str_vec = { "c=", "c-","dz=","d-","lj","nj","s=","z=" };
 
int main() {
    string _string;
    cin >> _string;
    int tot_num = 0;
 
    for (int tot_idx = 0; tot_idx < str_vec.size(); tot_idx++) {
        int each_char_num = 0;
 
        int sub_index = _string.find(str_vec.at(tot_idx), 0);
        while ( sub_index  != -1 ) {
            _string.replace(sub_index, str_vec.at(tot_idx).size() , "|");
            sub_index = _string.find(str_vec.at(tot_idx), sub_index + 1);
            tot_num++;
        } 
    }
 
    for (int str_idx = 0; str_idx < _string.length(); str_idx++)
        if (_string.at(str_idx) != '|') tot_num++;
 
    cout << tot_num;
 
    return 0; 
}

    for (int tot_idx = 0; tot_idx < str_vec.size(); tot_idx++) {
        int each_char_num = 0;
 
        int sub_index = _string.find(str_vec.at(tot_idx), 0);
        while ( sub_index  != -1 ) {
            _string.replace(sub_index, str_vec.at(tot_idx).size() , "|");
            sub_index = _string.find(str_vec.at(tot_idx), sub_index + 1);
            tot_num++;
        } 
    }
 
    for (int str_idx = 0; str_idx < _string.length(); str_idx++)
        if (_string.at(str_idx) != '|') tot_num++;
 
    cout << tot_num;
 
    return 0; 
}
