class Solution {
    class comparator {
        public:
        bool operator() (vector<int>& cost1, vector<int>& cost2) {
            return (cost1[0] - cost1[1]) < (cost2[0] - cost2[1]);
        }
    };
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        comparator cmp;
        int result = 0;
        sort(costs.begin(), costs.end(), cmp);
        int n = costs.size();
        for (int i = 0; i < n; i++) {
            if (i < n/2) {
                result += costs[i][0];
            } else {
                result += costs[i][1];
            }
        }
        return result;
    }
};