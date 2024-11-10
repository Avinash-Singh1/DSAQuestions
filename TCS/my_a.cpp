#include <iostream>
#include <string>

class SequenceDetector {
private:
    int state;

public:
    // Constructor to initialize the state
    SequenceDetector() {
        state = 0;
    }

    // Method to reset the state
    void reset() {
        state = 0;
    }

    // Method to detect the sequence
    bool detect_sequence(const std::string& sequence) {
        bool detected = false;

        // Iterate through each character in the sequence
        for (char ch : sequence) {
            if (state == 0) {
                if (ch == 'a') {
                    state = 1;
                }
            } else if (state == 1) {
                if (ch == 'b') {
                    state = 2;
                } else if (ch == 'a') {
                    state = 1;
                } else {
                    reset();
                }
            } else if (state == 2) {
                if (ch == 'c') {
                    detected = true;
                    reset();
                } else {
                    reset();
                }
            }
        }
        return detected;
    }
};

int main() {
    // Create an object of SequenceDetector
    SequenceDetector detector;

    // Sample sequence for testing
    std::string sequence;
    std::cout << "Enter the sequence: ";
    std::cin >> sequence;

    // Detect if the sequence "abc" appears
    if (detector.detect_sequence(sequence)) {
        std::cout << "Sequence 'abc' detected!" << std::endl;
    } else {
        std::cout << "Sequence 'abc' not detected." << std::endl;
    }

    return 0;
}
