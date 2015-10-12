#include "gtest/gtest.h"
#include "..\Arguments.h"


TEST(Arguments_Assign, Assign_Operator)
{
	char *arg1[3] = {(char*) "comm1", (char*) "comm2", (char*) "comm3"};
	Arguments args1(3,arg1);
	char *arg2[3] = {(char*) "asdf1", (char*) "aser2", (char*) "as3ds"};
	Arguments args2(3,arg2);
	EXPECT_EQ (false, args1.appName() == args2.appName());
	EXPECT_EQ (true, args1.count() == args2.count());
	for (int i = 0; i < 2; i++)
	{
		EXPECT_EQ (false, args1[i] == args2[i]);
	};
}