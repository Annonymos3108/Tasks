#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::ostream& operator<< (std::ostream& os, std::vector<std::vector<std::string>> vvStrArr)
{
    os << "[";
    for (int i = 0; i < vvStrArr.size(); i++)
    {
        os << "[";
        for (int j = 0; j < vvStrArr[i].size(); j++)
            os << "\"" << vvStrArr[i][j] << "\"" << (j == vvStrArr[i][j].size() - 1 ? "" : ", ");
        os << "], ";
    }
    os << "]";
    return os;
}

bool isContainsCommonLetters (std::string strA, std::string strB)
{
    std::vector<bool> stat;
    if (strA.size() == strB.size())
    {        
        for (int i = 0; i < strA.size(); i++) 
        {
            //find(strA.begin(), strA.end(), strB[i]) != strA.end()) -> strA contains strB[i]
            if (strA.find(strB[i]) != std::string::npos)
                stat.push_back(true);           
            else
                stat.push_back(false);
        }
        if (std::find(stat.begin(), stat.end(), false) != stat.end())
            return false;
        else 
            return true;
        
    }
    else
        return false;
}

//std::vector<std::vector<std::string>> 
auto commonLetters(std::vector<std::string> arr)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> temp;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++) 
        {
            if (isContainsCommonLetters(arr[i], arr[j])) 
            {
                //проверить есть ли уже данные слова в result в виде string in vector
                //if true, break
                for (int k = 0; k < result.size(); k++)
                {
                    for (int l = 0; l < result[k].size(); l++) 
                    {
                        if (result[k][l].find(arr[i]) != std::string::npos)
                        //break цикл j
                    }
                   
                }

                temp.push_back(arr[j]);
                
                
                if (std::find(temp.begin(), temp.end(), arr[i]) == temp.end())
                    temp.push_back(arr[i]);
            }  
        }
        if (temp.empty())
            temp.push_back(arr[i]);
        
        result.push_back(temp);
        temp.clear();
    }

    return result;
}


int main() 
{
    std::vector<std::string> arr = {"eat", "tea", "tan", "ate", "nat", "bat"};
    //сгруппировать слова по "общим буквам".  
    std::cout << commonLetters(arr) <<std::endl;
    return 0;
}
