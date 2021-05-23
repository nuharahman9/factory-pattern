CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(calculator
	main.cpp
)

ADD_EXECUTABLE(test
        unit_test.cpp
        test.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

