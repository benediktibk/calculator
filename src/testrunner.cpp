#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>

using namespace CPPUNIT_NS;
using namespace std;

int main (int, char**)
{
	 TestResult testresult;
	 TestResultCollector collectedresults;
	 BriefTestProgressListener progress;
	 TestRunner testrunner;
	 CompilerOutputter compileroutputter (&collectedresults, cerr);

	 testresult.addListener(&collectedresults);
	 testresult.addListener(&progress);
	 testrunner.addTest(TestFactoryRegistry::getRegistry().makeTest());
	 testrunner.run(testresult);
	 compileroutputter.write ();

	 return collectedresults.wasSuccessful () ? 0 : 1;
}
