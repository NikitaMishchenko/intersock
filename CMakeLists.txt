cmake_minimum_required(VERSION 3.0.0)
project(socket_test VERSION 0.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include(CTest)

#enable_testing()

include_directories (src/)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")


add_executable(socket_test
              ./src/main.cpp
)
set_target_properties(socket_test PROPERTIES LINKER_LANGUAGE CXX)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# sudo apt-get install libgsl-dev libgsl-dev libboost-dev
# libgtest-dev /usr/src/gtest make it
# sudo apt install libgnuplot-iostream-dev
target_link_libraries(socket_test
                      libboost_program_options.a
)

add_executable(runTests tests/main.cpp tests/test.cpp)
target_link_libraries(runTests
                     ${GTEST_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#TESTS


#add_executable(tests tests/tests.cpp)
#target_link_libraries(tests PRIVATE tests)

#add_test(
#  NAME tests
#  COMMAND $<TARGET_FILE:tests>
#  )