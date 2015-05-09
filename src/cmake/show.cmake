#
# Copyright (c) 2014 Nathan Clack, All Rights Reserved
#

macro(showhere)
    message("At ${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE}")
    message("At ${CMAKE_CURRENT_LIST_FILE}:${CMAKE_CURRENT_LIST_LINE}")
endmacro()

macro(show v)
  message("${v} is ${${v}}")
endmacro()

macro(showeach vs)
  message("${vs} is")
  foreach(v ${${vs}})
    message("   ${v}")
  endforeach()
endmacro()

macro(showprop type obj prop)
    get_property(v ${type} ${obj} PROPERTY ${prop})
    message("${prop} is ${v} for ${type} ${obj}")   
endmacro()

