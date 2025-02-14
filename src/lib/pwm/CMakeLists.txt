# Create a library called "rpi-pwm_lib"
add_library(rpi_pwm_lib clock.c pwm.c gpio.c pwm_setup.c)

# Specify include directories for the library
include_directories(${CMAKE_SOURCE_DIR}/include)

# Set the C++ standard
set_target_properties(rpi_pwm_lib PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)

# Link necessary libraries
target_link_libraries(rpi_pwm_lib pthread)


