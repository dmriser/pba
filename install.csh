#/bin/tcsh 

# compiling libraries 
scons 

# moving to dest
cp lib/*.so         $h22libs/lib/
cp include/*/*.h    $h22libs/include/
