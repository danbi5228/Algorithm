#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector <int> answer;
    queue <int> q;
    int arr[101] = {0,};
    
    for(int i = 0; i<progresses.size(); i++){
        float tmp = (100-progresses[i])/speeds[i];
        if (tmp == int(tmp)){
            q.push(int(tmp));
        }
        else q.push(int(ceil(tmp)));
    }
    int prev = q.front();
    arr[prev] += 1;
    q.pop();
    while(q.size() !=0){
        
        int tmp = q.front();
        if(prev >= tmp){
            arr[prev] += 1;
        }
        else{
            prev = tmp;
            arr[prev] += 1;
        }
        q.pop();
    }
    
    int all_item = speeds.size();
    int tmp_all_item = 0;
    for(int i = 0; i<101; i++){
        if(all_item == tmp_all_item) break;
        if(arr[i] == 0) continue;
        answer.push_back(arr[i]);
    }
    return answer;
    
}