#include<bits/stdc++.h>
using namespace std;
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> min_H;
    int K;
public:
    KthLargest() = default;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i = 0; i < k && i < nums.size(); ++i)
            min_H.push(nums[i]);
        for (int i = k; i < nums.size(); ++i)
            if (nums[i] > min_H.top()){
                min_H.pop();
                min_H.push(nums[i]);
            }
    };
    
    int add(int val) {
        if (K != min_H.size()) min_H.push(val);
        else if (val > min_H.top()){
            min_H.pop();
            min_H.push(val);
        }
        return min_H.top();
    }
};
int main()
{
    vector<int> nums;
    KthLargest *obj = new KthLargest(1,nums);
    cout << obj->add(-3) << endl;
    cout << obj->add(-2) << endl;
    cout << obj->add(-4) << endl;
    cout << obj->add(-0) << endl;
    cout << obj->add(2) << endl;

}
