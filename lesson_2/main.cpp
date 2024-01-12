#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

struct IpAddress
{
    std::vector<unsigned int> bytes;

    void parseFromString(const std::string& str)
    {
        std::istringstream iss(str);
        std::string byteStr;

        while (std::getline(iss, byteStr, '.'))
        {
            unsigned int byte = std::stoi(byteStr);
            bytes.push_back(byte);
        }
    }

    bool operator<(const IpAddress& other) const
    {
        for (size_t i = 0; i < bytes.size(); ++i)
        {
            if (bytes[i] > other.bytes[i])
                return true;
            else if (bytes[i] < other.bytes[i])
                return false;
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const IpAddress& ip)
    {
        for (size_t i = 0; i < ip.bytes.size(); ++i)
        {
            os << ip.bytes[i];
            if (i < ip.bytes.size() - 1) os << ".";
        }
        return os;
    }
};

int main(int argc, char const *argv[])
{

    std::vector<IpAddress> ipAddresses;
    std::string line;

    // Чтение данных из стандартного ввода
    while (std::getline(std::cin, line))
    {
        IpAddress ipAddress;
        ipAddress.parseFromString(line);
        ipAddresses.push_back(ipAddress);
    }

    // Сортировка в обратном лексикографическом порядке
    std::sort(ipAddresses.rbegin(), ipAddresses.rend());

    // Вывод полного списка адресов после сортировки
    for (const auto& ipAddress : ipAddresses)
    {
        std::cout << ipAddress << std::endl;
    }
    std::cout << std::endl;

    // Вывод адресов, первый байт которых равен 1
    for (const auto& ipAddress : ipAddresses)
    {
        if (ipAddress.bytes[0] == 1)
            std::cout << ipAddress << std::endl;
    }
    std::cout << std::endl;

    // Вывод адресов, первый байт которых равен 46, а второй 70
    for (const auto& ipAddress : ipAddresses)
    {
        if (ipAddress.bytes[0] == 46 && ipAddress.bytes[1] == 70)
            std::cout << ipAddress << std::endl;
    }
    std::cout << std::endl;

    // Вывод адресов, любой байт которых равен 46
    for (const auto& ipAddress : ipAddresses)
    {
        if (std::find(ipAddress.bytes.begin(), ipAddress.bytes.end(), 46) != ipAddress.bytes.end())
            std::cout << ipAddress << std::endl;
    }

    return 0;
}





