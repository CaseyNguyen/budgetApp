# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BudgetApp_autogen"
  "CMakeFiles\\BudgetApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BudgetApp_autogen.dir\\ParseCache.txt"
  )
endif()
