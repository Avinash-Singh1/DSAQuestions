#include <vector>
#include <algorithm>

int getMinCores(const std::vector<int>& start, const std::vector<int>& end) {
    std::vector<std::pair<int, int>> events;

    // Add start and end events
    for (size_t i = 0; i < start.size(); ++i) {
        events.emplace_back(start[i], 1);       // Start of an interval
        events.emplace_back(end[i] + 1, -1);    // End of an interval
    }

    // Sort events by time
    std::sort(events.begin(), events.end());

    int max_cores = 0;
    int current_cores = 0;

    // Traverse sorted events
    for (const auto& event : events) {
        current_cores += event.second;             // Update current cores
        max_cores = std::max(max_cores, current_cores);  // Update max cores if needed
    }

    return max_cores;
}
