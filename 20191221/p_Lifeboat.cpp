#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
bool desc(int a, int b){ return a > b; }

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector <pair<int, int>> p_arr;
    sort(people.begin(), people.end(), desc);
    for(int i = 0; i<people.size(); i++){
        bool isInsert = 0;
        for (int j = 0; j<p_arr.size(); j++){
            if(p_arr[j].first == 0) continue;
            if(p_arr[j].second + people[i] <= limit && p_arr[j].first == 1){
                isInsert = 1;
                p_arr[j].first = 0;
                break;
            }
        }
        
        if(isInsert == 0){
            p_arr.push_back(make_pair(1, people[i]));
        }
    }
    
    return p_arr.size();
}