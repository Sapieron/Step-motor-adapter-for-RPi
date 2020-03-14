# Step-motor-adapter-for-RPi
Step motor adapter for RPi-standard minicomputers

#Tools used
TODO ADD LINKS DOWN HERE
-Embedded C++
-Google Test
-CMake (build tool)
-Ninja (generator)
-ARM GNU Embedded Toolchain(C, CPP and ASM compilers)
-Visual Studio Code (IDE)
-SEGGER J-Link
Extensions used for VSCode:
-to
-do
-that
-list

TODO:
-change assembler startup file to cpp files contained in target/micro
-cleanup ,,drivers''
-sprawdzić SEGGER RTT
#Configuring the environment
In order to build the project

svd file for desired processor or rather use stcubemx to download latest
-opisac konkretne foldery, co zawierają i do czego te pliki służą
- in case of "Error: selected processor does not support ARM mode `wfi'" please reconfigure your project with CMake tool in VS Code (Ctrl+shift+P and select ,,CMake: Delete cache and reconfigure)
- opisać co się dzieje przed mainem - jest system_init() który wywołuje mi template'y, a ja go potem inicjalizowałem zerami = zerowałem wszystko i cześć
- during instalation set ,,add to path variable"

C:\Users\Pawel\STM32Cube\Repository\STM32Cube_FW_F1_V1.8.0\Drivers <- STEROWNIKI SĄ STĄD <- POBRANE PRZEZ CUBEMX