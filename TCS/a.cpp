#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

struct Transition {
    char next_state;
    int input;
    int output;
};

void detectSequence(const vector<tuple<char, char, int, int>>& transitions) {
    unordered_map<char, vector<Transition>> state_transitions;
    char initial_state = get<0>(transitions[0]); // First present_state in input as initial state
    char final_state = '\0';
    vector<int> sequence;

    // Parse transitions and populate the state_transitions map
    for (const auto& transition : transitions) {
        char present_state = get<0>(transition);
        char next_state = get<1>(transition);
        int input_val = get<2>(transition);
        int output_val = get<3>(transition);

        state_transitions[present_state].push_back({next_state, input_val, output_val});

        // Identify the final state if output is 1
        if (output_val == 1) {
            final_state = present_state;
        }
    }

    // Traverse state transitions to form the sequence
    char current_state = initial_state;
    set<char> visited_states;

    while (visited_states.find(current_state) == visited_states.end()) {
        visited_states.insert(current_state);
        bool transition_found = false;

        for (const auto& transition : state_transitions[current_state]) {
            if (transition.next_state != current_state) {
                sequence.push_back(transition.input);
                current_state = transition.next_state;
                transition_found = true;

                // If output is 1, we've reached the end of a sequence
                if (transition.output == 1) {
                    break;
                }
            }
        }

        if (!transition_found || (transition_found && state_transitions[current_state][0].output == 1)) {
            break;
        }
    }

    // Determine if the detector is overlapping or non-overlapping
    string detector_type = "Overlapping Sequence Detector";
    if (current_state == final_state) {
        for (const auto& transition : state_transitions[final_state]) {
            if (transition.next_state == initial_state && transition.output == 1) {
                detector_type = "Non Overlapping Sequence Detector";
                break;
            }
        }
    }

    // Output the results
    for (int bit : sequence) {
        cout << bit;
    }
    cout << endl;
    cout << detector_type << endl;
}

int main() {
    // Example 1 Input
    vector<tuple<char, char, int, int>> transitions1 = {
        {'a', 'b', 1, 0},
        {'b', 'c', 0, 0},
        {'b', 'b', 1, 0},
        {'a', 'a', 0, 0},
        {'c', 'a', 0, 0},
        {'c', 'a', 1, 1}
    };

    cout << "Example 1 Output:\n";
    detectSequence(transitions1);

    // Example 2 Input
    vector<tuple<char, char, int, int>> transitions2 = {
        {'a', 'b', 1, 0},
        {'a', 'a', 0, 0},
        {'b', 'a', 0, 0},
        {'b', 'c', 1, 0},
        {'c', 'c', 1, 0},
        {'d', 'a', 0, 0},
        {'d', 'b', 1, 1},
        {'c', 'd', 0, 0}
    };

    cout << "\nExample 2 Output:\n";
    detectSequence(transitions2);

    return 0;
}
