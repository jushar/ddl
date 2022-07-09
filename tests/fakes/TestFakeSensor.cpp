#include "catch2/catch_approx.hpp"
#include "catch2/catch_test_macros.hpp"
#include "ddl/fakes/FakeSensor.hpp"

SCENARIO("fake sensors") {
  GIVEN("a fake sensor") {
    ddl::FakeSensor sensor{};

    WHEN("it is initialized") {
      THEN("it should return the 0 for all channels") {
        REQUIRE(sensor.readValue(ddl::SensorChannel::Channel1) == Catch::Approx{0.0f});
        REQUIRE(sensor.readValue(ddl::SensorChannel::Channel2) == Catch::Approx{0.0f});
        REQUIRE(sensor.readValue(ddl::SensorChannel::AxisX) == Catch::Approx{0.0f});
      }
    }

    WHEN("a value is simulated on a single channel") {
      sensor.simulateValue(ddl::SensorChannel::Channel2, 10.0f);

      THEN("it should return the simulated value only for the channel") {
        REQUIRE(sensor.readValue(ddl::SensorChannel::Channel2) == Catch::Approx{10.0f});
        REQUIRE(sensor.readValue(ddl::SensorChannel::Channel1) == Catch::Approx{0.0f});
      }
    }
  }
}
