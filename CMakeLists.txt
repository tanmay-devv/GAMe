cmake_minimum_required(VERSION 3.10)
project(GAMe)
find_package(X11)

add_executable(exegame main.cpp)
target_link_libraries(exegame
	${X11_LIBRARIES})
