# function(target_generate_hex TARGET)
#   set (EXEC_OBJ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET})
#   set (HEX_OBJ ${EXEC_OBJ}.hex)

#   set_target_properties(${TARGET} PROPERTIES HEX_FILE ${HEX_OBJ})

#   add_custom_command(OUTPUT ${HEX_OBJ}
#       COMMAND ${CMAKE_OBJCOPY} -O ihex ${EXEC_OBJ} ${HEX_OBJ}
#       DEPENDS ${TARGET}
#   )

#   add_custom_target (${TARGET}.hex DEPENDS ${HEX_OBJ})
# endfunction(target_generate_hex)

# FIXME TO CHECK IF IT WORKS
macro(target_generate_hex TARGET)
    add_custom_target(${TARGET}-hex
        ALL
        COMMAND
            ${CMAKE_OBJCOPY} -O ihex
                $<TARGET_FILE:${TARGET}>
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET}.hex
    )
    add_dependencies(${TARGET}-hex
        ${TARGET}
    )
endmacro()

# FIXME GET RIDOF EXTRA FUNCTIONS
macro(target_generate_bin TARGET)
    add_custom_target(${TARGET}-bin
        ALL
        COMMAND
            ${CMAKE_OBJCOPY} -R .boot_params -O binary
                $<TARGET_FILE:${TARGET}>
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET}.bin
    )
    add_dependencies(${TARGET}-bin
        ${TARGET}
    )
endmacro()

# function(target_generate_bin TARGET)
#   set (EXEC_OBJ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TARGET})
#   set (BIN_OBJ ${EXEC_OBJ}.bin)

#   set_target_properties(${TARGET} PROPERTIES BIN_FILE ${BIN_OBJ})

#   add_custom_command(OUTPUT ${BIN_OBJ}
#       COMMAND ${CMAKE_OBJCOPY} -R .boot_params -O binary ${EXEC_OBJ} ${BIN_OBJ}
#       DEPENDS ${TARGET}
#   )

#   add_custom_target (${TARGET}.bin DEPENDS ${BIN_OBJ})
# endfunction(target_generate_bin)

function(target_jlink_flash TARGET BASE_ADDRESS)
  set(COMMAND_FILE ${CMAKE_BINARY_DIR}/jlink/${TARGET}.flash.jlink)

  get_property(FLASH_FILE TARGET ${TARGET} PROPERTY HEX_FILE)

  if("${FLASH_FILE}" STREQUAL "")
      get_property(FLASH_FILE TARGET ${TARGET} PROPERTY BIN_FILE)
  endif()
  
  configure_file(${CMAKE_SOURCE_DIR}/jlink/flash.jlink.template ${COMMAND_FILE})

  unset(FLASH_FILE)

  set(JLINK_ARGS 
      "-device" ${DEVICE}
      "-ExitOnError"
      "-CommanderScript" ${COMMAND_FILE}
  )

  if(NOT ${JLINK_SN} STREQUAL "")
      list(APPEND JLINK_ARGS -SelectEmuBySN ${JLINK_SN})
  endif()
  
  add_custom_target(${TARGET}.flash    
    COMMAND ${JLINK} ${JLINK_ARGS}
    DEPENDS ${FLASH_FILE}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  )

endfunction(target_jlink_flash)


macro(target_memory_report TARGET)
    add_custom_command(TARGET ${TARGET}
        POST_BUILD
            COMMAND
                ${CMAKE_GCC_SIZE} --format=sysv --radix=16 $<TARGET_FILE:${TARGET}>
    )
endmacro()


function(target_asm_listing TARGET)
    get_property(binary TARGET ${TARGET} PROPERTY RUNTIME_OUTPUT_NAME)

    add_custom_target(${TARGET}.asm
        COMMAND ${CMAKE_COMMAND} -E make_directory ${REPORTS_PATH}
        COMMAND ${CMAKE_OBJDUMP} -dSC $<TARGET_FILE:${TARGET}> > ${REPORTS_PATH}/${TARGET}.lss
        DEPENDS ${TARGET}
    )
endfunction(target_asm_listing)