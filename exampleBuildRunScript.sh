#!/bin/bash

# Set the exit code for this script
exitCode=0
buildStatus=0
testsStatus=0

#
# Run the make script in the UnitTest directory
#
echo ""
echo "Running make..."
echo ""
pushd ./ChronoExample > /dev/null

make
buildStatus=$?

popd > /dev/null
echo ""
echo "SUMMARY:"
echo "========"
echo ""
if [ $buildStatus == 0 ]; then
   echo "Build --- SUCCESSFUL."
else
   echo "Build --- FAILED."
fi


#
# Run the make script in the UnitTest directory
#
echo ""
echo ""
echo ""
echo ""
echo "Run the example...:"
echo "=================="
echo ""

if [ $buildStatus == 0 ]; then
  pushd ./bin > /dev/null
  ./chronoExample
  testsStatus=$?
  popd > /dev/null
fi
echo ""
echo ""
echo ""
echo ""


exit $exitCode
