#include "gtest/gtest.h"
#include "..\Arguments.h"


TEST(Arguments_Copy, Copy_Constructor)
{
	char *arg1[3] = {(char*) "comm1", (char*) "comm2", (char*) "comm3"};
	Arguments args1(3,arg1);
	Arguments args2(args1);
	EXPECT_EQ (true, args1.appName() == args2.appName());
	for (int i = 0; i < 2; i++)
	{
		EXPECT_EQ (true, args1[i] == args2[i]);
	};
}

TEST(Arguments_Copy, Copy_Constr)
{
	char *arg1[3] = {(char*) "comm1", (char*) "comm2", (char*) "co2342342343432tcwetrcwetrcwetrcmm3"};
	Arguments args1(3,arg1);
	Arguments args2(args1);
	EXPECT_EQ (true, args1.appName() == args2.appName());
	for (int i = 0; i < 2; i++)
	{
		EXPECT_EQ (true, args1[i] == args2[i]);
	};
}


