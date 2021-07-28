// Not my idea
// view as one should look at its left neighbour , and then look at its right neighbour
//Do it in two directions.
//  1.The first loop makes sure children with a higher rating get more candy than its left neighbor;
//  2.the second loop makes sure children with a higher rating get more candy than its right neighbor.
// how to proof?
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies (ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i)
            if (ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;

        for (int i = ratings.size() - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1]) candies[i] = max(candies[i + 1] + 1, candies[i]);// ensure not decrease
        return accumulate(candies.begin(), candies.end(), 0);
    }
};