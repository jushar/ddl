enable_testing()

add_executable(ddl_tests
    "fakes/TestFakeSensor.cpp"
)
target_link_libraries(ddl_tests Catch2::Catch2WithMain ddl ddl_fakes)
