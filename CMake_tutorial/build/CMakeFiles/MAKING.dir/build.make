# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\software dev\design_pattern\CMake_tutorial"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\software dev\design_pattern\CMake_tutorial\build"

# Include any dependencies generated for this target.
include CMakeFiles/MAKING.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MAKING.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MAKING.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MAKING.dir/flags.make

CMakeFiles/MAKING.dir/main.cpp.obj: CMakeFiles/MAKING.dir/flags.make
CMakeFiles/MAKING.dir/main.cpp.obj: ../main.cpp
CMakeFiles/MAKING.dir/main.cpp.obj: CMakeFiles/MAKING.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\software dev\design_pattern\CMake_tutorial\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MAKING.dir/main.cpp.obj"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MAKING.dir/main.cpp.obj -MF CMakeFiles\MAKING.dir\main.cpp.obj.d -o CMakeFiles\MAKING.dir\main.cpp.obj -c "D:\software dev\design_pattern\CMake_tutorial\main.cpp"

CMakeFiles/MAKING.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MAKING.dir/main.cpp.i"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\software dev\design_pattern\CMake_tutorial\main.cpp" > CMakeFiles\MAKING.dir\main.cpp.i

CMakeFiles/MAKING.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MAKING.dir/main.cpp.s"
	C:\PROGRA~1\CODEBL~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\software dev\design_pattern\CMake_tutorial\main.cpp" -o CMakeFiles\MAKING.dir\main.cpp.s

# Object files for target MAKING
MAKING_OBJECTS = \
"CMakeFiles/MAKING.dir/main.cpp.obj"

# External object files for target MAKING
MAKING_EXTERNAL_OBJECTS =

MAKING.exe: CMakeFiles/MAKING.dir/main.cpp.obj
MAKING.exe: CMakeFiles/MAKING.dir/build.make
MAKING.exe: CMakeFiles/MAKING.dir/linklibs.rsp
MAKING.exe: CMakeFiles/MAKING.dir/objects1.rsp
MAKING.exe: CMakeFiles/MAKING.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\software dev\design_pattern\CMake_tutorial\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MAKING.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MAKING.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MAKING.dir/build: MAKING.exe
.PHONY : CMakeFiles/MAKING.dir/build

CMakeFiles/MAKING.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MAKING.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MAKING.dir/clean

CMakeFiles/MAKING.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\software dev\design_pattern\CMake_tutorial" "D:\software dev\design_pattern\CMake_tutorial" "D:\software dev\design_pattern\CMake_tutorial\build" "D:\software dev\design_pattern\CMake_tutorial\build" "D:\software dev\design_pattern\CMake_tutorial\build\CMakeFiles\MAKING.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/MAKING.dir/depend

