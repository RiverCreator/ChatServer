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
CMAKE_SOURCE_DIR = /home/river/work/mychat/proxy_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/river/work/mychat/proxy_server/build

# Include any dependencies generated for this target.
include src/CMakeFiles/ProxyServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/ProxyServer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ProxyServer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/ProxyServer.dir/flags.make

src/CMakeFiles/ProxyServer.dir/main.cpp.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/ProxyServer.dir/main.cpp.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/ProxyServer.dir/main.cpp.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/main.cpp.o -MF CMakeFiles/ProxyServer.dir/main.cpp.o.d -o CMakeFiles/ProxyServer.dir/main.cpp.o -c /home/river/work/mychat/proxy_server/src/main.cpp

src/CMakeFiles/ProxyServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/main.cpp.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/main.cpp > CMakeFiles/ProxyServer.dir/main.cpp.i

src/CMakeFiles/ProxyServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/main.cpp.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/main.cpp -o CMakeFiles/ProxyServer.dir/main.cpp.s

src/CMakeFiles/ProxyServer.dir/proxy_server.cpp.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proxy_server.cpp.o: ../src/proxy_server.cpp
src/CMakeFiles/ProxyServer.dir/proxy_server.cpp.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/ProxyServer.dir/proxy_server.cpp.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proxy_server.cpp.o -MF CMakeFiles/ProxyServer.dir/proxy_server.cpp.o.d -o CMakeFiles/ProxyServer.dir/proxy_server.cpp.o -c /home/river/work/mychat/proxy_server/src/proxy_server.cpp

src/CMakeFiles/ProxyServer.dir/proxy_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proxy_server.cpp.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proxy_server.cpp > CMakeFiles/ProxyServer.dir/proxy_server.cpp.i

src/CMakeFiles/ProxyServer.dir/proxy_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proxy_server.cpp.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proxy_server.cpp -o CMakeFiles/ProxyServer.dir/proxy_server.cpp.s

src/CMakeFiles/ProxyServer.dir/proxy_service.cpp.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proxy_service.cpp.o: ../src/proxy_service.cpp
src/CMakeFiles/ProxyServer.dir/proxy_service.cpp.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/ProxyServer.dir/proxy_service.cpp.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proxy_service.cpp.o -MF CMakeFiles/ProxyServer.dir/proxy_service.cpp.o.d -o CMakeFiles/ProxyServer.dir/proxy_service.cpp.o -c /home/river/work/mychat/proxy_server/src/proxy_service.cpp

src/CMakeFiles/ProxyServer.dir/proxy_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proxy_service.cpp.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proxy_service.cpp > CMakeFiles/ProxyServer.dir/proxy_service.cpp.i

src/CMakeFiles/ProxyServer.dir/proxy_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proxy_service.cpp.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proxy_service.cpp -o CMakeFiles/ProxyServer.dir/proxy_service.cpp.s

src/CMakeFiles/ProxyServer.dir/redis.cpp.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/redis.cpp.o: ../src/redis.cpp
src/CMakeFiles/ProxyServer.dir/redis.cpp.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/ProxyServer.dir/redis.cpp.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/redis.cpp.o -MF CMakeFiles/ProxyServer.dir/redis.cpp.o.d -o CMakeFiles/ProxyServer.dir/redis.cpp.o -c /home/river/work/mychat/proxy_server/src/redis.cpp

src/CMakeFiles/ProxyServer.dir/redis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/redis.cpp.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/redis.cpp > CMakeFiles/ProxyServer.dir/redis.cpp.i

src/CMakeFiles/ProxyServer.dir/redis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/redis.cpp.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/redis.cpp -o CMakeFiles/ProxyServer.dir/redis.cpp.s

src/CMakeFiles/ProxyServer.dir/zkMaster.cpp.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/zkMaster.cpp.o: ../src/zkMaster.cpp
src/CMakeFiles/ProxyServer.dir/zkMaster.cpp.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/ProxyServer.dir/zkMaster.cpp.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/zkMaster.cpp.o -MF CMakeFiles/ProxyServer.dir/zkMaster.cpp.o.d -o CMakeFiles/ProxyServer.dir/zkMaster.cpp.o -c /home/river/work/mychat/proxy_server/src/zkMaster.cpp

src/CMakeFiles/ProxyServer.dir/zkMaster.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/zkMaster.cpp.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/zkMaster.cpp > CMakeFiles/ProxyServer.dir/zkMaster.cpp.i

src/CMakeFiles/ProxyServer.dir/zkMaster.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/zkMaster.cpp.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/zkMaster.cpp -o CMakeFiles/ProxyServer.dir/zkMaster.cpp.s

src/CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o: ../src/proto/ChatServer.pb.cc
src/CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o -MF CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o.d -o CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o -c /home/river/work/mychat/proxy_server/src/proto/ChatServer.pb.cc

src/CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proto/ChatServer.pb.cc > CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.i

src/CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proto/ChatServer.pb.cc -o CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.s

src/CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o: ../src/proto/FriendService.pb.cc
src/CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o -MF CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o.d -o CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o -c /home/river/work/mychat/proxy_server/src/proto/FriendService.pb.cc

src/CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proto/FriendService.pb.cc > CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.i

src/CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proto/FriendService.pb.cc -o CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.s

src/CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o: ../src/proto/GroupService.pb.cc
src/CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o -MF CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o.d -o CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o -c /home/river/work/mychat/proxy_server/src/proto/GroupService.pb.cc

src/CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proto/GroupService.pb.cc > CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.i

src/CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proto/GroupService.pb.cc -o CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.s

src/CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o: ../src/proto/LogServer.pb.cc
src/CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o -MF CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o.d -o CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o -c /home/river/work/mychat/proxy_server/src/proto/LogServer.pb.cc

src/CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proto/LogServer.pb.cc > CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.i

src/CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proto/LogServer.pb.cc -o CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.s

src/CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o: ../src/proto/OfflineService.pb.cc
src/CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o -MF CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o.d -o CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o -c /home/river/work/mychat/proxy_server/src/proto/OfflineService.pb.cc

src/CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proto/OfflineService.pb.cc > CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.i

src/CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proto/OfflineService.pb.cc -o CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.s

src/CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o: ../src/proto/ProxyServer.pb.cc
src/CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o -MF CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o.d -o CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o -c /home/river/work/mychat/proxy_server/src/proto/ProxyServer.pb.cc

src/CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proto/ProxyServer.pb.cc > CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.i

src/CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proto/ProxyServer.pb.cc -o CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.s

src/CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o: src/CMakeFiles/ProxyServer.dir/flags.make
src/CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o: ../src/proto/UserService.pb.cc
src/CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o: src/CMakeFiles/ProxyServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o -MF CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o.d -o CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o -c /home/river/work/mychat/proxy_server/src/proto/UserService.pb.cc

src/CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.i"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/river/work/mychat/proxy_server/src/proto/UserService.pb.cc > CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.i

src/CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.s"
	cd /home/river/work/mychat/proxy_server/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/river/work/mychat/proxy_server/src/proto/UserService.pb.cc -o CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.s

# Object files for target ProxyServer
ProxyServer_OBJECTS = \
"CMakeFiles/ProxyServer.dir/main.cpp.o" \
"CMakeFiles/ProxyServer.dir/proxy_server.cpp.o" \
"CMakeFiles/ProxyServer.dir/proxy_service.cpp.o" \
"CMakeFiles/ProxyServer.dir/redis.cpp.o" \
"CMakeFiles/ProxyServer.dir/zkMaster.cpp.o" \
"CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o" \
"CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o" \
"CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o" \
"CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o" \
"CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o" \
"CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o" \
"CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o"

# External object files for target ProxyServer
ProxyServer_EXTERNAL_OBJECTS =

../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/main.cpp.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proxy_server.cpp.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proxy_service.cpp.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/redis.cpp.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/zkMaster.cpp.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proto/ChatServer.pb.cc.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proto/FriendService.pb.cc.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proto/GroupService.pb.cc.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proto/LogServer.pb.cc.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proto/OfflineService.pb.cc.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proto/ProxyServer.pb.cc.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/proto/UserService.pb.cc.o
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/build.make
../bin/ProxyServer: src/CMakeFiles/ProxyServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/river/work/mychat/proxy_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable ../../bin/ProxyServer"
	cd /home/river/work/mychat/proxy_server/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ProxyServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/ProxyServer.dir/build: ../bin/ProxyServer
.PHONY : src/CMakeFiles/ProxyServer.dir/build

src/CMakeFiles/ProxyServer.dir/clean:
	cd /home/river/work/mychat/proxy_server/build/src && $(CMAKE_COMMAND) -P CMakeFiles/ProxyServer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ProxyServer.dir/clean

src/CMakeFiles/ProxyServer.dir/depend:
	cd /home/river/work/mychat/proxy_server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/river/work/mychat/proxy_server /home/river/work/mychat/proxy_server/src /home/river/work/mychat/proxy_server/build /home/river/work/mychat/proxy_server/build/src /home/river/work/mychat/proxy_server/build/src/CMakeFiles/ProxyServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/ProxyServer.dir/depend

