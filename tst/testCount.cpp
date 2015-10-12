#include "gtest/gtest.h"
#include "..\Arguments.h"


TEST(Arguments_Count, count)
{
	char *arg1[3] = {(char*) "comm1", (char*) "comm2", (char*) "comm3"};
	Arguments args1(3,arg1);
	EXPECT_EQ (2, args1.count());
	
	char *arg2[3] = {(char*) "comm1", (char*) "comm2", (char*) "comm3"};
	Arguments args2(3,arg2);
	EXPECT_NE (3, args2.count());
	
	char *arg3[2] = {(char*) "comm1", (char*) "comm2"};
	Arguments args3(2,arg3);
	EXPECT_EQ (1, args3.count());
	
	char *arg4[0] = {};
	Arguments args4(0,arg4);
	EXPECT_EQ (0, args4.count());
} 

