add_subdirectory("LibSystem")
add_subdirectory("Book")
add_subdirectory("User")
add_subdirectory("helpers")

add_executable(out main.cpp)
target_link_libraries(out LibSystem Book BooksClass User UsersClass ReaderModule)