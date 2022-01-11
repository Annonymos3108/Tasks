#include <iostream>

std::string reverseString(std::string str)
{
    std::string temp = "";
    for (int i = str.length(); i >= 0; i--)
    {
        temp += str[i];
    }
    return temp;
}

int main() 
{
    std::string loremIpsum = "Lorem ipsum dolor sit amet.";
    std::cout << reverseString(loremIpsum) <<std::endl;
    return 0;
}
