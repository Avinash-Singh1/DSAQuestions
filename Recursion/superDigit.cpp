#include <iostream>
#include <string>

using namespace std;

// Function to calculate the sum of digits of a string
long long sumOfDigits(string num) {
    long long sum = 0;
    for (char digit : num) {
        sum += digit - '0';
    }
    return sum;
}

// Function to recursively find the super digit of a number
int superDigitHelper(long long num) {
    if (num < 10) {
        return num;
    }
    long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return superDigitHelper(sum);
}

// Main function to calculate the super digit
int superDigit(string n, int k) {
    long long initialSum = sumOfDigits(n);
    long long totalSum = initialSum * k;
    return superDigitHelper(totalSum);
}

long long sumOfDigits2(string num) {
    long long sum = 0;
    for (char digit : num) {
        sum += digit;
        cout<<"sum: "<<sum<<endl;
    }
    return sum;
}

int main() {
    string n;
    int k;
    
    cin >> n >> k;
    
    // cout << superDigit(n, k) << endl;
    cout<<sumOfDigits2(n)<<endl;
    return 0;
}
