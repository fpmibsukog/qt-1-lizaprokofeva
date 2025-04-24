cmake_minimum_required(VERSION 3.16)

project(task2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets) 
qt_standard_project_setup()

qt_add_executable(LectureTask
     main.cpp
     Book.cpp
     Library.cpp 
     User.cpp 
     Utils.cpp 
     MainWindow.cpp
     AddBookDialog.cpp
     AddUserDialog.cpp 
     SearchBookDialog.cpp 
     Info.cpp
     LendBook.cpp
)

target_link_libraries(LectureTask PRIVATE Qt6::Widgets)


set_target_properties(LectureTask PROPERTIES
    WIN32_EXECUTABLE ON
)