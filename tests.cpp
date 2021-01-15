#include "gtest/gtest.h"
#include "base64.h"
#include <string>
using namespace std;


TEST(tested, t1)
{
    string input = "Im not a chiken";
    string result = Encode(input);
    ASSERT_EQ(result, "SW0gbm90IGEgY2hpa2Vu");
}

TEST(tested, t2)
{
    string input = "string result = Encode(input);";
    string result = Encode(input);
    ASSERT_EQ(result, "c3RyaW5nIHJlc3VsdCA9IEVuY29kZShpbnB1dCk7");
}

TEST(tested, t3)
{
    string input = "c3RyaW5nIHJlc3VsdCA9IEVuY29kZShpbnB1dCk7";
    string result = Decode(input);
    ASSERT_EQ(result, "string result = Encode(input);");
}

TEST(tested, t4)
{
    string input = "SW0gbm90IGEgY2hpa2Vu";
    string result = Decode(input);
    ASSERT_EQ(result, "Im not a chiken");
}

TEST(tested, t5)
{
    string input = "That is not fair when you often waste you time on assamler";
    string result = Encode(input);
    ASSERT_EQ(result, "VGhhdCBpcyBub3QgZmFpciB3aGVuIHlvdSBvZnRlbiB3YXN0ZSB5b3UgdGltZSBvbiBhc3NhbWxlcg==");
}

TEST(tested, t6)
{
    string input = "RG9udCBiZSBzbyBwYXRpZW50";
    string result = Decode(input);
    ASSERT_EQ(result, "Dont be so patient");
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}