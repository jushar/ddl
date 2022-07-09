# ddl
PoC for a Clean Code driver library for embedded systems.

## Design Goals
- Extensibility: It should be easy to add new drivers
- Portability: It should be possible to re-use drivers without any modifications for all embedded devices (independent of pin configurations)
- Testability
  - Drivers and fake drivers should be testable
  - The integrating system should be testable (i.e. drivers being replaceable with fake implementations)
