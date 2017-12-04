libSDL="-L/usr/local/Cellar/sdl2/2.0.5/lib/"
libSDLImage="-L/usr/local/Cellar/sdl2_image/2.0.1_3/lib/"
libSDLTTF="-L/usr/local/Cellar/sdl2_ttf/2.0.14/lib"
libSDLMixer="-L/usr/local/Cellar/sdl2_mixer/2.0.1_1/lib"
linkSDK="-lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_ttf -lSDL2_image -framework OpenGL"
incSDL="-I/usr/local/Cellar/sdl2/2.0.5/include/SDL2/ -DPLATFORM_OSX -DUSE_SDL_2"
objs="./doc_sdl2/sdl2_event/*.o"

#libSDL="-L/usr/local/Cellar/sdl/1.2.15/lib"
#libSDLImage="-L/usr/local/Cellar/sdl_image/1.2.12_7/lib/"
#libSDLTTF="-L/usr/local/Cellar/sdl_ttf/2.0.11_1/lib/"
#libSDLMixer="-L/usr/local/Cellar/sdl_mixer/1.2.12_2/lib/"
#linkSDK="-lSDLmain -lSDL -lSDL_mixer -lSDL_ttf -lSDL_image -framework OpenGL -framework Cocoa"
#incSDL="-I/usr/local/Cellar/sdl/1.2.15/include/SDL/ -DPLATFORM_OSX -DUSE_SDL_1"
#objs="./doc_sdl2/sdl1_event/*.o"

gcc -c libhello.c -o libhello.o -I/usr/local/Cellar/dart/2.0.0-dev.8.0/libexec/ ${incSDL}
gcc -fpic -shared -o libhello.dylib libhello.o ${objs} -dynamiclib -undefined dynamic_lookup -DDART_SHARED_LIB=1 ${libSDL} ${libSDLImage} ${libSDLTTF} ${libSDLMixer} ${linkSDK}
