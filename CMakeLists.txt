cmake_minimum_required(VERSION 3.10)
project(DemoProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(demo
#    src/main.cpp
 #   src/Animal.cpp
 #   src/Dog.cpp
 #   src/Horse.cpp
 #   src/Duck.cpp
#)

#target_include_directories(demo PRIVATE include)

# --- 新增：单元测试支持 ---
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# 避免与主项目的运行时库设置冲突（MSVC 上很重要）
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 把原本 main() 之外的业务代码单独做成一个库，供测试和主程序共用
add_library(demo_lib
    src/Animal.cpp
  src/AnimalCreation.cpp
    src/Dog.cpp
    src/Horse.cpp
    src/Duck.cpp
    src/AnimalSoundIfElseChain.cpp
    src/AnimalSoundNested.cpp
    src/ProcessAnimalLargeMethod.cpp
    src/Machine.cpp
    src/Robot.cpp
    include/Robot.h
)
target_include_directories(demo_lib PUBLIC include)

add_executable(demo src/main.cpp)
target_link_libraries(demo PRIVATE demo_lib)

# 测试可执行文件
add_executable(unit_tests
    tests/AnimalTests.cpp
    tests/DogTests.cpp
    tests/DuckTests.cpp
    tests/HorseTests.cpp
)
target_link_libraries(unit_tests PRIVATE demo_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)
