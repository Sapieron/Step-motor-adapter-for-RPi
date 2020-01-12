# Step-motor-adapter-for-RPi
Step motor adapter for RPi-standard minicomputers

#Tools used
TODO ADD LINKS DOWN HERE
-Visual Studio Code (IDE)
-Embedded C++17
-Embedded C11
-Google Test
-CMake (build tool)
-Ninja (generator)
-ARM GNU Embedded Toolchain(GCC, GPP and ASM compilers)
-CppCheck to check compliance with MISRA

Extensions used for VSCode:
-CMake tools
-GoogleTest Adapter
-ARM [ARM support for Visual Studio Code]
-Cortex-Debug [Usage shown here https://marcelball.ca/projects/cortex-debug/cortex-debug-launch-configurations/]
-LinkerScript [adds GNU linker script support]

#Configuring the environment
In order to build the project

svd file for desired processor or rather use stcubemx to download latest
-opisac konkretne foldery, co zawierają i do czego te pliki służą
- in case of "Error: selected processor does not support ARM mode `wfi'" please reconfigure your project with CMake tool in VS Code (Ctrl+shift+P and select ,,CMake: Delete cache and reconfigure)
- during instalation set ,,add to path variable"