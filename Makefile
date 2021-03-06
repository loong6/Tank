# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/loong6/Project/cocos2d-x-3.12/GameDemo/Tank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/loong6/Project/cocos2d-x-3.12/GameDemo/Tank

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/loong6/Project/cocos2d-x-3.12/GameDemo/Tank/CMakeFiles /home/loong6/Project/cocos2d-x-3.12/GameDemo/Tank/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/loong6/Project/cocos2d-x-3.12/GameDemo/Tank/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named MyGame

# Build rule for target.
MyGame: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MyGame
.PHONY : MyGame

# fast build rule for target.
MyGame/fast:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/build
.PHONY : MyGame/fast

#=============================================================================
# Target rules for targets named MyGame_PRE_BUILD

# Build rule for target.
MyGame_PRE_BUILD: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MyGame_PRE_BUILD
.PHONY : MyGame_PRE_BUILD

# fast build rule for target.
MyGame_PRE_BUILD/fast:
	$(MAKE) -f CMakeFiles/MyGame_PRE_BUILD.dir/build.make CMakeFiles/MyGame_PRE_BUILD.dir/build
.PHONY : MyGame_PRE_BUILD/fast

#=============================================================================
# Target rules for targets named MyGame_CORE_PRE_BUILD

# Build rule for target.
MyGame_CORE_PRE_BUILD: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 MyGame_CORE_PRE_BUILD
.PHONY : MyGame_CORE_PRE_BUILD

# fast build rule for target.
MyGame_CORE_PRE_BUILD/fast:
	$(MAKE) -f CMakeFiles/MyGame_CORE_PRE_BUILD.dir/build.make CMakeFiles/MyGame_CORE_PRE_BUILD.dir/build
.PHONY : MyGame_CORE_PRE_BUILD/fast

#=============================================================================
# Target rules for targets named bullet

# Build rule for target.
bullet: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 bullet
.PHONY : bullet

# fast build rule for target.
bullet/fast:
	$(MAKE) -f cocos2d/external/bullet/CMakeFiles/bullet.dir/build.make cocos2d/external/bullet/CMakeFiles/bullet.dir/build
.PHONY : bullet/fast

#=============================================================================
# Target rules for targets named recast

# Build rule for target.
recast: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 recast
.PHONY : recast

# fast build rule for target.
recast/fast:
	$(MAKE) -f cocos2d/external/recast/CMakeFiles/recast.dir/build.make cocos2d/external/recast/CMakeFiles/recast.dir/build
.PHONY : recast/fast

#=============================================================================
# Target rules for targets named tinyxml2

# Build rule for target.
tinyxml2: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 tinyxml2
.PHONY : tinyxml2

# fast build rule for target.
tinyxml2/fast:
	$(MAKE) -f cocos2d/external/tinyxml2/CMakeFiles/tinyxml2.dir/build.make cocos2d/external/tinyxml2/CMakeFiles/tinyxml2.dir/build
.PHONY : tinyxml2/fast

#=============================================================================
# Target rules for targets named unzip

# Build rule for target.
unzip: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 unzip
.PHONY : unzip

# fast build rule for target.
unzip/fast:
	$(MAKE) -f cocos2d/external/unzip/CMakeFiles/unzip.dir/build.make cocos2d/external/unzip/CMakeFiles/unzip.dir/build
.PHONY : unzip/fast

#=============================================================================
# Target rules for targets named flatbuffers

# Build rule for target.
flatbuffers: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 flatbuffers
.PHONY : flatbuffers

# fast build rule for target.
flatbuffers/fast:
	$(MAKE) -f cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build.make cocos2d/external/flatbuffers/CMakeFiles/flatbuffers.dir/build
.PHONY : flatbuffers/fast

#=============================================================================
# Target rules for targets named xxhash

# Build rule for target.
xxhash: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 xxhash
.PHONY : xxhash

# fast build rule for target.
xxhash/fast:
	$(MAKE) -f cocos2d/external/xxhash/CMakeFiles/xxhash.dir/build.make cocos2d/external/xxhash/CMakeFiles/xxhash.dir/build
.PHONY : xxhash/fast

#=============================================================================
# Target rules for targets named cocos2d

# Build rule for target.
cocos2d: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cocos2d
.PHONY : cocos2d

# fast build rule for target.
cocos2d/fast:
	$(MAKE) -f cocos2d/cocos/CMakeFiles/cocos2d.dir/build.make cocos2d/cocos/CMakeFiles/cocos2d.dir/build
.PHONY : cocos2d/fast

#=============================================================================
# Target rules for targets named cocos2dInternal

# Build rule for target.
cocos2dInternal: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cocos2dInternal
.PHONY : cocos2dInternal

# fast build rule for target.
cocos2dInternal/fast:
	$(MAKE) -f cocos2d/cocos/CMakeFiles/cocos2dInternal.dir/build.make cocos2d/cocos/CMakeFiles/cocos2dInternal.dir/build
.PHONY : cocos2dInternal/fast

Classes/AppDelegate.o: Classes/AppDelegate.cpp.o

.PHONY : Classes/AppDelegate.o

# target to build an object file
Classes/AppDelegate.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.o
.PHONY : Classes/AppDelegate.cpp.o

Classes/AppDelegate.i: Classes/AppDelegate.cpp.i

.PHONY : Classes/AppDelegate.i

# target to preprocess a source file
Classes/AppDelegate.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.i
.PHONY : Classes/AppDelegate.cpp.i

Classes/AppDelegate.s: Classes/AppDelegate.cpp.s

.PHONY : Classes/AppDelegate.s

# target to generate assembly for a file
Classes/AppDelegate.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AppDelegate.cpp.s
.PHONY : Classes/AppDelegate.cpp.s

Classes/AudioM.o: Classes/AudioM.cpp.o

.PHONY : Classes/AudioM.o

# target to build an object file
Classes/AudioM.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AudioM.cpp.o
.PHONY : Classes/AudioM.cpp.o

Classes/AudioM.i: Classes/AudioM.cpp.i

.PHONY : Classes/AudioM.i

# target to preprocess a source file
Classes/AudioM.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AudioM.cpp.i
.PHONY : Classes/AudioM.cpp.i

Classes/AudioM.s: Classes/AudioM.cpp.s

.PHONY : Classes/AudioM.s

# target to generate assembly for a file
Classes/AudioM.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/AudioM.cpp.s
.PHONY : Classes/AudioM.cpp.s

Classes/Bomb.o: Classes/Bomb.cpp.o

.PHONY : Classes/Bomb.o

# target to build an object file
Classes/Bomb.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bomb.cpp.o
.PHONY : Classes/Bomb.cpp.o

Classes/Bomb.i: Classes/Bomb.cpp.i

.PHONY : Classes/Bomb.i

# target to preprocess a source file
Classes/Bomb.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bomb.cpp.i
.PHONY : Classes/Bomb.cpp.i

Classes/Bomb.s: Classes/Bomb.cpp.s

.PHONY : Classes/Bomb.s

# target to generate assembly for a file
Classes/Bomb.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bomb.cpp.s
.PHONY : Classes/Bomb.cpp.s

Classes/BombM.o: Classes/BombM.cpp.o

.PHONY : Classes/BombM.o

# target to build an object file
Classes/BombM.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/BombM.cpp.o
.PHONY : Classes/BombM.cpp.o

Classes/BombM.i: Classes/BombM.cpp.i

.PHONY : Classes/BombM.i

# target to preprocess a source file
Classes/BombM.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/BombM.cpp.i
.PHONY : Classes/BombM.cpp.i

Classes/BombM.s: Classes/BombM.cpp.s

.PHONY : Classes/BombM.s

# target to generate assembly for a file
Classes/BombM.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/BombM.cpp.s
.PHONY : Classes/BombM.cpp.s

Classes/Bonus.o: Classes/Bonus.cpp.o

.PHONY : Classes/Bonus.o

# target to build an object file
Classes/Bonus.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bonus.cpp.o
.PHONY : Classes/Bonus.cpp.o

Classes/Bonus.i: Classes/Bonus.cpp.i

.PHONY : Classes/Bonus.i

# target to preprocess a source file
Classes/Bonus.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bonus.cpp.i
.PHONY : Classes/Bonus.cpp.i

Classes/Bonus.s: Classes/Bonus.cpp.s

.PHONY : Classes/Bonus.s

# target to generate assembly for a file
Classes/Bonus.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bonus.cpp.s
.PHONY : Classes/Bonus.cpp.s

Classes/Bullet.o: Classes/Bullet.cpp.o

.PHONY : Classes/Bullet.o

# target to build an object file
Classes/Bullet.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bullet.cpp.o
.PHONY : Classes/Bullet.cpp.o

Classes/Bullet.i: Classes/Bullet.cpp.i

.PHONY : Classes/Bullet.i

# target to preprocess a source file
Classes/Bullet.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bullet.cpp.i
.PHONY : Classes/Bullet.cpp.i

Classes/Bullet.s: Classes/Bullet.cpp.s

.PHONY : Classes/Bullet.s

# target to generate assembly for a file
Classes/Bullet.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Bullet.cpp.s
.PHONY : Classes/Bullet.cpp.s

Classes/BulletM.o: Classes/BulletM.cpp.o

.PHONY : Classes/BulletM.o

# target to build an object file
Classes/BulletM.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/BulletM.cpp.o
.PHONY : Classes/BulletM.cpp.o

Classes/BulletM.i: Classes/BulletM.cpp.i

.PHONY : Classes/BulletM.i

# target to preprocess a source file
Classes/BulletM.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/BulletM.cpp.i
.PHONY : Classes/BulletM.cpp.i

Classes/BulletM.s: Classes/BulletM.cpp.s

.PHONY : Classes/BulletM.s

# target to generate assembly for a file
Classes/BulletM.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/BulletM.cpp.s
.PHONY : Classes/BulletM.cpp.s

Classes/DataM.o: Classes/DataM.cpp.o

.PHONY : Classes/DataM.o

# target to build an object file
Classes/DataM.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/DataM.cpp.o
.PHONY : Classes/DataM.cpp.o

Classes/DataM.i: Classes/DataM.cpp.i

.PHONY : Classes/DataM.i

# target to preprocess a source file
Classes/DataM.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/DataM.cpp.i
.PHONY : Classes/DataM.cpp.i

Classes/DataM.s: Classes/DataM.cpp.s

.PHONY : Classes/DataM.s

# target to generate assembly for a file
Classes/DataM.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/DataM.cpp.s
.PHONY : Classes/DataM.cpp.s

Classes/EnemyTank.o: Classes/EnemyTank.cpp.o

.PHONY : Classes/EnemyTank.o

# target to build an object file
Classes/EnemyTank.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/EnemyTank.cpp.o
.PHONY : Classes/EnemyTank.cpp.o

Classes/EnemyTank.i: Classes/EnemyTank.cpp.i

.PHONY : Classes/EnemyTank.i

# target to preprocess a source file
Classes/EnemyTank.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/EnemyTank.cpp.i
.PHONY : Classes/EnemyTank.cpp.i

Classes/EnemyTank.s: Classes/EnemyTank.cpp.s

.PHONY : Classes/EnemyTank.s

# target to generate assembly for a file
Classes/EnemyTank.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/EnemyTank.cpp.s
.PHONY : Classes/EnemyTank.cpp.s

Classes/GameOverScene.o: Classes/GameOverScene.cpp.o

.PHONY : Classes/GameOverScene.o

# target to build an object file
Classes/GameOverScene.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/GameOverScene.cpp.o
.PHONY : Classes/GameOverScene.cpp.o

Classes/GameOverScene.i: Classes/GameOverScene.cpp.i

.PHONY : Classes/GameOverScene.i

# target to preprocess a source file
Classes/GameOverScene.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/GameOverScene.cpp.i
.PHONY : Classes/GameOverScene.cpp.i

Classes/GameOverScene.s: Classes/GameOverScene.cpp.s

.PHONY : Classes/GameOverScene.s

# target to generate assembly for a file
Classes/GameOverScene.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/GameOverScene.cpp.s
.PHONY : Classes/GameOverScene.cpp.s

Classes/GameScene.o: Classes/GameScene.cpp.o

.PHONY : Classes/GameScene.o

# target to build an object file
Classes/GameScene.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/GameScene.cpp.o
.PHONY : Classes/GameScene.cpp.o

Classes/GameScene.i: Classes/GameScene.cpp.i

.PHONY : Classes/GameScene.i

# target to preprocess a source file
Classes/GameScene.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/GameScene.cpp.i
.PHONY : Classes/GameScene.cpp.i

Classes/GameScene.s: Classes/GameScene.cpp.s

.PHONY : Classes/GameScene.s

# target to generate assembly for a file
Classes/GameScene.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/GameScene.cpp.s
.PHONY : Classes/GameScene.cpp.s

Classes/Global.o: Classes/Global.cpp.o

.PHONY : Classes/Global.o

# target to build an object file
Classes/Global.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Global.cpp.o
.PHONY : Classes/Global.cpp.o

Classes/Global.i: Classes/Global.cpp.i

.PHONY : Classes/Global.i

# target to preprocess a source file
Classes/Global.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Global.cpp.i
.PHONY : Classes/Global.cpp.i

Classes/Global.s: Classes/Global.cpp.s

.PHONY : Classes/Global.s

# target to generate assembly for a file
Classes/Global.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Global.cpp.s
.PHONY : Classes/Global.cpp.s

Classes/Joystick.o: Classes/Joystick.cpp.o

.PHONY : Classes/Joystick.o

# target to build an object file
Classes/Joystick.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Joystick.cpp.o
.PHONY : Classes/Joystick.cpp.o

Classes/Joystick.i: Classes/Joystick.cpp.i

.PHONY : Classes/Joystick.i

# target to preprocess a source file
Classes/Joystick.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Joystick.cpp.i
.PHONY : Classes/Joystick.cpp.i

Classes/Joystick.s: Classes/Joystick.cpp.s

.PHONY : Classes/Joystick.s

# target to generate assembly for a file
Classes/Joystick.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Joystick.cpp.s
.PHONY : Classes/Joystick.cpp.s

Classes/LevelScene.o: Classes/LevelScene.cpp.o

.PHONY : Classes/LevelScene.o

# target to build an object file
Classes/LevelScene.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/LevelScene.cpp.o
.PHONY : Classes/LevelScene.cpp.o

Classes/LevelScene.i: Classes/LevelScene.cpp.i

.PHONY : Classes/LevelScene.i

# target to preprocess a source file
Classes/LevelScene.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/LevelScene.cpp.i
.PHONY : Classes/LevelScene.cpp.i

Classes/LevelScene.s: Classes/LevelScene.cpp.s

.PHONY : Classes/LevelScene.s

# target to generate assembly for a file
Classes/LevelScene.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/LevelScene.cpp.s
.PHONY : Classes/LevelScene.cpp.s

Classes/LoadingScene.o: Classes/LoadingScene.cpp.o

.PHONY : Classes/LoadingScene.o

# target to build an object file
Classes/LoadingScene.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/LoadingScene.cpp.o
.PHONY : Classes/LoadingScene.cpp.o

Classes/LoadingScene.i: Classes/LoadingScene.cpp.i

.PHONY : Classes/LoadingScene.i

# target to preprocess a source file
Classes/LoadingScene.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/LoadingScene.cpp.i
.PHONY : Classes/LoadingScene.cpp.i

Classes/LoadingScene.s: Classes/LoadingScene.cpp.s

.PHONY : Classes/LoadingScene.s

# target to generate assembly for a file
Classes/LoadingScene.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/LoadingScene.cpp.s
.PHONY : Classes/LoadingScene.cpp.s

Classes/MenuScene.o: Classes/MenuScene.cpp.o

.PHONY : Classes/MenuScene.o

# target to build an object file
Classes/MenuScene.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/MenuScene.cpp.o
.PHONY : Classes/MenuScene.cpp.o

Classes/MenuScene.i: Classes/MenuScene.cpp.i

.PHONY : Classes/MenuScene.i

# target to preprocess a source file
Classes/MenuScene.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/MenuScene.cpp.i
.PHONY : Classes/MenuScene.cpp.i

Classes/MenuScene.s: Classes/MenuScene.cpp.s

.PHONY : Classes/MenuScene.s

# target to generate assembly for a file
Classes/MenuScene.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/MenuScene.cpp.s
.PHONY : Classes/MenuScene.cpp.s

Classes/PlayerTank.o: Classes/PlayerTank.cpp.o

.PHONY : Classes/PlayerTank.o

# target to build an object file
Classes/PlayerTank.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/PlayerTank.cpp.o
.PHONY : Classes/PlayerTank.cpp.o

Classes/PlayerTank.i: Classes/PlayerTank.cpp.i

.PHONY : Classes/PlayerTank.i

# target to preprocess a source file
Classes/PlayerTank.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/PlayerTank.cpp.i
.PHONY : Classes/PlayerTank.cpp.i

Classes/PlayerTank.s: Classes/PlayerTank.cpp.s

.PHONY : Classes/PlayerTank.s

# target to generate assembly for a file
Classes/PlayerTank.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/PlayerTank.cpp.s
.PHONY : Classes/PlayerTank.cpp.s

Classes/SceneM.o: Classes/SceneM.cpp.o

.PHONY : Classes/SceneM.o

# target to build an object file
Classes/SceneM.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/SceneM.cpp.o
.PHONY : Classes/SceneM.cpp.o

Classes/SceneM.i: Classes/SceneM.cpp.i

.PHONY : Classes/SceneM.i

# target to preprocess a source file
Classes/SceneM.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/SceneM.cpp.i
.PHONY : Classes/SceneM.cpp.i

Classes/SceneM.s: Classes/SceneM.cpp.s

.PHONY : Classes/SceneM.s

# target to generate assembly for a file
Classes/SceneM.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/SceneM.cpp.s
.PHONY : Classes/SceneM.cpp.s

Classes/Score.o: Classes/Score.cpp.o

.PHONY : Classes/Score.o

# target to build an object file
Classes/Score.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Score.cpp.o
.PHONY : Classes/Score.cpp.o

Classes/Score.i: Classes/Score.cpp.i

.PHONY : Classes/Score.i

# target to preprocess a source file
Classes/Score.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Score.cpp.i
.PHONY : Classes/Score.cpp.i

Classes/Score.s: Classes/Score.cpp.s

.PHONY : Classes/Score.s

# target to generate assembly for a file
Classes/Score.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Score.cpp.s
.PHONY : Classes/Score.cpp.s

Classes/Stage.o: Classes/Stage.cpp.o

.PHONY : Classes/Stage.o

# target to build an object file
Classes/Stage.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Stage.cpp.o
.PHONY : Classes/Stage.cpp.o

Classes/Stage.i: Classes/Stage.cpp.i

.PHONY : Classes/Stage.i

# target to preprocess a source file
Classes/Stage.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Stage.cpp.i
.PHONY : Classes/Stage.cpp.i

Classes/Stage.s: Classes/Stage.cpp.s

.PHONY : Classes/Stage.s

# target to generate assembly for a file
Classes/Stage.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Stage.cpp.s
.PHONY : Classes/Stage.cpp.s

Classes/Tank.o: Classes/Tank.cpp.o

.PHONY : Classes/Tank.o

# target to build an object file
Classes/Tank.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Tank.cpp.o
.PHONY : Classes/Tank.cpp.o

Classes/Tank.i: Classes/Tank.cpp.i

.PHONY : Classes/Tank.i

# target to preprocess a source file
Classes/Tank.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Tank.cpp.i
.PHONY : Classes/Tank.cpp.i

Classes/Tank.s: Classes/Tank.cpp.s

.PHONY : Classes/Tank.s

# target to generate assembly for a file
Classes/Tank.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/Tank.cpp.s
.PHONY : Classes/Tank.cpp.s

Classes/TankM.o: Classes/TankM.cpp.o

.PHONY : Classes/TankM.o

# target to build an object file
Classes/TankM.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/TankM.cpp.o
.PHONY : Classes/TankM.cpp.o

Classes/TankM.i: Classes/TankM.cpp.i

.PHONY : Classes/TankM.i

# target to preprocess a source file
Classes/TankM.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/TankM.cpp.i
.PHONY : Classes/TankM.cpp.i

Classes/TankM.s: Classes/TankM.cpp.s

.PHONY : Classes/TankM.s

# target to generate assembly for a file
Classes/TankM.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/TankM.cpp.s
.PHONY : Classes/TankM.cpp.s

Classes/TransitionEx.o: Classes/TransitionEx.cpp.o

.PHONY : Classes/TransitionEx.o

# target to build an object file
Classes/TransitionEx.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/TransitionEx.cpp.o
.PHONY : Classes/TransitionEx.cpp.o

Classes/TransitionEx.i: Classes/TransitionEx.cpp.i

.PHONY : Classes/TransitionEx.i

# target to preprocess a source file
Classes/TransitionEx.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/TransitionEx.cpp.i
.PHONY : Classes/TransitionEx.cpp.i

Classes/TransitionEx.s: Classes/TransitionEx.cpp.s

.PHONY : Classes/TransitionEx.s

# target to generate assembly for a file
Classes/TransitionEx.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/Classes/TransitionEx.cpp.s
.PHONY : Classes/TransitionEx.cpp.s

proj.linux/main.o: proj.linux/main.cpp.o

.PHONY : proj.linux/main.o

# target to build an object file
proj.linux/main.cpp.o:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/proj.linux/main.cpp.o
.PHONY : proj.linux/main.cpp.o

proj.linux/main.i: proj.linux/main.cpp.i

.PHONY : proj.linux/main.i

# target to preprocess a source file
proj.linux/main.cpp.i:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/proj.linux/main.cpp.i
.PHONY : proj.linux/main.cpp.i

proj.linux/main.s: proj.linux/main.cpp.s

.PHONY : proj.linux/main.s

# target to generate assembly for a file
proj.linux/main.cpp.s:
	$(MAKE) -f CMakeFiles/MyGame.dir/build.make CMakeFiles/MyGame.dir/proj.linux/main.cpp.s
.PHONY : proj.linux/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... MyGame"
	@echo "... MyGame_PRE_BUILD"
	@echo "... rebuild_cache"
	@echo "... MyGame_CORE_PRE_BUILD"
	@echo "... bullet"
	@echo "... recast"
	@echo "... tinyxml2"
	@echo "... unzip"
	@echo "... flatbuffers"
	@echo "... xxhash"
	@echo "... cocos2d"
	@echo "... cocos2dInternal"
	@echo "... Classes/AppDelegate.o"
	@echo "... Classes/AppDelegate.i"
	@echo "... Classes/AppDelegate.s"
	@echo "... Classes/AudioM.o"
	@echo "... Classes/AudioM.i"
	@echo "... Classes/AudioM.s"
	@echo "... Classes/Bomb.o"
	@echo "... Classes/Bomb.i"
	@echo "... Classes/Bomb.s"
	@echo "... Classes/BombM.o"
	@echo "... Classes/BombM.i"
	@echo "... Classes/BombM.s"
	@echo "... Classes/Bonus.o"
	@echo "... Classes/Bonus.i"
	@echo "... Classes/Bonus.s"
	@echo "... Classes/Bullet.o"
	@echo "... Classes/Bullet.i"
	@echo "... Classes/Bullet.s"
	@echo "... Classes/BulletM.o"
	@echo "... Classes/BulletM.i"
	@echo "... Classes/BulletM.s"
	@echo "... Classes/DataM.o"
	@echo "... Classes/DataM.i"
	@echo "... Classes/DataM.s"
	@echo "... Classes/EnemyTank.o"
	@echo "... Classes/EnemyTank.i"
	@echo "... Classes/EnemyTank.s"
	@echo "... Classes/GameOverScene.o"
	@echo "... Classes/GameOverScene.i"
	@echo "... Classes/GameOverScene.s"
	@echo "... Classes/GameScene.o"
	@echo "... Classes/GameScene.i"
	@echo "... Classes/GameScene.s"
	@echo "... Classes/Global.o"
	@echo "... Classes/Global.i"
	@echo "... Classes/Global.s"
	@echo "... Classes/Joystick.o"
	@echo "... Classes/Joystick.i"
	@echo "... Classes/Joystick.s"
	@echo "... Classes/LevelScene.o"
	@echo "... Classes/LevelScene.i"
	@echo "... Classes/LevelScene.s"
	@echo "... Classes/LoadingScene.o"
	@echo "... Classes/LoadingScene.i"
	@echo "... Classes/LoadingScene.s"
	@echo "... Classes/MenuScene.o"
	@echo "... Classes/MenuScene.i"
	@echo "... Classes/MenuScene.s"
	@echo "... Classes/PlayerTank.o"
	@echo "... Classes/PlayerTank.i"
	@echo "... Classes/PlayerTank.s"
	@echo "... Classes/SceneM.o"
	@echo "... Classes/SceneM.i"
	@echo "... Classes/SceneM.s"
	@echo "... Classes/Score.o"
	@echo "... Classes/Score.i"
	@echo "... Classes/Score.s"
	@echo "... Classes/Stage.o"
	@echo "... Classes/Stage.i"
	@echo "... Classes/Stage.s"
	@echo "... Classes/Tank.o"
	@echo "... Classes/Tank.i"
	@echo "... Classes/Tank.s"
	@echo "... Classes/TankM.o"
	@echo "... Classes/TankM.i"
	@echo "... Classes/TankM.s"
	@echo "... Classes/TransitionEx.o"
	@echo "... Classes/TransitionEx.i"
	@echo "... Classes/TransitionEx.s"
	@echo "... proj.linux/main.o"
	@echo "... proj.linux/main.i"
	@echo "... proj.linux/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

