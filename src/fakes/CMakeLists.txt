add_library(ddl_fakes STATIC
    "FakeFlash.cpp"
    "FakeSensor.cpp"
)
target_link_libraries(ddl_fakes PRIVATE ddl)
