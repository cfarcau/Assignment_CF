
#include "Arguments.h"
#include <iostream>

using namespace std;

Arguments::Arguments(int argc, char* argv[])
{
    try
    {
        if ( argc < 0 || argv == 0 )
        {
            throw argc;
        }
        else
        {
            /// todo: Set app to be the first item from argv
			app = argv[0];
			
            /// todo: Save the remaining from argv into the args vector (push_back)
			for (int i = 1; i < argc; i++)
			{
				args.push_back(argv[i]);
			}
        }
    }
    catch (int e)
    {
        cerr << "error: constructing argument object..." << endl;
        throw;
    }
}

// copy constructor
Arguments::Arguments(const Arguments& rhs):args(rhs.args), app(rhs.app)
{ /*cout << "copy constr Argum" << endl;*/}

// Array subscript operator
const string& Arguments::operator[](const size_t i) const 
{
    try
    {
        if ( i >= args.size() ) throw i;
    }
    catch(size_t e)
    {
        cerr << "error: index out of range " << e << endl;
        throw;
    }
    /// todo: return argument on index
	return args[i];
}

// Assignment operator
Arguments& Arguments::operator=(const Arguments& rhs)
{
	try 
	{
		if(this == &rhs)
		{
			throw "Throw error: identical objects given to Assign Oper";
		}
		else 
		{
			args = rhs.args;
			app = rhs.app;
			//cout << "Ok in Assig Oper" << endl; //
		}
	}
	catch (const char* msg)
	{
		cerr << msg << endl;
	}
	return *this;
}


int Arguments::count()
{
	return args.size(); // 'size' function returns size of the vector
}

string Arguments::appName() const 
{
	return app; 		// app = argv[0]
}