project('limiter', 'c',
  version: '0.1',
  license: 'GPL')

inc = include_directories('include')
subdir('include')
subdir('lib')
subdir('src')
subdir('test')

pkg = import('pkgconfig')

pkg.generate(	 
  version : '0.1',
  name : 'liblimiter',
  filebase  : 'limiter',
  description: 'Limits a number to a specified range',
  libraries: [limiterlib]
  )

