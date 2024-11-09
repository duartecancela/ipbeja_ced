cmake_minimum_required(VERSION 3.22)
project(ced LANGUAGES CXX)
find_package(CUDAToolkit)
set(CMAKE_CXX)

add_executable(farao
	farao.cpp
	f.cpp
	soma_integral.cpp 
	heat_difusion.cpp
)