# CMakeList.txt : CMake project for GNDOBDH, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (GNDOBDH "GNDOBDH.cpp" "GNDOBDH.h" "SendCommand.cpp" "SendCOmmand.h" "GetCommand.cpp" "GetCommand.h" "printTM_and_log.cpp" "printTM_and_log.h" "check_command.cpp" "check_command.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GNDOBDH PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
