# Sensor Network Simulation

This project simulates a sensor network consisting of multiple sensors publishing data to a main node. The main node stores the data in a circular buffer and notifies clients at regular intervals.

## Features

- Simulates multiple sensors running in separate threads
- Main node stores sensor data in a circular buffer
- Clients are notified about new sensor data at regular intervals
- Supports different types of sensor messages

## Usage

The application takes three command-line arguments: client size, buffer size, and sensor size. For example, you can run the application with a client size of 2, a buffer size of 5, and a sensor size of 2 like this:

```bash
./SensorNetwork 2 5 2
```

This will run the app and print info about gathered data for the clients from different sensors.
Note that sensors will run in loop so press `ctrl + c` to kill the app.

## Build Instructions

This project uses CMake as its build system. To build the project, follow these steps:

1. Install CMake and a C++ compiler if you haven't already.

2. Open a terminal and navigate to the project directory.

3. Create a new directory for the build:

```bash
mkdir build
cd build
```

4. Run CMake to generate the build files:

```bash
cmake ..
```

5. Build the project:

```bash
make
```

This will create an executable named `SensorNetwork` in the `build` directory.


### Build with Conan

You can also use conan to install all the nessesary dependencies:

Configure conan if you haven't already

```bash
conan profile detect --force
```
Install deps

```bash
conan install . --build=missing
```

Run CMake

```bash
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
make
```

Note: path to the `conan_toolchain.cmake` could be `Release/generators/conan_toolchain.cmake`


