# CMake generated Testfile for 
# Source directory: /home/mavolio/RayTracer
# Build directory: /home/mavolio/RayTracer/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(MyTest "/home/mavolio/RayTracer/build/test/Test")
set_tests_properties(MyTest PROPERTIES  _BACKTRACE_TRIPLES "/home/mavolio/RayTracer/CMakeLists.txt;6;add_test;/home/mavolio/RayTracer/CMakeLists.txt;0;")
subdirs("src")
subdirs("test")