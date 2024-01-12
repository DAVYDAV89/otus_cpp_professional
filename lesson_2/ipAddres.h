#include <vector>
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

    bool operator>(const IpAddress& other) const
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

    bool operator==(const IpAddress& other) const
    {
        return bytes == other.bytes;
    }
};

