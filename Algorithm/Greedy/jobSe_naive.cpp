#include <iostream>
#include <vector>

struct Job {
    std::string name;
    int profit;
    bool feasible;
};

void generate_subsets(const std::vector<Job>& jobs, std::vector<Job>& current_subset, int index, int& max_profit, int current_profit) {
    // Base case: check feasibility and update max_profit
    if (index == jobs.size()) {
        if (current_profit > max_profit) {
            max_profit = current_profit;
        }
        return;
    }

    // Include the current job in the subset
    current_subset.push_back(jobs[index]);
    generate_subsets(jobs, current_subset, index + 1, max_profit, current_profit + jobs[index].profit);

    // Exclude the current job from the subset
    current_subset.pop_back();
    generate_subsets(jobs, current_subset, index + 1, max_profit, current_profit);
}

int find_max_profit_subset(const std::vector<Job>& jobs) {
    int max_profit = 0;
    std::vector<Job> current_subset;
    generate_subsets(jobs, current_subset, 0, max_profit, 0);
    return max_profit;
}

int main() {
    std::vector<Job> jobs = {
        {"Job1", 5, true},
        {"Job2", 8, true},
        {"Job3", 6, false},
        {"Job4", 10, true}
    };

    int result = find_max_profit_subset(jobs);
    std::cout << "Maximum Profit: " << result << std::endl;

    return 0;
}
