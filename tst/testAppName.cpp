#include "gtest/gtest.h"
#include "..\Arguments.h"


TEST(Arguments_AppName, AppName_EQ)
{
	char *arg1[3] = {(char*) "comm1", (char*) "comm2", (char*) "comm3"};
	Arguments args1(3,arg1);
	EXPECT_EQ ("comm1", args1.appName());
	char *arg2[3] = {(char*) "-05.2@5", (char*) "--%$2", (char*) "arg3"};
	Arguments args2(3,arg2);
	EXPECT_EQ ("-05.2@5", args2.appName());
} 

TEST(Arguments_AppName, AppName_NE)
{
	char *arg1[3] = {(char*) "co1", (char*) "comm2", (char*) "comm3"};
	Arguments args1(3,arg1);
	EXPECT_NE ("comm1", args1.appName());
	char *arg2[3] = {(char*) "-52@5", (char*) "--%$2", (char*) "arg3"};
	Arguments args2(3,arg2);
	EXPECT_NE ("-05.2@5", args2.appName());
} 











