add_library (Src 
             Tuple.cpp Tuple.h
             Colour.cpp Colour.h 
             Canvas.cpp Canvas.h
             Matrix.cpp Matrix.h
             Ray.cpp Ray.h
             Sphere.cpp Sphere.h
             Shape.h
             )
target_link_libraries (Src)