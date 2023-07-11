// Aoc_2015_Day7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//123 -> x         d: 72    
//456->y           e: 507
//x AND y->d       f: 492
//x OR y->e        g: 114
//x LSHIFT 2->f    h: 65412
//y RSHIFT 2->g    i: 65079
//NOT x->h         x: 123
//NOT y->i         y: 456

// uns 16
// 0000_0000_0000_0000
// 0000_0000_0111_1011 X
// 0000_0001_1100_1000 Y
//
// 0000_0000_0100_1000 d
// 0000_0001_1111_1011 e

// 0000_0001_1110_1100  f

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <map>


void parse_start_wire(std::string& str, std::vector<std::string> start_gates) {
    auto first_gate = std::regex{ R"(^(\w+))" }; 
    auto match = std::smatch{};
    if (std::regex_search(str, match, first_gate))
    {
        if (match[1] != "NOT")
        {
            std::cout << match[1] << '\n';
            start_gates.emplace_back(match[1]);
        }
    }
}

void parse_Start_Gates(std::string& str)
{

    auto match = std::smatch{};
}

void parse_initialization(std::vector<std::string> &directions ){
    std::map<int, std::string> initializations;
    auto insert_value = std::regex{ R"(^(\d+)\s->\s(\w+))" };
    auto match = std::smatch{};
    for (size_t i = 0; i < directions.size(); i++) {
        if (std::regex_search(directions[i], match, insert_value))
        {
            std::cout << match[1] << ' ' << match[2];
            
        }
    }
}


std::vector<std::string> processInput() {
    std::ifstream aocInput;
    aocInput.open("AOCInputDay7.txt");
    std::string line;
    std::vector <std::string> directions;
    while (std::getline(aocInput,line)) {
        directions.emplace_back(line);
       }
    return directions;
}


int main()
{
    auto directions = processInput();
    for (size_t i = 0; i < directions.size(); i++)
        std::cout << directions[i] << '\n';
    std::vector<std::string> start_gates;

    for (size_t i = 0; i < directions.size(); i++)
    {
        parse_start_wire(directions[i], start_gates);
    }
   /* for (size_t i = 0; i < start_gates.size(); i++)
    {
        std::cout << start_gates[i] << '\n';
    }*/
    //auto value_map = 
    //for (auto i : value_map)
    //{
    //    std::cout << i.first << " " << i.second << '\n';
    //}
    parse_initialization(directions);
}

