#include<bits/stdc++.h>
using namespace std;

// Structure to represent a pipe with start, end, and diameter
struct Pipe {
    int start;
    int end;
    int diameter;
};

// Function to process pipes and find the efficient solution
void processPipes(int num_houses, int num_pipes, list<Pipe>& pipes) {
    // Maps to store information about pipes
    map<int, int> starting_vertex;  // Map from house to its starting vertex
    map<int, int> ending_vertex;    // Map from house to its ending vertex
    map<int, int> diameter;         // Map from house to the diameter of the pipe

    // Populate the maps with information from the pipes list
    for (const auto& pipe : pipes) {
        starting_vertex[pipe.start] = pipe.end;
        ending_vertex[pipe.end] = pipe.start;
        diameter[pipe.start] = pipe.diameter;
       
    }

    // List to store the final output of pipes
    list<Pipe> resultPipes;

    // Loop through houses to find pipes with no ending vertex
    for (int j = 1; j <= num_houses; ++j) {
        // Check if the house has no ending vertex but has a starting vertex
        if (ending_vertex.find(j) == ending_vertex.end() && starting_vertex.find(j) != starting_vertex.end()) {
            int min_diameter = INT_MAX;
            int current_house = j;

            // Traverse the pipe to find the minimum diameter
            while (starting_vertex.find(current_house) != starting_vertex.end()) {
                min_diameter = min(min_diameter, diameter[current_house]);
                current_house = starting_vertex[current_house];
            }

            // Add the details of the component to the result list
            resultPipes.push_back({j, current_house, min_diameter});
        }
    }

    // Output the number of pipes and their details
    cout << resultPipes.size() << endl;

    for (const auto& pipe : resultPipes)
        cout << pipe.start << " " << pipe.end << " " << pipe.diameter << endl;
}

int main() {
    //https://chat.openai.com/share/d982092c-2ed8-456b-8350-28e18bd940b7
    // Input parameters
    int num_houses = 9;
    int num_pipes = 6;

    // List of pipes with their details
    list<Pipe> pipes = {
        {7, 4, 98},
        {5, 9, 72},
        {4, 6, 10},
        {2, 8, 22},
        {9, 7, 17},
        {3, 1, 66}
    };

    // Call the function to process pipes and find the efficient solution
    processPipes(num_houses, num_pipes, pipes);

    return 0;
}
