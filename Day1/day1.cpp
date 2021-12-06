#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int countIncreasedValues(vector<int> input);

int main()
{
    ifstream input(".\\Day1\\input.txt");
    string line;
    vector<int> input_int;
    vector<int> input_sliding_window;
    int input_size = 0;
    int result_part1 = 0;
    int result_part2 = 0;
    int sum = 0;

    input_int.reserve(1000);
    input_sliding_window.reserve(1000);

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

    input_size = input_int.size();
    cout << input_size << endl;

    // for(int i = 0; i < input_size - 1; i++)
    // {
    //     if(input_int[i+1] > input_int[i])
    //     {
    //         result_part1++;
    //     }
    // }

    result_part1 = countIncreasedValues(input_int);

    for(int j = 0; j < input_size - 2; j++)
    {
        sum = input_int[j] + input_int[j+1] + input_int[j+2];
        input_sliding_window.push_back(sum);
    }

    result_part2 = countIncreasedValues(input_sliding_window);

    cout << result_part1 << endl;
    cout << result_part2 << endl;

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