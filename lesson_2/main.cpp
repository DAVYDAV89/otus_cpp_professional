#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

#include "ipAddres.h"

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





