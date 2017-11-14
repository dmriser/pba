import os, glob 

env = Environment(ENV = {'PATH':os.environ['PATH']})
env.ParseConfig("root-config --glibs --cflags")
env.Append(CCFLAGS = ['-g','-std=c++11'])
env.Append(CPPPATH=['include/base/', 'include/producers/', 'include/aggregators/', 
				   'include/data/', 'include/processors/', 'include/external/', 
				   'include/config/'])


# build the library 
sources  = glob.glob('src/*/*.cxx')
env.SharedLibrary('lib/pba', sources)

