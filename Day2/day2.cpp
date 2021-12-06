#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Movement{
    string direction;
    int steps;
};


int main()
{
    string line;
    Movement tmp = {"", 0};
    vector<Movement> input_movements;
    int horizontal_pos = 0;
    int depth = 0;
    int aim = 0;
    int result = 0;

    ifstream input(".\\Day2\\input.txt");
    if(input.is_open())
    {
        while(!input.eof())
        {
            getline(input, line);
            int del_idx = line.find(" ");
            tmp.direction = line.substr(0, del_idx);
            tmp.steps = stoi(line.substr(del_idx + 1, line.length() - 1));
            input_movements.push_back(tmp);
        }
        input.close();
    }
    else cout << "Unable to open input file." << endl;

    //Output number of elements in vector to terminal
    int input_size = input_movements.size();
    cout << "Number of elements in vector read from file: " << input_size << endl;

    for(int i = 0; i < input_movements.size(); i++)
    {
        string tmp_direction = input_movements[i].direction;
        int tmp_steps = input_movements[i].steps;
        if(tmp_direction == "forward")
        {
            horizontal_pos += tmp_steps;
        }
        else if(tmp_direction == "down")
        {
            depth += tmp_steps;
        }
        else if(tmp_direction == "up")
        {
            depth -= tmp_steps;
        }
        else cout << "Bad entry in input index: " << i << endl;
    }

    result = horizontal_pos * depth;

    cout << "Horizontal position = " << horizontal_pos << endl;
    cout << "Depth = " << depth << endl;
    cout << "Result of part 1 (multiply values of horizontal position and depth): " << result << endl;


    horizontal_pos = 0;
    depth = 0;
    for(int i = 0; i < input_movements.size(); i++)
    {
        string tmp_direction = input_movements[i].direction;
        int tmp_steps = input_movements[i].steps;
        if(tmp_direction == "forward")
        {
            horizontal_pos += tmp_steps;
            depth += aim * tmp_steps;
        }
        else if(tmp_direction == "down")
        {
            aim += tmp_steps;
        }
        else if(tmp_direction == "up")
        {
            aim -= tmp_steps;
        }
        else cout << "Bad entry in input index: " << i << endl;
    }

    result = horizontal_pos * depth;

    cout << "Horizontal position = " << horizontal_pos << endl;
    cout << "Depth = " << depth << endl;
    cout << "Result of part 2 (multiply values of horizontal position and depth): " << result << endl;

}