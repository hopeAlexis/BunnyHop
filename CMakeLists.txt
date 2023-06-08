cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произойдёт аварийный выход.

set(PROJECT_NAME BunnyHop)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("ext/SFML/include/")	# добавляем директории
include_directories("inc/")
link_directories("ext/SFML/lib/")
include_directories("assets/")	

add_executable("${PROJECT_NAME}"
								sound_player.hpp
								sound_player.cpp
								bunny_animator.hpp
								bunny_animator.cpp
								timer.hpp
								timer.cpp
								bunny.cpp
								bunny.hpp
								game.hpp
								game.cpp
								main.cpp)
											
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
						  sfml-window-s-d
						  sfml-system-s-d
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s-d
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)
file(COPY "assets/" DESTINATION "assets/")