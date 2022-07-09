#include <iostream>
#include <string_view>

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
  ddl::LPS22DF& pressure() override {
    static ddl::ST_I2C pressureI2c{ddl::I2CConfig{
        .address = 0x123,
    }};
    static ddl::LPS22DF lps22df{pressureI2c};
    return lps22df;
  }
};
// DEVICE DEFINITION FOR TARGET DEVICE END

// DEVICE DEFINITION FOR SIM DEVICE START
struct MySimulatedDevice : MyDevice {
  ddl::FakeSensor& pressure() override {
    static ddl::FakeSensor fakeSensor;
    return fakeSensor;
  }
};
// DEVICE DEFINITION FOR SIM DEVICE END

// TODO: Generate these definitions based on a declarative yaml file (similar to a device tree)

void printDeviceSensorValues(std::string_view name, MyDevice& device) {
  std::cout << "[" << name << "] " << "Read pressure: "
            << device.pressure().readValue(ddl::SensorChannel::Default)
            << "\n";
}

int main() {
  MyTargetDevice targetDevice;
  printDeviceSensorValues("Target", targetDevice);

  MySimulatedDevice simDevice;
  simDevice.pressure().simulateValue(ddl::SensorChannel::Default, 10.0f);
  printDeviceSensorValues("Sim", simDevice);
}
