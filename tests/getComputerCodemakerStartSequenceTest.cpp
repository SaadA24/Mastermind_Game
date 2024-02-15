#include <gtest/gtest.h>
#include "D:/Projects/vscode/backups/MasterMind_Game/src/model/GetComputerStartingSequence.cpp"

TEST(myfunctions, add)
{
    GTEST_ASSERT_EQ(add(10, 22), 32);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}