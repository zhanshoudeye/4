cmake_minimum_required(VERSION 3.30)
project(C__)

set(CMAKE_CXX_STANDARD 20)
include_directories(D:/C++/include)

add_executable(C__ main.cpp
        j.h
        include/Manage.h
        include/Report.h
        include/Checkout.h
        include/BookData.h
        include/Mainmenu.h
        BookData.cpp
        Checkout.cpp
        Mainmenu.cpp
        Report.cpp
        Manage.cpp)

