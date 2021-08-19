// borrow from https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B
// I think the while loop is just magic
// if the loop not ended, then the search must fail, so we adjust to the end of the route
// waiting for we finish the right search so that we could succeed
#include<bits/stdc++.h>
using namespace std;
unordered_map<string, multiset<string>> targets;
vector<string> route;
const string depart = "JFK";
void visit(string place){
    while (targets[place].size()){ // magic here
        auto next = *targets[place].begin();
        targets[place].erase(targets[place].begin());
        visit(next);
    }
    route.push_back(place);
}
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        targets.clear();
        route.clear();
        for (auto ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit(depart);

        return vector<string>(route.rbegin(), route.rend());
    }
};