add_library(ddl_fakes STATIC
    "FakeSensor.cpp"
)
target_link_libraries(ddl_fakes PRIVATE ddl)
