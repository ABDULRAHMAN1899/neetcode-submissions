class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int arr[26];
        for(int i=0;i<26;i++){
            arr[i]=0;
        }
        for(int i=0;i<tasks.size();i++){
            arr[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                pq.push(arr[i]);
            }
        }
        queue<pair<int,int>> cooldown;
        int time=0;
        while(!pq.empty() || !cooldown.empty()){
            time++;
            while(!cooldown.empty() && cooldown.front().first==time){
                pq.push(cooldown.front().second);
                cooldown.pop();
            }
            if(!pq.empty()){
                int cnt=pq.top();
                pq.pop();
                cnt--;
                if(cnt>0){
                    cooldown.push({time+n+1,cnt});
                }
            }
            
        }
        return time;
    }
};
