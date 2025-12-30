# include_directories(
#   ${CMAKE_CURRENT_SOURCE_DIR}
#   ${CMAKE_CURRENT_BINARY_DIR}
# )
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmonad.h.in 
  ${CMAKE_CURRENT_BINARY_DIR}/cmonad.h 
  @ONLY
)


# add_library(worker OBJECT worker.c worker.h)
# add_library(
#   ${PRJ}
#   STATIC
#   $<TARGET_OBJECTS:null>
#   $<TARGET_OBJECTS:addr>
#   $<TARGET_OBJECTS:blob>
#   $<TARGET_OBJECTS:buffring>
#   $<TARGET_OBJECTS:tun>
#   $<TARGET_OBJECTS:sig>
#   $<TARGET_OBJECTS:socket>
#   $<TARGET_OBJECTS:server>
#   $<TARGET_OBJECTS:worker>
# )
# target_link_libraries(
#   ${PRJ}
#   uring
#   clog
#   mrb
# )
