#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

struct position {
    int x;
    int y;

    bool operator<(const position& rhs) const
    {
        if (x != rhs.x)
        {
            return x < rhs.x;
        }
        else
            return y < rhs.y;
    }

    bool operator==(const position& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
   
};

std::vector<std::string> process_Input() {
    std::vector<std::string> directions;
    std::ifstream aocInput;
    aocInput.open("AocDay3.txt");
    if (aocInput.fail())
    {
        std::cout << "Failed to open file\n";
        std::exit(-1);
    }
    std::string line;
    while (std::getline(aocInput, line))
    {
        directions.emplace_back(line);
    }
    return directions;
}

void followDirections(position& santa, std::set<position>& visited, 
    std::vector<std::string>& directions)
{
    for (auto i = 0; i < directions.size(); i++)
    {
        for (auto j = 0; j < directions[i].size(); j++)
        {
            if (directions[i][j] == '^')
            {
                santa.y += 1;
            }
            else if (directions[i][j] == 'v')
            {
                santa.y -= 1;
            }
            else if (directions[i][j] == '>')
            {
                santa.x += 1;
            }
            else if (directions[i][j] == '<')
            {
                santa.x -= 1;
            }
            visited.insert(santa);
        }
    }
}

void roboSanta(position& santa, position& robosanta,
    std::set<position>& visited, std::vector<std::string>& directions)
{
    for (auto i = 0; i < directions.size(); i++)
    {
        for (auto j = 0; j < directions[i].size(); j++)
        {
            if (directions[i][j] == '^' && j % 2 == 0)
            {
                santa.y += 1;
            }
            else if (directions[i][j] == 'v' && j % 2 == 0)
            {
                santa.y -= 1;
            }
            else if (directions[i][j] == '>' && j % 2 == 0)
            {
                santa.x += 1;
            }
            else if (directions[i][j] == '<' && j % 2 == 0)
            {
                santa.x -= 1;
            }

            if (directions[i][j] == '^' && j % 2 != 0)
            {
                robosanta.y += 1;
            }
            else if (directions[i][j] == 'v' && j % 2 != 0)
            {
                robosanta.y -= 1;
            }
            else if (directions[i][j] == '>' && j % 2 != 0)
            {
                robosanta.x += 1;
            }
            else if (directions[i][j] == '<' && j % 2 != 0)
            {
                robosanta.x -= 1;
            }
            visited.insert(santa);
            visited.insert(robosanta);
        }
    }
}



int main()
{
    std::set<position> visited;
    std::vector<std::string> directions = process_Input();
    position santa_visit = { 0, 0 };
    visited.insert(santa_visit);
    position robo_santa = { 0,0 };
    roboSanta(santa_visit, robo_santa, visited, directions);
    for (auto& element : visited)
    {
        std::cout << element.x << " " << element.y << '\n';
    }
    std::cout << visited.size();
}

