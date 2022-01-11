#include <iostream>
#include <vector>


std::ostream& operator<< (std::ostream& os, std::vector<int> vIntArr)
{
    os << "[";
    for (int i=0; i < vIntArr.size(); i++)
    {
        os << vIntArr[i] << (i == vIntArr.size() - 1 ? "" : ", ");
    }
    os << "]";
    return os;
}


std::vector<int> intersection(std::vector<int> arrA, std::vector<int> arrB)
{
    std::vector<int> temp;
    for (int i = 0; i < arrA.size(); i++) 
    {
        for (int j = 0; j < arrB.size(); j++) 
        {
            if (arrA[i] == arrB[j])
            {
                temp.push_back(arrA[i]);
                break;           
            }
        }
    }
    return temp;
}


int main() 
{
    std::vector<int> arrA = {1, 2, 3, 2, 0};
    std::vector<int> arrB = {5, 1, 2, 7, 3, 2};
    //вернуть их пересечение [1, 2, 2, 3] (порядок неважен)   
    std::cout << intersection(arrA, arrB) <<std::endl;
    return 0;
}
