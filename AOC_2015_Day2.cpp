#include <iostream>
#include <fstream>
#include <vector>
#include "stringHelper.h"
#include <sstream>
#include <algorithm>



struct Dimensions{
    int length;
    int width;
    int height;
};


template<class T>
T find_min(T x, T y)
{
    return (x < y) ? x : y;
}

std::pair<int, int> findTwoLowest(Dimensions& current)
{
    int lowest = find_min(current.length, find_min(current.width, current.height));
    int secondLowest;
    if (current.length == lowest)
    {
        secondLowest = find_min(current.width, current.height);
    }
    else if (current.width == lowest)
    {
        secondLowest = find_min(current.length, current.height);
    }
    else if (current.height == lowest)
    {
        secondLowest = find_min(current.length, current.width);
    }
    return std::make_pair(lowest, secondLowest);
}


int calculate_area(Dimensions& current)
{
    int area_1, area_2, area_3, area;
    area_1 = 2 * current.length * current.width;
    area_2 = 2 * current.width * current.height;
    area_3 = 2 * current.height * current.length;
    area = area_1 + area_2 + area_3 + find_min(area_1/2, find_min(area_2/2, area_3/2));
    return area;
}

int calculate_ribbon(Dimensions& current)
{
    auto pair = findTwoLowest(current);
    int ribbon_wrap, ribbon_bow;
    ribbon_wrap = pair.first + pair.first+ pair.second+ pair.second;
    ribbon_bow = current.length * current.width * current.height;
    int total_ribbon = ribbon_wrap + ribbon_bow;
    return total_ribbon;
}

std::regex pattern (R"((\d+)x(\d+)x(\d+))");
std::smatch regexMatch;


std::vector<Dimensions> processInput() {
    using namespace stringHelper;
    std::ifstream aocInput;
    aocInput.open("AocDay2_2015.txt");
    if (aocInput.fail())
    {
        std::cout << "Failed to open file\n";
        std::exit(-1);
    }
    std::vector<Dimensions> dimensions;
    std::string line;
    

    while (std::getline(aocInput,line))
    {
        Dimensions current;
        if (std::regex_search(line, regexMatch, pattern))
        {
            current.length = std::stoi(regexMatch[1]);
            current.width = std::stoi(regexMatch[2]);
            current.height = std::stoi(regexMatch[3]);
        }
        dimensions.emplace_back(current);
    }
    return dimensions;
}




int main()
{   
    using namespace stringHelper;
    auto packageDimensions = processInput();
    
    int totalFeet = 0;
    int ribbon = 0;
    for (auto i = 0; i < packageDimensions.size(); i++)
    {
        totalFeet += calculate_area(packageDimensions[i]);
        ribbon += calculate_ribbon(packageDimensions[i]);
    }

    std::cout << totalFeet << '\n' << ribbon;

}
