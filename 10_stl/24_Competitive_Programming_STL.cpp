#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> numbers = {
        10, 20, 10, 30, 20, 10, 40
    };

    unordered_map<int, int> frequency;

    for (int number : numbers)
    {
        frequency[number]++;
    }

    vector<pair<int, int>> result;

    for (const auto& entry : frequency)
    {
        result.push_back({entry.first, entry.second});
    }

    sort(result.begin(), result.end(),
        [](const pair<int, int>& a, const pair<int, int>& b)
        {
            if (a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        });

    cout << "Number -> Frequency\n";

    for (const auto& [number, count] : result)
    {
        cout << number << " -> " << count << endl;
    }

    return 0;
}