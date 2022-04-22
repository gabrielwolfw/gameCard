# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjectCard_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjectCard_autogen.dir\\ParseCache.txt"
  "ProjectCard_autogen"
  )
endif()
