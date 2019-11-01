#include <iostream>
#include <climits>
#include <cmath>
#include <exception>
#include <string>
#include <sstream>
#include "RandomEngine.h"

const char nl = '\n';

inline std::string BuildWithSource
	(  std::string const& msg
	 , const char* file
	 , int line
	 , const char* func
	)
{
	std::stringstream what;
	what << msg << ' ' << file << ':' << line << '@' << func;

	return what.str();
}

struct MyOverFlowException : std::overflow_error {
	MyOverFlowException
		(  std::string const& msg
		 , const char* file
		 , int line
		 , const char* func
		)
	: std::overflow_error(BuildWithSource(msg, file, line, func))
	{}
};

int multiply(int a, int b) {
    if( !a || !b){
        return 0;
    }

    if(a > INT_MAX / b){
        std::cerr << "a = " << a << nl;
        std::cerr << "b = " << b << nl;

        throw MyOverFlowException("overflow", __FILE__, __LINE__, __FUNCTION__);

        //~ std::string msg = "overflow error: ";
        //~ std::string fname = "multiply";
        //~ throw std::overflow_error(msg+fname);
    }

    return a * b;
}


int* buildVector(long n) throw(std::bad_alloc, std::overflow_error)
{
    if(n < 1){
        throw std::invalid_argument("buildVector: arg must be > 1");
//        throw my::InvalidArgsException("big num", __FILE__, __LINE__, __FUNCTION__);
//        throw Exception(my::InvalidArgsException, "big num");
    }

    int *v = new int[n];

    RandomEngine<int> randomEngine(0, INT_MAX/1000);

    long i = 0, tries = 0;
    while( i < n)
    {
        const int a = randomEngine.get();
        const int b = randomEngine.get();
        try {
            ++tries;
            v[i] = multiply(a, b);
            ++i;
        } catch(std::overflow_error const& e){
			std::cerr << "got " << e.what() << ", skipping\n";
            //~ throw;
		}
    }

    std::cout << "Tries: " << tries << " For " << n << nl;
    return v;
}


void testRandom(){
    RandomEngine<int> re(0, INT_MAX/1000);

    std::cout << re.get() << nl;
    std::cout << re.get() << nl;
}

int main() {
    const long n = 32; // INT_MAX * 1L;
    //~ testRandom();

    try {
        int *v = buildVector(n);

        std::cout << v[0];
        for (int i = 1; i < n; ++i) {
            std::cout << ", " << v[i];
        }
        std::cout << nl;
    }catch(std::bad_alloc const& x){
        std::cerr << "No such memory!";
    }catch(std::overflow_error const& x){
        std::cerr << x.what() << nl;
    }

    return 0;
}
