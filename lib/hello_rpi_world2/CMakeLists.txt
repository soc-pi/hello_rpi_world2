# Create a library called "hello_rpi_world2"
add_library(hello_rpi_world2_lib hello_rpi_world2.c)

# Specify include directories for the library
target_include_directories(hello_rpi_world2_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)
