# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhangjizhi/data/G4_IMP/geant4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhangjizhi/data/G4_IMP/geant4/build

# Include any dependencies generated for this target.
include CMakeFiles/geant4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/geant4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/geant4.dir/flags.make

CMakeFiles/geant4.dir/main.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/geant4.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/main.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/main.cc

CMakeFiles/geant4.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/main.cc > CMakeFiles/geant4.dir/main.cc.i

CMakeFiles/geant4.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/main.cc -o CMakeFiles/geant4.dir/main.cc.s

CMakeFiles/geant4.dir/main.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/main.cc.o.requires

CMakeFiles/geant4.dir/main.cc.o.provides: CMakeFiles/geant4.dir/main.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/main.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/main.cc.o.provides

CMakeFiles/geant4.dir/main.cc.o.provides.build: CMakeFiles/geant4.dir/main.cc.o


CMakeFiles/geant4.dir/src/ActionInitialization.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/ActionInitialization.cc.o: ../src/ActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/geant4.dir/src/ActionInitialization.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/ActionInitialization.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/ActionInitialization.cc

CMakeFiles/geant4.dir/src/ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/ActionInitialization.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/ActionInitialization.cc > CMakeFiles/geant4.dir/src/ActionInitialization.cc.i

CMakeFiles/geant4.dir/src/ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/ActionInitialization.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/ActionInitialization.cc -o CMakeFiles/geant4.dir/src/ActionInitialization.cc.s

CMakeFiles/geant4.dir/src/ActionInitialization.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/ActionInitialization.cc.o.requires

CMakeFiles/geant4.dir/src/ActionInitialization.cc.o.provides: CMakeFiles/geant4.dir/src/ActionInitialization.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/ActionInitialization.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/ActionInitialization.cc.o.provides

CMakeFiles/geant4.dir/src/ActionInitialization.cc.o.provides.build: CMakeFiles/geant4.dir/src/ActionInitialization.cc.o


CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o: ../src/DetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/DetectorConstruction.cc

CMakeFiles/geant4.dir/src/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/DetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/DetectorConstruction.cc > CMakeFiles/geant4.dir/src/DetectorConstruction.cc.i

CMakeFiles/geant4.dir/src/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/DetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/DetectorConstruction.cc -o CMakeFiles/geant4.dir/src/DetectorConstruction.cc.s

CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o.requires

CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o.provides: CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o.provides

CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o.provides.build: CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o


CMakeFiles/geant4.dir/src/EventAction.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/EventAction.cc.o: ../src/EventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/geant4.dir/src/EventAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/EventAction.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/EventAction.cc

CMakeFiles/geant4.dir/src/EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/EventAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/EventAction.cc > CMakeFiles/geant4.dir/src/EventAction.cc.i

CMakeFiles/geant4.dir/src/EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/EventAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/EventAction.cc -o CMakeFiles/geant4.dir/src/EventAction.cc.s

CMakeFiles/geant4.dir/src/EventAction.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/EventAction.cc.o.requires

CMakeFiles/geant4.dir/src/EventAction.cc.o.provides: CMakeFiles/geant4.dir/src/EventAction.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/EventAction.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/EventAction.cc.o.provides

CMakeFiles/geant4.dir/src/EventAction.cc.o.provides.build: CMakeFiles/geant4.dir/src/EventAction.cc.o


CMakeFiles/geant4.dir/src/PhysicsList.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/PhysicsList.cc.o: ../src/PhysicsList.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/geant4.dir/src/PhysicsList.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/PhysicsList.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/PhysicsList.cc

CMakeFiles/geant4.dir/src/PhysicsList.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/PhysicsList.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/PhysicsList.cc > CMakeFiles/geant4.dir/src/PhysicsList.cc.i

CMakeFiles/geant4.dir/src/PhysicsList.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/PhysicsList.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/PhysicsList.cc -o CMakeFiles/geant4.dir/src/PhysicsList.cc.s

CMakeFiles/geant4.dir/src/PhysicsList.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/PhysicsList.cc.o.requires

CMakeFiles/geant4.dir/src/PhysicsList.cc.o.provides: CMakeFiles/geant4.dir/src/PhysicsList.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/PhysicsList.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/PhysicsList.cc.o.provides

CMakeFiles/geant4.dir/src/PhysicsList.cc.o.provides.build: CMakeFiles/geant4.dir/src/PhysicsList.cc.o


CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o: ../src/PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/PrimaryGeneratorAction.cc

CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/PrimaryGeneratorAction.cc > CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.i

CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/PrimaryGeneratorAction.cc -o CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.s

CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o.requires

CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o.provides: CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o.provides

CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o.provides.build: CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o


CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o: ../src/RadioactiveDecayPhysics.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/RadioactiveDecayPhysics.cc

CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/RadioactiveDecayPhysics.cc > CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.i

CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/RadioactiveDecayPhysics.cc -o CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.s

CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o.requires

CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o.provides: CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o.provides

CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o.provides.build: CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o


CMakeFiles/geant4.dir/src/RunAction.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/RunAction.cc.o: ../src/RunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/geant4.dir/src/RunAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/RunAction.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/RunAction.cc

CMakeFiles/geant4.dir/src/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/RunAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/RunAction.cc > CMakeFiles/geant4.dir/src/RunAction.cc.i

CMakeFiles/geant4.dir/src/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/RunAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/RunAction.cc -o CMakeFiles/geant4.dir/src/RunAction.cc.s

CMakeFiles/geant4.dir/src/RunAction.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/RunAction.cc.o.requires

CMakeFiles/geant4.dir/src/RunAction.cc.o.provides: CMakeFiles/geant4.dir/src/RunAction.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/RunAction.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/RunAction.cc.o.provides

CMakeFiles/geant4.dir/src/RunAction.cc.o.provides.build: CMakeFiles/geant4.dir/src/RunAction.cc.o


CMakeFiles/geant4.dir/src/StackingAction.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/StackingAction.cc.o: ../src/StackingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/geant4.dir/src/StackingAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/StackingAction.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/StackingAction.cc

CMakeFiles/geant4.dir/src/StackingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/StackingAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/StackingAction.cc > CMakeFiles/geant4.dir/src/StackingAction.cc.i

CMakeFiles/geant4.dir/src/StackingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/StackingAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/StackingAction.cc -o CMakeFiles/geant4.dir/src/StackingAction.cc.s

CMakeFiles/geant4.dir/src/StackingAction.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/StackingAction.cc.o.requires

CMakeFiles/geant4.dir/src/StackingAction.cc.o.provides: CMakeFiles/geant4.dir/src/StackingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/StackingAction.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/StackingAction.cc.o.provides

CMakeFiles/geant4.dir/src/StackingAction.cc.o.provides.build: CMakeFiles/geant4.dir/src/StackingAction.cc.o


CMakeFiles/geant4.dir/src/SteppingAction.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/SteppingAction.cc.o: ../src/SteppingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/geant4.dir/src/SteppingAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/SteppingAction.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/SteppingAction.cc

CMakeFiles/geant4.dir/src/SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/SteppingAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/SteppingAction.cc > CMakeFiles/geant4.dir/src/SteppingAction.cc.i

CMakeFiles/geant4.dir/src/SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/SteppingAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/SteppingAction.cc -o CMakeFiles/geant4.dir/src/SteppingAction.cc.s

CMakeFiles/geant4.dir/src/SteppingAction.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/SteppingAction.cc.o.requires

CMakeFiles/geant4.dir/src/SteppingAction.cc.o.provides: CMakeFiles/geant4.dir/src/SteppingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/SteppingAction.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/SteppingAction.cc.o.provides

CMakeFiles/geant4.dir/src/SteppingAction.cc.o.provides.build: CMakeFiles/geant4.dir/src/SteppingAction.cc.o


CMakeFiles/geant4.dir/src/TrackInformation.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/TrackInformation.cc.o: ../src/TrackInformation.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/geant4.dir/src/TrackInformation.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/TrackInformation.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/TrackInformation.cc

CMakeFiles/geant4.dir/src/TrackInformation.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/TrackInformation.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/TrackInformation.cc > CMakeFiles/geant4.dir/src/TrackInformation.cc.i

CMakeFiles/geant4.dir/src/TrackInformation.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/TrackInformation.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/TrackInformation.cc -o CMakeFiles/geant4.dir/src/TrackInformation.cc.s

CMakeFiles/geant4.dir/src/TrackInformation.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/TrackInformation.cc.o.requires

CMakeFiles/geant4.dir/src/TrackInformation.cc.o.provides: CMakeFiles/geant4.dir/src/TrackInformation.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/TrackInformation.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/TrackInformation.cc.o.provides

CMakeFiles/geant4.dir/src/TrackInformation.cc.o.provides.build: CMakeFiles/geant4.dir/src/TrackInformation.cc.o


CMakeFiles/geant4.dir/src/TrackingAction.cc.o: CMakeFiles/geant4.dir/flags.make
CMakeFiles/geant4.dir/src/TrackingAction.cc.o: ../src/TrackingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/geant4.dir/src/TrackingAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/geant4.dir/src/TrackingAction.cc.o -c /home/zhangjizhi/data/G4_IMP/geant4/src/TrackingAction.cc

CMakeFiles/geant4.dir/src/TrackingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geant4.dir/src/TrackingAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangjizhi/data/G4_IMP/geant4/src/TrackingAction.cc > CMakeFiles/geant4.dir/src/TrackingAction.cc.i

CMakeFiles/geant4.dir/src/TrackingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geant4.dir/src/TrackingAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangjizhi/data/G4_IMP/geant4/src/TrackingAction.cc -o CMakeFiles/geant4.dir/src/TrackingAction.cc.s

CMakeFiles/geant4.dir/src/TrackingAction.cc.o.requires:

.PHONY : CMakeFiles/geant4.dir/src/TrackingAction.cc.o.requires

CMakeFiles/geant4.dir/src/TrackingAction.cc.o.provides: CMakeFiles/geant4.dir/src/TrackingAction.cc.o.requires
	$(MAKE) -f CMakeFiles/geant4.dir/build.make CMakeFiles/geant4.dir/src/TrackingAction.cc.o.provides.build
.PHONY : CMakeFiles/geant4.dir/src/TrackingAction.cc.o.provides

CMakeFiles/geant4.dir/src/TrackingAction.cc.o.provides.build: CMakeFiles/geant4.dir/src/TrackingAction.cc.o


# Object files for target geant4
geant4_OBJECTS = \
"CMakeFiles/geant4.dir/main.cc.o" \
"CMakeFiles/geant4.dir/src/ActionInitialization.cc.o" \
"CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o" \
"CMakeFiles/geant4.dir/src/EventAction.cc.o" \
"CMakeFiles/geant4.dir/src/PhysicsList.cc.o" \
"CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o" \
"CMakeFiles/geant4.dir/src/RunAction.cc.o" \
"CMakeFiles/geant4.dir/src/StackingAction.cc.o" \
"CMakeFiles/geant4.dir/src/SteppingAction.cc.o" \
"CMakeFiles/geant4.dir/src/TrackInformation.cc.o" \
"CMakeFiles/geant4.dir/src/TrackingAction.cc.o"

# External object files for target geant4
geant4_EXTERNAL_OBJECTS =

geant4: CMakeFiles/geant4.dir/main.cc.o
geant4: CMakeFiles/geant4.dir/src/ActionInitialization.cc.o
geant4: CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o
geant4: CMakeFiles/geant4.dir/src/EventAction.cc.o
geant4: CMakeFiles/geant4.dir/src/PhysicsList.cc.o
geant4: CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o
geant4: CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o
geant4: CMakeFiles/geant4.dir/src/RunAction.cc.o
geant4: CMakeFiles/geant4.dir/src/StackingAction.cc.o
geant4: CMakeFiles/geant4.dir/src/SteppingAction.cc.o
geant4: CMakeFiles/geant4.dir/src/TrackInformation.cc.o
geant4: CMakeFiles/geant4.dir/src/TrackingAction.cc.o
geant4: CMakeFiles/geant4.dir/build.make
geant4: /opt/Geant4/geant41007p03/lib64/libG4Tree.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4FR.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4GMocren.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4visHepRep.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4RayTracer.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4VRML.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4OpenGL.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4gl2ps.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4vis_management.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4modeling.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4interfaces.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4persistency.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4error_propagation.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4readout.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4physicslists.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4tasking.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4parmodels.so
geant4: /opt/ROOT/root61600/lib/libCore.so
geant4: /opt/ROOT/root61600/lib/libImt.so
geant4: /opt/ROOT/root61600/lib/libRIO.so
geant4: /opt/ROOT/root61600/lib/libNet.so
geant4: /opt/ROOT/root61600/lib/libHist.so
geant4: /opt/ROOT/root61600/lib/libGraf.so
geant4: /opt/ROOT/root61600/lib/libGraf3d.so
geant4: /opt/ROOT/root61600/lib/libGpad.so
geant4: /opt/ROOT/root61600/lib/libROOTDataFrame.so
geant4: /opt/ROOT/root61600/lib/libTree.so
geant4: /opt/ROOT/root61600/lib/libTreePlayer.so
geant4: /opt/ROOT/root61600/lib/libRint.so
geant4: /opt/ROOT/root61600/lib/libPostscript.so
geant4: /opt/ROOT/root61600/lib/libMatrix.so
geant4: /opt/ROOT/root61600/lib/libPhysics.so
geant4: /opt/ROOT/root61600/lib/libMathCore.so
geant4: /opt/ROOT/root61600/lib/libThread.so
geant4: /opt/ROOT/root61600/lib/libMultiProc.so
geant4: /usr/lib64/libXmu.so
geant4: /usr/lib64/libXext.so
geant4: /usr/lib64/libXm.so
geant4: /usr/lib64/libXt.so
geant4: /usr/lib64/libICE.so
geant4: /usr/lib64/libSM.so
geant4: /usr/lib64/libX11.so
geant4: /usr/lib64/libGL.so
geant4: /usr/lib64/libQt5OpenGL.so.5.9.7
geant4: /usr/lib64/libQt5PrintSupport.so.5.9.7
geant4: /usr/lib64/libQt5Widgets.so.5.9.7
geant4: /usr/lib64/libQt5Gui.so.5.9.7
geant4: /usr/lib64/libQt5Core.so.5.9.7
geant4: /opt/xerces-c/3.2.3/lib64/libxerces-c.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4run.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4event.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4tracking.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4processes.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4analysis.so
geant4: /usr/lib64/libfreetype.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4expat.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4digits_hits.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4track.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4particles.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4geometry.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4materials.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4zlib.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4graphics_reps.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4intercoms.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4global.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4clhep.so
geant4: /opt/Geant4/geant41007p03/lib64/libG4ptl.so.0.0.2
geant4: CMakeFiles/geant4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable geant4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/geant4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/geant4.dir/build: geant4

.PHONY : CMakeFiles/geant4.dir/build

CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/main.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/ActionInitialization.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/DetectorConstruction.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/EventAction.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/PhysicsList.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/PrimaryGeneratorAction.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/RadioactiveDecayPhysics.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/RunAction.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/StackingAction.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/SteppingAction.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/TrackInformation.cc.o.requires
CMakeFiles/geant4.dir/requires: CMakeFiles/geant4.dir/src/TrackingAction.cc.o.requires

.PHONY : CMakeFiles/geant4.dir/requires

CMakeFiles/geant4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/geant4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/geant4.dir/clean

CMakeFiles/geant4.dir/depend:
	cd /home/zhangjizhi/data/G4_IMP/geant4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangjizhi/data/G4_IMP/geant4 /home/zhangjizhi/data/G4_IMP/geant4 /home/zhangjizhi/data/G4_IMP/geant4/build /home/zhangjizhi/data/G4_IMP/geant4/build /home/zhangjizhi/data/G4_IMP/geant4/build/CMakeFiles/geant4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/geant4.dir/depend
