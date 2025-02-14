add_executable(${PROJECT_NAME} main.c)

# Link the project library
target_link_libraries(${PROJECT_NAME} rpi_pwm_lib)

# Specify include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

# Set the C++ standard
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11 CXX_STANDARD_REQUIRED YES)
