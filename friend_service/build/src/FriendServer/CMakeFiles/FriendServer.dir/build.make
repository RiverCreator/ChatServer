# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/river/work/mychat/friend_service

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/river/work/mychat/friend_service/build

# Include any dependencies generated for this target.
include src/FriendServer/CMakeFiles/FriendServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/FriendServer/CMakeFiles/FriendServer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/FriendServer/CMakeFiles/FriendServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/FriendServer/CMakeFiles/FriendServer.dir/flags.make

src/FriendServer/CMakeFiles/FriendServer.dir/FriendServer.cpp.o: src/FriendServer/CMakeFiles/FriendServer.dir/flags.make
src/FriendServer/CMakeFiles/FriendServer.dir/FriendServer.cpp.o: ../src/FriendServer/FriendServer.cpp
src/FriendServer/CMakeFiles/FriendServer.dir/FriendServer.cpp.o: src/FriendServer/CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/friend_service/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/FriendServer/CMakeFiles/FriendServer.dir/FriendServer.cpp.o"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/FriendServer/CMakeFiles/FriendServer.dir/FriendServer.cpp.o -MF CMakeFiles/FriendServer.dir/FriendServer.cpp.o.d -o CMakeFiles/FriendServer.dir/FriendServer.cpp.o -c /home/river/work/mychat/friend_service/src/FriendServer/FriendServer.cpp

src/FriendServer/CMakeFiles/FriendServer.dir/FriendServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/FriendServer.cpp.i"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/friend_service/src/FriendServer/FriendServer.cpp > CMakeFiles/FriendServer.dir/FriendServer.cpp.i

src/FriendServer/CMakeFiles/FriendServer.dir/FriendServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/FriendServer.cpp.s"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/friend_service/src/FriendServer/FriendServer.cpp -o CMakeFiles/FriendServer.dir/FriendServer.cpp.s

src/FriendServer/CMakeFiles/FriendServer.dir/redis.cpp.o: src/FriendServer/CMakeFiles/FriendServer.dir/flags.make
src/FriendServer/CMakeFiles/FriendServer.dir/redis.cpp.o: ../src/FriendServer/redis.cpp
src/FriendServer/CMakeFiles/FriendServer.dir/redis.cpp.o: src/FriendServer/CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/friend_service/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/FriendServer/CMakeFiles/FriendServer.dir/redis.cpp.o"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/FriendServer/CMakeFiles/FriendServer.dir/redis.cpp.o -MF CMakeFiles/FriendServer.dir/redis.cpp.o.d -o CMakeFiles/FriendServer.dir/redis.cpp.o -c /home/river/work/mychat/friend_service/src/FriendServer/redis.cpp

src/FriendServer/CMakeFiles/FriendServer.dir/redis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/redis.cpp.i"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/friend_service/src/FriendServer/redis.cpp > CMakeFiles/FriendServer.dir/redis.cpp.i

src/FriendServer/CMakeFiles/FriendServer.dir/redis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/redis.cpp.s"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/friend_service/src/FriendServer/redis.cpp -o CMakeFiles/FriendServer.dir/redis.cpp.s

src/FriendServer/CMakeFiles/FriendServer.dir/run.cpp.o: src/FriendServer/CMakeFiles/FriendServer.dir/flags.make
src/FriendServer/CMakeFiles/FriendServer.dir/run.cpp.o: ../src/FriendServer/run.cpp
src/FriendServer/CMakeFiles/FriendServer.dir/run.cpp.o: src/FriendServer/CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/friend_service/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/FriendServer/CMakeFiles/FriendServer.dir/run.cpp.o"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/FriendServer/CMakeFiles/FriendServer.dir/run.cpp.o -MF CMakeFiles/FriendServer.dir/run.cpp.o.d -o CMakeFiles/FriendServer.dir/run.cpp.o -c /home/river/work/mychat/friend_service/src/FriendServer/run.cpp

src/FriendServer/CMakeFiles/FriendServer.dir/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/run.cpp.i"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/friend_service/src/FriendServer/run.cpp > CMakeFiles/FriendServer.dir/run.cpp.i

src/FriendServer/CMakeFiles/FriendServer.dir/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/run.cpp.s"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/friend_service/src/FriendServer/run.cpp -o CMakeFiles/FriendServer.dir/run.cpp.s

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o: src/FriendServer/CMakeFiles/FriendServer.dir/flags.make
src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o: ../src/proto/FriendServer.pb.cc
src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o: src/FriendServer/CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/friend_service/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o -MF CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o.d -o CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o -c /home/river/work/mychat/friend_service/src/proto/FriendServer.pb.cc

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.i"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/friend_service/src/proto/FriendServer.pb.cc > CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.i

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.s"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/friend_service/src/proto/FriendServer.pb.cc -o CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.s

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o: src/FriendServer/CMakeFiles/FriendServer.dir/flags.make
src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o: ../src/proto/FriendService.pb.cc
src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o: src/FriendServer/CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/friend_service/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o -MF CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o.d -o CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o -c /home/river/work/mychat/friend_service/src/proto/FriendService.pb.cc

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.i"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/friend_service/src/proto/FriendService.pb.cc > CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.i

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.s"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/friend_service/src/proto/FriendService.pb.cc -o CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.s

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o: src/FriendServer/CMakeFiles/FriendServer.dir/flags.make
src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o: ../src/proto/LogServer.pb.cc
src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o: src/FriendServer/CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/friend_service/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o -MF CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o.d -o CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o -c /home/river/work/mychat/friend_service/src/proto/LogServer.pb.cc

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.i"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/friend_service/src/proto/LogServer.pb.cc > CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.i

src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.s"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/friend_service/src/proto/LogServer.pb.cc -o CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.s

# Object files for target FriendServer
FriendServer_OBJECTS = \
"CMakeFiles/FriendServer.dir/FriendServer.cpp.o" \
"CMakeFiles/FriendServer.dir/redis.cpp.o" \
"CMakeFiles/FriendServer.dir/run.cpp.o" \
"CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o" \
"CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o" \
"CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o"

# External object files for target FriendServer
FriendServer_EXTERNAL_OBJECTS =

../bin/FriendServer: src/FriendServer/CMakeFiles/FriendServer.dir/FriendServer.cpp.o
../bin/FriendServer: src/FriendServer/CMakeFiles/FriendServer.dir/redis.cpp.o
../bin/FriendServer: src/FriendServer/CMakeFiles/FriendServer.dir/run.cpp.o
../bin/FriendServer: src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendServer.pb.cc.o
../bin/FriendServer: src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/FriendService.pb.cc.o
../bin/FriendServer: src/FriendServer/CMakeFiles/FriendServer.dir/__/proto/LogServer.pb.cc.o
../bin/FriendServer: src/FriendServer/CMakeFiles/FriendServer.dir/build.make
../bin/FriendServer: src/FriendServer/CMakeFiles/FriendServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/river/work/mychat/friend_service/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ../../../bin/FriendServer"
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FriendServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/FriendServer/CMakeFiles/FriendServer.dir/build: ../bin/FriendServer
.PHONY : src/FriendServer/CMakeFiles/FriendServer.dir/build

src/FriendServer/CMakeFiles/FriendServer.dir/clean:
	cd /home/river/work/mychat/friend_service/build/src/FriendServer && $(CMAKE_COMMAND) -P CMakeFiles/FriendServer.dir/cmake_clean.cmake
.PHONY : src/FriendServer/CMakeFiles/FriendServer.dir/clean

src/FriendServer/CMakeFiles/FriendServer.dir/depend:
	cd /home/river/work/mychat/friend_service/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/river/work/mychat/friend_service /home/river/work/mychat/friend_service/src/FriendServer /home/river/work/mychat/friend_service/build /home/river/work/mychat/friend_service/build/src/FriendServer /home/river/work/mychat/friend_service/build/src/FriendServer/CMakeFiles/FriendServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/FriendServer/CMakeFiles/FriendServer.dir/depend

