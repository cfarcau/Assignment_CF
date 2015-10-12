#include "gtest/gtest.h"
#include "..\Arguments.h"


TEST(Arguments_Exception, Negative_argc)
{
	char *arg1[3] = {(char*) "comm1", (char*) "comm2", (char*) "comm3"};
	bool hasException = false;
	try
	{
			Arguments args1 (-1, arg1);
	}
	catch (int e)
	{
		hasException = true;
	}
	EXPECT_EQ(true, hasException);
} 

