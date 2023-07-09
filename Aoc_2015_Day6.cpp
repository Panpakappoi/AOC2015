#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

const size_t grid_size{ 1000 };

void processDirections(std::string& str, std::vector<int8_t>& arr) {
    std::regex turn_on{ R"((turn\son)\s(\d+),(\d+)\sthrough\s(\d+),(\d+))" };
    auto match = std::smatch{};
    if (std::regex_search(str, match, turn_on))
    {   
        size_t start_x = std::stoi(match[2]);
        size_t start_y = std::stoi(match[3]);
        size_t end_x = std::stoi(match[4]);
        size_t end_y = std::stoi(match[5]);
        //std::cout << match[1] << ' ' << start_x << ' ' << start_y << ' ' << end_x << ' ' << end_y <<'\n';
        for (auto i = start_x; i <= end_x; i++)
            for (auto j = start_y; j <= end_y; j++)
            {
                auto index = i * grid_size + j;
                arr[index] = 1;
            }
    }

    std::regex turn_off{ R"((turn\soff)\s(\d+),(\d+)\sthrough\s(\d+),(\d+))" };
    if (std::regex_search(str, match, turn_off))
    {   
        size_t start_x = std::stoi(match[2]);
        size_t start_y = std::stoi(match[3]);
        size_t end_x = std::stoi(match[4]);
        size_t end_y = std::stoi(match[5]);
        //std::cout << match[1] << ' ' << start_x << ' ' << start_y << ' ' << end_x << ' ' << end_y << '\n';
        for (auto i = start_x; i <= end_x; i++)
            for (auto j = start_y; j <= end_y; j++)
            {
                auto index = i * grid_size + j;
                arr[index] = 0;
            }
    }
    std::regex toggle{ R"((toggle)\s(\d+),(\d+)\sthrough\s(\d+),(\d+))" };
    if (std::regex_search(str, match, toggle))
    {
        size_t start_x = std::stoi(match[2]);
        size_t start_y = std::stoi(match[3]);
        size_t end_x = std::stoi(match[4]);
        size_t end_y = std::stoi(match[5]);
        //std::cout << match[1] << ' ' << start_x << ' ' << start_y << ' ' << end_x << ' ' << end_y << '\n';
        for (auto i = start_x; i <= end_x; i++)
            for (auto j = start_y; j <= end_y; j++)
            {
                auto index = i * grid_size + j;
                if (arr[index] == 1)
                    arr[index] = 0;
                else if (arr[index] == 0)
                    arr[index] = 1;
            }
    }
}

void processDirections_Part2(std::string &str, std::vector<int8_t>& arr)
{
    std::regex turn_on{ R"((turn\son)\s(\d+),(\d+)\sthrough\s(\d+),(\d+))" };
    auto match = std::smatch{};
    if (std::regex_search(str, match, turn_on))
    {
        size_t start_x = std::stoi(match[2]);
        size_t start_y = std::stoi(match[3]);
        size_t end_x = std::stoi(match[4]);
        size_t end_y = std::stoi(match[5]);
        //std::cout << match[1] << ' ' << start_x << ' ' << start_y << ' ' << end_x << ' ' << end_y <<'\n';
        for (auto i = start_x; i <= end_x; i++)
            for (auto j = start_y; j <= end_y; j++)
            {
                auto index = i * grid_size + j;
                arr[index] += 1;
            }
    }

    std::regex turn_off{ R"((turn\soff)\s(\d+),(\d+)\sthrough\s(\d+),(\d+))" };
    if (std::regex_search(str, match, turn_off))
    {
        size_t start_x = std::stoi(match[2]);
        size_t start_y = std::stoi(match[3]);
        size_t end_x = std::stoi(match[4]);
        size_t end_y = std::stoi(match[5]);
        //std::cout << match[1] << ' ' << start_x << ' ' << start_y << ' ' << end_x << ' ' << end_y << '\n';
        for (auto i = start_x; i <= end_x; i++)
            for (auto j = start_y; j <= end_y; j++)
            {
                auto index = i * grid_size + j;
                if (arr[index] >= 1)
                    arr[index] --;
                else
                    arr[index] = 0;
            }
    }
    std::regex toggle{ R"((toggle)\s(\d+),(\d+)\sthrough\s(\d+),(\d+))" };
    if (std::regex_search(str, match, toggle))
    {
        size_t start_x = std::stoi(match[2]);
        size_t start_y = std::stoi(match[3]);
        size_t end_x = std::stoi(match[4]);
        size_t end_y = std::stoi(match[5]);
        //std::cout << match[1] << ' ' << start_x << ' ' << start_y << ' ' << end_x << ' ' << end_y << '\n';
        for (auto i = start_x; i <= end_x; i++)
            for (auto j = start_y; j <= end_y; j++)
            {
                auto index = i * grid_size + j;
                arr[index] += 2;
            }
    }
}

long long calculate_total_brightness(std::vector<int8_t>& arr)
{
    long long total_brightness = 0;
    for (size_t i = 0; i < grid_size; i++)
        for (size_t j = 0; j < grid_size; j++)
        {
            size_t index = i * grid_size + j;
            total_brightness += arr[index];
        }
    return total_brightness;
}

int calculate_light_on(std::vector<int8_t> &arr)
{
    int light_on = 0;
    for(size_t i = 0; i < grid_size; i++)
        for (size_t j = 0; j < grid_size; j++)
        {
            size_t index = i * grid_size + j;
            if (arr[index] == 1)
            {
                light_on++;
            }
        }
    return light_on;
}

std::vector<std::string> processInput() {
    std::ifstream aocInput;
    aocInput.open("aocDay6Input.txt");
    if (aocInput.fail())
    {
        std::cout << "Failed to open file:\n";
        std::exit(-1);
    }

    std::string line;
    std::vector<std::string> directions;
    while (std::getline(aocInput, line))
    {
        directions.emplace_back(line);
    }
    return directions;
}

void initialize_array(std::vector<int8_t>& arr)
{
    for (size_t i = 0; i < grid_size; i++) {
        for (size_t j = 0; j < grid_size; j++)
        {
            size_t index = i * grid_size + j;
            arr[index] = 0;
        }
    }
}

int main()
{
    std::vector<int8_t> arr(grid_size * grid_size);
    using namespace std::string_literals;
    auto directions = processInput();
    initialize_array(arr);
   
    for (int i = 0; i < directions.size(); i++)
    {
        processDirections_Part2(directions[i], arr);
    }
    std::cout << calculate_total_brightness(arr);
}
