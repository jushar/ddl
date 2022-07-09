#include <iostream>

#include "ddl/drivers/LPS22DF.hpp"
#include "ddl/drivers/ST/ST_I2C.hpp"
#include "ddl/fakes/FakeSensor.hpp"

// DEVICE INTERFACE START
struct MyDevice {
  virtual ddl::Sensor& pressure() = 0;
};
// DEVICE INTERFACE END

// DEVICE DEFINITION FOR TARGET DEVICE START
struct MyTargetDevice : MyDevice {
  static ddl::LPS22DF& lps22Df() {
    static ddl::ST_I2C pressureI2c{ddl::I2CConfig{
        .address = 0x123,
    }};
    static ddl::LPS22DF lps22df{pressureI2c};
    return lps22df;
  }

  ddl::Sensor& pressure() override { return lps22Df(); }
};
// DEVICE DEFINITION FOR TARGET DEVICE END

// DEVICE DEFINITION FOR SIM DEVICE START
struct MySimulatedDevice : MyDevice {
  static ddl::FakeSensor& fakePressureSensor() {
    static ddl::FakeSensor fakeSensor;
    return fakeSensor;
  }

  ddl::Sensor& pressure() override { return fakePressureSensor(); }
};
// DEVICE DEFINITION FOR SIM DEVICE END

// TODO: Generate these definitions based on a declarative yaml file (similar to a device tree)

int main() {
  MyTargetDevice targetDevice;
  std::cout << "Read target pressure sensor: " << targetDevice.pressure().readValue(ddl::SensorChannel::Default)
            << "\n";

  MySimulatedDevice simDevice;
  simDevice.fakePressureSensor().simulateValue(ddl::SensorChannel::Default, 10.0f);
  std::cout << "Read simulated pressure sensor: " << simDevice.pressure().readValue(ddl::SensorChannel::Default)
            << "\n";
}
