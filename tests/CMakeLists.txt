################################################################################
# Part of CMake configuration for GEOS
#
# Copyright (C) 2018 Mateusz Loskot <mateusz@loskot.net>
#
# This is free software; you can redistribute and/or modify it under
# the terms of the GNU Lesser General Public Licence as published
# by the Free Software Foundation.
# See the COPYING file for more information.
################################################################################
add_custom_target(check COMMAND ctest)

add_subdirectory(unit)
add_subdirectory(xmltester)
add_subdirectory(bigtest)

# perf tests are built but not run by default
add_subdirectory(perf)
