# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "A1_autogen"
  "CMakeFiles\\A1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\A1_autogen.dir\\ParseCache.txt"
  )
endif()
