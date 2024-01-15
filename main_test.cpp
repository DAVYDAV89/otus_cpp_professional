#include "ipAddres.h"
#include "gtest/gtest.h"

TEST(IpAddressTest, ParseFromString)
{
    IpAddress ip;
    ip.parseFromString("192.168.0.1");
    EXPECT_EQ(ip.bytes[0], 192);
    EXPECT_EQ(ip.bytes[1], 168);
    EXPECT_EQ(ip.bytes[2], 0);
    EXPECT_EQ(ip.bytes[3], 1);
}

//TEST(IpAddressTest, OperatorLessThan)
//{
//    IpAddress ip1;
//    ip1.parseFromString("192.168.0.1");
//    IpAddress ip2;
//    ip2.parseFromString("192.168.0.2");
//    EXPECT_TRUE(ip1 < ip2);
//    EXPECT_FALSE(ip2 < ip1);
//}

TEST(IpAddressTest, OperatorGreaterThan)
{
    IpAddress ip1; ip1.parseFromString("192.168.0.1");
    IpAddress ip2; ip2.parseFromString("192.168.0.2");
    EXPECT_TRUE(ip2 > ip1);
    EXPECT_FALSE(ip1 > ip2);
}

TEST(IpAddressTest, OperatorEqual)
{
    IpAddress ip1; ip1.parseFromString("192.168.0.1");
    IpAddress ip2; ip2.parseFromString("192.168.0.1");
    EXPECT_TRUE(ip1 == ip2);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
