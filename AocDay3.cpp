// AocDay3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>

#include <unordered_map>
std::vector <char> commonItem;
std::map<char, int> ItemPriority{
    {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5},
    {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10},
    {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15},
    {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20},
    {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25},
    {'z', 26}, {'A', 27}, {'B', 28}, {'C', 29}, {'D', 30},
    {'E', 31}, {'F', 32}, {'G', 33}, {'H', 34}, {'I', 35},
    {'J', 36}, {'K', 37}, {'L', 38}, {'M', 39}, {'N', 40},
    {'O', 41}, {'P', 42}, {'Q', 43}, {'R', 44}, {'S', 45},
    {'T', 46}, {'U', 47}, {'V', 48}, {'W', 49}, {'X', 50},
    {'Y', 51} , {'Z', 52}
};

void findCommonELement(std::string_view lhs, std::string_view rhs, std::vector<char>& commonItem)
{

    if (lhs.empty() || rhs.empty())
        return;
    std::unordered_set left (lhs.begin(), lhs.end());
    std::unordered_set right(rhs.begin(), rhs.end());
    for (char c : right)
        if (left.count(c)) {
            commonItem.emplace_back(c);
            return;
        }
}




void Day3SolutionPart1() {
    std::ifstream aocInput;
    aocInput.open("C:\\Users\\j_cha\\Downloads\\AOCDay3.txt");
    if (aocInput.fail())
    {
        std::cout << "Failed to open file \n";
        std::exit(-1);
    }
    std::string line;
    while (std::getline(aocInput, line))
    {
        std::string substr1 = line.substr(0, line.length() / 2);
        std::string substr2 = line.substr(line.length() - line.length() / 2, line.length() / 2);
        std::cout << substr1 << " " << substr2 << '\n';
        findCommonELement(substr1, substr2, commonItem);
    }
    int sum = 0;
    for (int i = 0; i < commonItem.size(); i++)
        sum += ItemPriority[commonItem[i]];
       
    std::cout << sum;
}


void CheckCommonElement(std::string_view first, std::string_view second, 
    std::string third, std::vector<char> &commonitem) 
{
    std::unordered_set<char> _first(first.begin(), first.end());
    std::unordered_set<char> _second(second.begin(), second.end());
    for (char c : third) {
        if (_first.count(c) && _second.count(c)) {
            commonItem.emplace_back(c);
            return;
        }
    }
}

void Day3SolutionPart2() {
    std::vector < std::string> collection;
    std::vector <std::string> Groups;

    std::ifstream aocInput;
    aocInput.open("C:\\Users\\j_cha\\Downloads\\AOCDay3.txt");
    if (aocInput.fail())
    {
        std::cout << "Failed to open file \n";
        std::exit(-1);
    }
    std::string line;
    std::string line2;
    std::string line3;
    while (aocInput >> line >> line2 >> line3)
    {
        std::cout << line << '\n' <<  line2 << '\n' << line3 << '\n';
        CheckCommonElement(line, line2, line3, commonItem);
    }
    int sum = 0;
    for (int i = 0; i < commonItem.size(); i++)
        sum += ItemPriority[commonItem[i]];
    std::cout << sum;
}


int main()
{
    //Day3SolutionPart1();
    Day3SolutionPart2();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
