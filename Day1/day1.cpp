#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int countIncreasedValues(vector<int> input);
vector<int> slidingWindow(vector<int> input, int windowSize);

int main()
{
    ifstream input(".\\Day1\\input.txt");
    string line;
    vector<int> input_int;                      //Vector for reading input file
    vector<int> input_sliding_window;           //Vector for sums of sliding window approach
    int input_size = 0;
    int result_part1 = 0;
    int result_part2 = 0;

    input_int.reserve(1000);
    input_sliding_window.reserve(1000);

    //Read input from file into vector
    if(input.is_open())
    {
        while(!input.eof())
        {
            getline(input, line);
            input_int.push_back(stoi(line));
        }
        input.close();
    }
    else cout << "Unable to open input file." << endl;

    //Output number of elements in vector to terminal
    input_size = input_int.size();
    cout << "Number of elements in vector read from file: " << input_size << endl;

    //Get result for part 1 (number of increasing values in raw measurement data)
    result_part1 = countIncreasedValues(input_int);

    //Calculate sliding window result data on raw measurement data
    input_sliding_window = slidingWindow(input_int, 3);

    //Get result for part 2 (number of increasing values in smoothened data from sliding window)
    result_part2 = countIncreasedValues(input_sliding_window);

    //Output results for part 1 & 2 to terminal
    cout << "Result of Part 1 (Raw Data): " << result_part1 << endl;
    cout << "Result of Part 2 (Smoothened Data): " << result_part2 << endl;
}

int countIncreasedValues(vector<int> input)
{
    int result = 0;
    for(int i = 0; i < input.size() - 1; i++)
    {
        if(input[i+1] > input[i])
        {
            result++;
        }
    }
    return result;
}

vector<int> slidingWindow(vector<int> input, int windowSize)
{
    int sum = 0;
    vector<int> result;
    for(int j = 0; j < input.size() - (windowSize - 1); j++)
    {
        sum = 0;
        for(int k = 0; k < windowSize; k++)
        {
            sum += input[j+k];
        }
        result.push_back(sum);
    }
    return result;
}