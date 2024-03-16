add_library(pico_sleep_utility INTERFACE)

target_sources(pico_sleep_utility INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/src/pico_sleep_utility.cpp
)

target_include_directories(pico_sleep_utility INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src ${CMAKE_CURRENT_LIST_DIR}/include)

# Pull in pico libraries that we need
target_link_libraries(pico_sleep_utility INTERFACE pico_stdlib hardware_sleep hardware_gpio pico_runtime)
