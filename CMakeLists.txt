cmake_minimum_required(VERSION 2.8)

project(wm)

include_directories(
        ${wm_SOURCE_DIR}/include
        ${wm_SOURCE_DIR}/src
)

set	(HEADER_FILES 	${wm_SOURCE_DIR}/include/planes_in_air.hpp
				 	${wm_SOURCE_DIR}/include/isPower4.hpp
				 	${wm_SOURCE_DIR}/include/rev_ll.hpp
				 	${wm_SOURCE_DIR}/include/reverse_num.hpp
				)

add_executable	(wmo 	${wm_SOURCE_DIR}/src/main.cpp 
						${wm_SOURCE_DIR}/src/planes_in_air.cpp
						${wm_SOURCE_DIR}/src/isPower4.cpp
						${wm_SOURCE_DIR}/src/rev_ll.cpp
						${wm_SOURCE_DIR}/src/reverse_num.cpp
						${HEADER_FILES}
				 )
