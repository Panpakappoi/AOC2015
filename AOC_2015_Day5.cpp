#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

// nice string is one with all the following properties
// contain atleast 3 vowels aeiou only 
// contains at least one letter that appears twice in a row like xx, dd, aa, bb , cc, dd
// does not contain ab cd pq or xy.
// regex patterns ("[aeiou].*[aeiou].*[aeiou]")
// regex pattern repeateadLetterRegex(R"((\w)\1)");
// rule 3 forbiddenStrings "(ab|cd|pq|xy)";

// part 2 contains a pair of any two letters that appears at least twice in the string without overlapping
// like xyxy (xy) or aabcdefgaa (aa) but not like aaa.

// it contains at least one letter which repeats with exactly one letter in between them.

bool validateString_Part2(const std::string& str)
{
    std::regex repeat_without_overlap_pattern(R"((\w\w).*\1)");
    if (!std::regex_search(str, repeat_without_overlap_pattern))
        return false;

    std::regex oneletterbetweenPattern(R"((\w)\w\1)");
    if (!std::regex_search(str, oneletterbetweenPattern))
        return false;
    return true;
}




bool validateString(const std::string& str)
{
    std::regex vowelPattern("[aeiou].*[aeiou].*[aeiou].*");
    if (!std::regex_search(str, vowelPattern))
        return false;
    std::regex repeatPattern(R"((\w)\1)");
    if (!std::regex_search(str, repeatPattern))
        return false;
    std::regex forbiddenStrings("(ab|cd|pq|xy)");
    if (std::regex_search(str, forbiddenStrings))
        return false;

    return true;
}

int calculateNiceString(const std::vector<std::string> &strlist) {
    int nice_count = 0;
    for (size_t i = 0; i < strlist.size(); i++)
    {
        if (validateString(strlist[i]))
            nice_count++;
    }
    return nice_count;
}

int calculateNiceString_Part2(const std::vector<std::string>& strlist)
{
    int nice_count = 0;
    for (size_t i = 0; i < strlist.size(); i++)
    {
        if (validateString_Part2(strlist[i]))
            nice_count++;
    }
    return nice_count;
}



std::vector<std::string> processInput (){
    std::ifstream aocInput;
    aocInput.open("AOCDay5Input.txt");
    if (aocInput.fail()) {
        std::cout << "Failed to open file :\n";
        std::exit(-1);
    }
    std::vector<std::string> naughty_nice;
    std::string line;
    while (std::getline(aocInput, line))
    {
        naughty_nice.emplace_back(line);
    }
    return naughty_nice;
}

int main()
{
    auto naughty_nice = processInput();
    for (size_t i = 0; i < naughty_nice.size(); i++)
        std::cout << naughty_nice[i] << '\n';
    std::cout << calculateNiceString(naughty_nice) << '\n';
    std::cout << calculateNiceString_Part2(naughty_nice) << '\n';
}
