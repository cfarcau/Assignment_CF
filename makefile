
CPPTOOL = g++
CPPFLAGS = -Wall -Iinc

RM = rm

CPP = $(CPPTOOL) $(CPPFLAGS)
LINK = $(CPPTOOL) -o


GTEST_DIR=C:\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include

LIB=Arguments.h

TEST_OBJ=\
	tst\testAppName.o \
	tst\testException.o \
	tst\testCount.o \
	tst\testCopy.o \
	tst\testAssign.o

all: main.exe testArg.exe

main.exe: main.o Arguments.o
	$(LINK) main.exe main.o Arguments.o

testArg.exe: $(TEST_OBJ) Arguments.o $(GTEST_LIB)
	$(LINK) testArg.exe $(TEST_OBJ) Arguments.o $(GTEST_LIB)

Arguments.o: Arguments.cpp $(LIB)
	$(CPP) -o Arguments.o -c Arguments.cpp

tst\testAppName.o: tst\testAppName.cpp $(LIB)	
	$(CPP) $(GTEST_INC) -o tst\testAppName.o -c tst\testAppName.cpp
tst\testException.o: tst\testException.cpp $(LIB)	
	$(CPP) $(GTEST_INC) -o tst\testException.o -c tst\testException.cpp	
tst\testCount.o: tst\testCount.cpp $(LIB)	
	$(CPP) $(GTEST_INC) -o tst\testCount.o -c tst\testCount.cpp
tst\testCopy.o: tst\testCopy.cpp $(LIB)	
	$(CPP) $(GTEST_INC) -o tst\testCopy.o -c tst\testCopy.cpp
tst\testAssign.o: tst\testAssign.cpp $(LIB)	
	$(CPP) $(GTEST_INC) -o tst\testAssign.o -c tst\testAssign.cpp
	
main: main.exe
	main.exe

test: testArg.exe
	testArg.exe
	
clean:
	$(RM) Arguments.o
	$(RM) $(TEST_OBJ)
	$(RM) main.o
	$(RM) main.exe
	$(RM) testArg.exe
