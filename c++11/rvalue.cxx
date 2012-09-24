#include <iostream>
#include <vector>
#pragma warning(push)
#pragma warning(disable:4819)
#include <boost/date_time/posix_time/posix_time.hpp>
#pragma warning(pop)
using namespace std;
 
vector<int>&& doubleValues (const vector<int>& v)
{
    vector<int> new_values( v.size() );
    for (auto itr = new_values.begin(), end_itr = new_values.end(); itr != end_itr; ++itr )
    {
        new_values.push_back( 2 * *itr );
    }
    return std::move(new_values);
}
 
int main()
{
    vector<int> v;
    for ( int i = 0; i < 100; i++ )
    {
        v.push_back( i );
    }
    v = doubleValues( v );
}