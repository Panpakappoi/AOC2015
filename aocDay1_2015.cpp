#include <iostream>
#include <vector>
#include <string>
#include <fstream>


// (()) ()() floor 0
// ((( (()(()( both result in floor 3
// ))((((( floor 3
// ()) ))( floor -1 the first basement level
// ))) )())()) floor -3

int calculate_Floors_part_1(std::vector<std::string>& instructions)
{	
	int floor = 0;
	for (int i = 0; i < instructions.size(); i++)
		for (int j = 0; j < instructions[i].size(); j++)
		{
			if (instructions[i][j] == '(')
			{
				floor++;
			}
			else if(instructions[i][j] == ')')
			{
				floor--;
			}
		}
	return floor;
}

void calculate_Floors_part_2(std::vector<std::string>& instructions)
{
	int floor = 0;
	for (int i = 0; i < instructions.size(); i++) {
		for (int j = 0; j < instructions[i].size(); j++)
		{
			if (instructions[i][j] == '(')
			{
				floor++;
			}
			else if (instructions[i][j] == ')')
			{
				floor--;
			}
			if (floor == -1)
			{
				std::cout << "Where santa is in basement " <<  i << " " << j << '\n';
			}

		}
		std::cout << "size of vectors " << instructions[i].size() << '\n';
	}
}



std::vector<std::string> parseInput() {
	std::vector<std::string> instructions; 
	std::ifstream aocInput; 
	aocInput.open("aocDay1_input.txt");
	if (aocInput.fail())
	{
		std::cout << "Failed to open file\n";
		std::exit(-1);
	}
	std::string line;
	while (std::getline(aocInput, line));
	{
		instructions.emplace_back(line);
	}
	return instructions;
}

int main() {
	using namespace std::string_literals;

	auto instruction = parseInput();
	for (auto i = 0; i < instruction.size(); i++)
	{
		std::cout << instruction[i] << '\n';
	}
	auto last_floor = calculate_Floors_part_1(instruction);
	std::cout << last_floor;
	calculate_Floors_part_2(instruction);
}

