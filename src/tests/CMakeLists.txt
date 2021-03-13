add_executable(BaseConvertTest BaseConvertUnitTest.cc)
add_executable(SnowFlakeTest SnowFlakeUnitTest.cc)

set(UNITTEST_TARGETS BaseConvertTest SnowFlakeTest)

foreach(T ${UNITTEST_TARGETS})
    target_include_directories(${T} PRIVATE ../)
    target_link_libraries(${T} funcs GTest::gtest)
    gtest_discover_tests(${T})
endforeach()