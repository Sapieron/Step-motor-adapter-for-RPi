# Step motor adapter for RPi
Step motor adapter for RPi-standard minicomputers
## Brief
The purpose of this project is to control 3 step motors and 1 gripper (or any other on-off device) with simple commands sent through UART interface.

This project is a part of engineering thesis developed by [Paweł Klisz](https://pl.linkedin.com/in/pawel-klisz) for Wyższa Szkoła Techniczna in Katowice, Poland.
## Software development
To develop firmware for this project following tools were used:
- [Visual Studio Code (IDE)](https://code.visualstudio.com/) - version 1.43.2
- Embedded C++20
- Embedded C18
- [GoogleTest](https://github.com/google/googletest) - version 1.10.x
- [CMake](https://cmake.org/) - version 3.16.2
- [Ninja](https://ninja-build.org/)
- [ARM GNU Embedded Toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) (GCC, GXX and ASM compilers) - GNU version 9.2.1
- [Segger J-Link EDU](https://www.segger.com/products/debug-probes/j-link/models/j-link-edu/) for debugging
#### Extensions used for Visual Studio Code IDE:
- [CMake tools](https://marketplace.visualstudio.com/items?itemName=twxs.cmake) - provides support for CMake in VSCode
- [GoogleTest Adapter](https://marketplace.visualstudio.com/items?itemName=DavidSchuldenfrei.gtest-adapter) - user-friendly presentation of unit test results
- [ARM](https://marketplace.visualstudio.com/items?itemName=dan-c-underwood.arm) - ARM syntax highlighting for VSCode
- [Cortex-Debug](https://marcelball.ca/projects/cortex-debug/cortex-debug-launch-configurations) - adds debugging capability of ARM devices in VSCode
- [LinkerScript](https://marketplace.visualstudio.com/items?itemName=amapleaf.linker-script) - adds GNU linker script support
- [DoxyGen Documentation Generator](https://marketplace.visualstudio.com/items?itemName=cschlosser.doxdocgen) - autocompletes doxygen templates, in order to speed up the documentation creation, in more user-friendly way
## Hardware development
Custom board was developed for this project. Following tools were used:
- [Altium Designer](https://www.altium.com/altium-designer/) 18.1
## TODO:
- change assembler startup file to cpp files contained in target/micro
- cleanup ,,drivers''
- create DoxyGen documentation and create UML diagrams / write something about architecture
- integrate CppCheck to check compliance with MISRA
- Add photos to this file

## Books / resources 
I'd like to list resources that helped me developing that board:
- ,,Real Time C++", Christopher Kormanyos 
- ,,Test-Driven Development for Embedded C", James W. Grenning
- ,,Making Embedded Systems", Elecia White
- [PW-Sat2](https://github.com/PW-Sat2) - polish students' satelite
- ,,Clean code", Robert C. Martin