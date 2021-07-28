#include<bits/stdc++.h>
using namespace std;
map<int, int> freq;
unordered_map<int, bool> isInHeap;
auto comp = [](int n1, int n2){return freq[n1] > freq[n2];};
priority_queue<int, vector<int>, decltype(comp)> heap(comp);
int cnt = 0;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        freq.clear();
        isInHeap.clear();
        cnt = 0;
        for (auto number : nums){
            ++freq[number];
            isInHeap[number] = false;
        }
            
        for (auto number : nums){
            if (!isInHeap[number]){
                isInHeap[number] = true;
                heap.push(number);
                ++cnt;
                if (cnt == k + 1){
                    --cnt;
                    heap.pop();
                }
            }
        }
        vector<int> ans;
        while (!heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};
// int main(){
//     Solution sol;
//     vector<int> test1 = {3, 0, 1, 0}, res;
//     sol.topKFrequent(test1, 1);
// }