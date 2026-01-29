#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

string formatSocial(long double n) {
    if (n >= 1e15) {
        char buffer[50];
        sprintf(buffer, "%.2Le", n);
        return string(buffer);
    }

    
    if (n < 1000) return to_string((long long)n);

    long double num = n;
    string suffix = "";

    if (n >= 1e12) {
        num /= 1e12;
        suffix = " Trillion";
    } else if (n >= 1e9) {
        num /= 1e9;
        suffix = " Billion";
    } else if (n >= 1e6) {
        num /= 1e6;
        suffix = " Million";
    } else if (n >= 1000) {
        num /= 1000.0;
        suffix = " Thousand";
    }

    string s = to_string(num);
    size_t dot = s.find('.');
    if (s[dot + 1] == '0') s = s.substr(0, dot);
    else s = s.substr(0, dot + 2);

    return s + suffix;
}

long double moneyDoubles(int days) {
    return pow(2.0L, days - 1);
}

int main() {
    int days;
    cout << "Enter number of days: ";
    cin >> days;

    long double res = moneyDoubles(days);

    cout << "1$ on day 1 which doubles every day." << endl;
    cout << "Your Money after " << days << " days will be: " << formatSocial(res) << " $" << endl;

    return 0;
}