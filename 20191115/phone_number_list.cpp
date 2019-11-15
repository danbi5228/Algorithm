#include <string>
#include <vector>
#include <string>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(int i = 0; i<phone_book.size(); i++){
        string str_standard = phone_book[i];
        int num_size = str_standard.size();
        for(int j = 0; j<phone_book.size(); j++){
            if (i == j) continue;
            if (str_standard == phone_book[j].substr(0, num_size)) {
                return false;
            }
        }
    }
    return true;
}