#include <iostream>
#include <vector>
#pragma warning(push)
#pragma warning(disable:4819)
#include <boost/date_time/posix_time/posix_time.hpp>
#pragma warning(pop)
using namespace std;
 
vector<std::string> doubleValues (const vector<std::string>& v)
{
    vector<std::string> new_values;
	new_values.reserve( v.size() );
    for (auto itr = new_values.begin(), end_itr = new_values.end(); itr != end_itr; ++itr )
    {
        new_values.push_back( *itr );
    }
	std::cout << "start: " << boost::posix_time::to_simple_string(boost::posix_time::microsec_clock::local_time());
	std::cout << "\n";
    return new_values;
}
 
int main()
{
	size_t size = 1000000;
    vector<std::string> v(size);
	for(auto iter = v.begin(); iter != v.end(); iter ++)
	{
		*iter = "Hello world.";
	}
	
    vector<std::string> v2 = doubleValues( v );
	
	std::cout << "stop: " << boost::posix_time::to_simple_string(boost::posix_time::microsec_clock::local_time());
}