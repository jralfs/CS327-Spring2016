cmake_minimum_required(VERSION 3.3)
project(project0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
#add_definitions(-std=gnu11)
set(CMAKE_LEGACY_CYGWIN_WIN32 0)

set(SOURCE_FILES )
set(PROJECT0.0 project0/src/hyperbinary.c)
set(PROJECT0.1 project0/src/rationalNumber.c)
set(PROJECT1.01 project1.01/src/main.c)
set(PROJECT1.02 project1.02/src/main.c)
set(PROJECT1.03 project1.03/src/main.c project1.03/src/dungeon.c project1.03/src/dungeon.h project1.03/src/globals.h project1.03/src/path.c project1.03/src/path.h project1.03/src/binheap.c project1.03/src/binheap.h project1.03/src/utils.c project1.03/src/utils.h)
set(PROJECT1.04 project1.04/src/main.c project1.04/src/dungeon.c project1.04/src/path.c project1.04/src/binheap.c project1.04/src/utils.c project1.04/src/movement.c project1.04/src/monster.c project1.04/src/turn.c)
set(PROJECT1.05 project1.05/src/main.c project1.05/src/dungeon.c project1.05/src/path.c project1.05/src/heap.c project1.05/src/utils.c project1.05/src/movement.c project1.05/src/monster.c project1.05/src/turn.c project1.05/src/screen.c)
set(PROJECT1.06 project1.06/src/main.c project1.06/src/dungeon.c project1.06/src/path.c project1.06/src/heap.c project1.06/src/utils.c project1.06/src/movement.c project1.06/src/monster.cpp project1.06/src/turn.c project1.06/src/screen.c)
set(PROJECT1.07 project1.07/src/main.cpp project1.07/src/dungeon.cpp project1.07/src/path.cpp project1.07/src/heap.c project1.07/src/utils.cpp project1.07/src/movement.cpp project1.07/src/monster.cpp project1.07/src/turn.cpp project1.07/src/screen.cpp project1.07/src/dice_set.cpp project1.07/src/dice_set.h)
set(PROJECT1.08 project1.08/src/main.cpp project1.08/src/dungeon.cpp project1.08/src/path.cpp project1.08/src/heap.c project1.08/src/utils.cpp project1.08/src/movement.cpp project1.08/src/monster.cpp project1.08/src/turn.cpp project1.08/src/screen.cpp project1.08/src/dice_set.cpp project1.08/src/dice_set.h project1.08/src/monster_descrip.cpp project1.08/src/item_descrip.cpp project1.08/src/descrip.cpp project1.08/src/descrip.h project1.08/src/item.cpp)
set(PROJECT1.09 project1.09/src/main.cpp project1.09/src/dungeon.cpp project1.09/src/path.cpp project1.09/src/heap.c project1.09/src/utils.cpp project1.09/src/movement.cpp project1.09/src/monster.cpp project1.09/src/turn.cpp project1.09/src/screen.cpp project1.09/src/dice_set.cpp project1.09/src/dice_set.h project1.09/src/monster_descrip.cpp project1.09/src/item_descrip.cpp project1.09/src/descrip.cpp project1.09/src/descrip.h project1.09/src/item.cpp project1.09/src/message_queue.cpp project1.09/src/message_queue.h)
find_package(Curses REQUIRED)
#include_directories()
#set(PROJECT1 project1.c)
add_executable(project0.0 ${SOURCE_FILES} ${PROJECT0.0})
add_executable(project0.1 ${SOURCE_FILES} ${PROJECT0.1})
add_executable(project1.01 ${SOURCE_FILES} ${PROJECT1.01})
add_executable(project1.02 ${SOURCE_FILES} ${PROJECT1.02})
add_executable(project1.03 ${SOURCE_FILES} ${PROJECT1.03})
add_executable(project1.04 ${SOURCE_FILES} ${PROJECT1.04})
add_executable(project1.05 ${SOURCE_FILES} ${PROJECT1.05})
add_executable(project1.06 ${SOURCE_FILES} ${PROJECT1.06})
add_executable(project1.07 ${SOURCE_FILES} ${PROJECT1.07})
add_executable(project1.08 ${SOURCE_FILES} ${PROJECT1.08})
add_executable(project1.09 ${SOURCE_FILES} ${PROJECT1.09})
target_link_libraries(project1.05 ${CURSES_LIBRARIES})
target_link_libraries(project1.06 ${CURSES_LIBRARIES})
target_link_libraries(project1.07 ${CURSES_LIBRARIES})
target_link_libraries(project1.08 ${CURSES_LIBRARIES})
target_link_libraries(project1.09 ${CURSES_LIBRARIES})