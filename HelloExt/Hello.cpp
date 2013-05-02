#include <boost/python.hpp>
#include <boost/thread.hpp>
#include <boost/date_time.hpp>
#include <boost/random.hpp>
#include <boost/generator_iterator.hpp>
#include <iostream>

typedef boost::mt19937 RNGType;
RNGType rng;
boost::uniform_int<> one_to_six(1, 60);
boost::variate_generator<RNGType, boost::uniform_int<> > dice(rng,
			one_to_six);

void workerFunc() {
	std::cout << "Worker: running" << std::endl;

	// Pretend to do something useful...
	int a = dice();
	std::cout << "wait: " << a << " s\n";
	boost::posix_time::seconds workTime(a);
	boost::this_thread::sleep(workTime);

	std::cout << "Worker: finished " << a << " s" << std::endl;
}

using namespace boost::python;

char const* greet() {
	std::cout << "main: startup" << std::endl;

	for(int i = 0; i < 100; i++) {
		boost::thread workerThread(workerFunc);
	}

	std::cout << "main: waiting for thread" << std::endl;

	//workerThread.join();

	std::cout << "main: done" << std::endl;
	return "Hi there.";
}

BOOST_PYTHON_MODULE(foo)
{
	def("greet", greet);
}
