all: Build.exe

object_files/main.o: ../src/main.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/main.cpp -o $(@)

object_files/entity.o: ../src/framework/entity.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/entity.cpp -o $(@)

object_files/component.o: ../src/framework/component.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/component.cpp -o $(@)

object_files/test_entity.o: ../src/framework/entities/test_entity.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/entities/test_entity.cpp -o $(@)

object_files/tilemap_entity.o: ../src/framework/entities/tilemap_entity.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/entities/tilemap_entity.cpp -o $(@)

object_files/scene.o: ../src/framework/scene.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/scene.cpp -o $(@)

object_files/misc.o: ../src/framework/misc.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/misc.cpp -o $(@)

object_files/health_component.o: ../src/framework/components/health_component.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/health_component.cpp -o $(@)

object_files/transform_component.o: ../src/framework/components/transform_component.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/transform_component.cpp -o $(@)

object_files/camera_component.o: ../src/framework/components/camera_component.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/camera_component.cpp -o $(@)

object_files/animation_component.o: ../src/framework/components/animation_component.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/components/animation_component.cpp -o $(@)

object_files/trails.o: ../src/framework/objects/trails.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/trails.cpp -o $(@)

object_files/sprites.o: ../src/framework/objects/sprites.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/sprites.cpp -o $(@)

object_files/particles.o: ../src/framework/objects/particles.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/particles.cpp -o $(@)

object_files/audio.o: ../src/framework/objects/audio.cpp
	g++ -O1 -Wall -Wno-missing-braces -I../src/framework/components/ -I../include/ -I../src/ -I../src/framework/ -I../src/framework/objects/ -I../src/framework/entities/ -c ../src/framework/objects/audio.cpp -o $(@)

Build.exe: object_files/main.o object_files/entity.o object_files/component.o object_files/test_entity.o object_files/tilemap_entity.o object_files/scene.o object_files/misc.o object_files/health_component.o object_files/transform_component.o object_files/camera_component.o object_files/animation_component.o object_files/trails.o object_files/sprites.o object_files/particles.o object_files/audio.o 
	g++ -o Build.exe object_files/main.o object_files/entity.o object_files/component.o object_files/test_entity.o object_files/tilemap_entity.o object_files/scene.o object_files/misc.o object_files/health_component.o object_files/transform_component.o object_files/camera_component.o object_files/animation_component.o object_files/trails.o object_files/sprites.o object_files/particles.o object_files/audio.o -L../lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

.PHONY: clean
clean:
	del /S /Q object_files\main.o
	del /S /Q object_files\entity.o
	del /S /Q object_files\component.o
	del /S /Q object_files\test_entity.o
	del /S /Q object_files\tilemap_entity.o
	del /S /Q object_files\scene.o
	del /S /Q object_files\misc.o
	del /S /Q object_files\health_component.o
	del /S /Q object_files\transform_component.o
	del /S /Q object_files\camera_component.o
	del /S /Q object_files\animation_component.o
	del /S /Q object_files\trails.o
	del /S /Q object_files\sprites.o
	del /S /Q object_files\particles.o
	del /S /Q object_files\audio.o
