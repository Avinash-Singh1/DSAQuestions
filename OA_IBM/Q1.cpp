#include <vector>

long getProfitablePairs(const std::vector<int>& profit, const std::vector<int>& implementationCost) {
    int n = profit.size();
    long count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((profit[i] - implementationCost[i]) + (profit[j] - implementationCost[j]) > 0) {
                count++;
            }
        }
    }

    return count;
}
