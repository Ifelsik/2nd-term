# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Installed\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Installed\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Programming\C\HW5\Task_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Programming\C\HW5\Task_3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task_3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Task_3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Task_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task_3.dir/flags.make

CMakeFiles/Task_3.dir/main.c.obj: CMakeFiles/Task_3.dir/flags.make
CMakeFiles/Task_3.dir/main.c.obj: ../main.c
CMakeFiles/Task_3.dir/main.c.obj: CMakeFiles/Task_3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Programming\C\HW5\Task_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Task_3.dir/main.c.obj"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Task_3.dir/main.c.obj -MF CMakeFiles\Task_3.dir\main.c.obj.d -o CMakeFiles\Task_3.dir\main.c.obj -c C:\Programming\C\HW5\Task_3\main.c

CMakeFiles/Task_3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Task_3.dir/main.c.i"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Programming\C\HW5\Task_3\main.c > CMakeFiles\Task_3.dir\main.c.i

CMakeFiles/Task_3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Task_3.dir/main.c.s"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Programming\C\HW5\Task_3\main.c -o CMakeFiles\Task_3.dir\main.c.s

CMakeFiles/Task_3.dir/src/db_utils.c.obj: CMakeFiles/Task_3.dir/flags.make
CMakeFiles/Task_3.dir/src/db_utils.c.obj: ../src/db_utils.c
CMakeFiles/Task_3.dir/src/db_utils.c.obj: CMakeFiles/Task_3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Programming\C\HW5\Task_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Task_3.dir/src/db_utils.c.obj"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Task_3.dir/src/db_utils.c.obj -MF CMakeFiles\Task_3.dir\src\db_utils.c.obj.d -o CMakeFiles\Task_3.dir\src\db_utils.c.obj -c C:\Programming\C\HW5\Task_3\src\db_utils.c

CMakeFiles/Task_3.dir/src/db_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Task_3.dir/src/db_utils.c.i"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Programming\C\HW5\Task_3\src\db_utils.c > CMakeFiles\Task_3.dir\src\db_utils.c.i

CMakeFiles/Task_3.dir/src/db_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Task_3.dir/src/db_utils.c.s"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Programming\C\HW5\Task_3\src\db_utils.c -o CMakeFiles\Task_3.dir\src\db_utils.c.s

CMakeFiles/Task_3.dir/src/file_utils.c.obj: CMakeFiles/Task_3.dir/flags.make
CMakeFiles/Task_3.dir/src/file_utils.c.obj: ../src/file_utils.c
CMakeFiles/Task_3.dir/src/file_utils.c.obj: CMakeFiles/Task_3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Programming\C\HW5\Task_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Task_3.dir/src/file_utils.c.obj"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Task_3.dir/src/file_utils.c.obj -MF CMakeFiles\Task_3.dir\src\file_utils.c.obj.d -o CMakeFiles\Task_3.dir\src\file_utils.c.obj -c C:\Programming\C\HW5\Task_3\src\file_utils.c

CMakeFiles/Task_3.dir/src/file_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Task_3.dir/src/file_utils.c.i"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Programming\C\HW5\Task_3\src\file_utils.c > CMakeFiles\Task_3.dir\src\file_utils.c.i

CMakeFiles/Task_3.dir/src/file_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Task_3.dir/src/file_utils.c.s"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Programming\C\HW5\Task_3\src\file_utils.c -o CMakeFiles\Task_3.dir\src\file_utils.c.s

CMakeFiles/Task_3.dir/sha256/sha-256.c.obj: CMakeFiles/Task_3.dir/flags.make
CMakeFiles/Task_3.dir/sha256/sha-256.c.obj: ../sha256/sha-256.c
CMakeFiles/Task_3.dir/sha256/sha-256.c.obj: CMakeFiles/Task_3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Programming\C\HW5\Task_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Task_3.dir/sha256/sha-256.c.obj"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Task_3.dir/sha256/sha-256.c.obj -MF CMakeFiles\Task_3.dir\sha256\sha-256.c.obj.d -o CMakeFiles\Task_3.dir\sha256\sha-256.c.obj -c C:\Programming\C\HW5\Task_3\sha256\sha-256.c

CMakeFiles/Task_3.dir/sha256/sha-256.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Task_3.dir/sha256/sha-256.c.i"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Programming\C\HW5\Task_3\sha256\sha-256.c > CMakeFiles\Task_3.dir\sha256\sha-256.c.i

CMakeFiles/Task_3.dir/sha256/sha-256.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Task_3.dir/sha256/sha-256.c.s"
	C:\INSTAL~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Programming\C\HW5\Task_3\sha256\sha-256.c -o CMakeFiles\Task_3.dir\sha256\sha-256.c.s

# Object files for target Task_3
Task_3_OBJECTS = \
"CMakeFiles/Task_3.dir/main.c.obj" \
"CMakeFiles/Task_3.dir/src/db_utils.c.obj" \
"CMakeFiles/Task_3.dir/src/file_utils.c.obj" \
"CMakeFiles/Task_3.dir/sha256/sha-256.c.obj"

# External object files for target Task_3
Task_3_EXTERNAL_OBJECTS =

Task_3.exe: CMakeFiles/Task_3.dir/main.c.obj
Task_3.exe: CMakeFiles/Task_3.dir/src/db_utils.c.obj
Task_3.exe: CMakeFiles/Task_3.dir/src/file_utils.c.obj
Task_3.exe: CMakeFiles/Task_3.dir/sha256/sha-256.c.obj
Task_3.exe: CMakeFiles/Task_3.dir/build.make
Task_3.exe: CMakeFiles/Task_3.dir/linklibs.rsp
Task_3.exe: CMakeFiles/Task_3.dir/objects1.rsp
Task_3.exe: CMakeFiles/Task_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Programming\C\HW5\Task_3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Task_3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task_3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task_3.dir/build: Task_3.exe
.PHONY : CMakeFiles/Task_3.dir/build

CMakeFiles/Task_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task_3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task_3.dir/clean

CMakeFiles/Task_3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Programming\C\HW5\Task_3 C:\Programming\C\HW5\Task_3 C:\Programming\C\HW5\Task_3\cmake-build-debug C:\Programming\C\HW5\Task_3\cmake-build-debug C:\Programming\C\HW5\Task_3\cmake-build-debug\CMakeFiles\Task_3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task_3.dir/depend

