from distutils.core import setup
from distutils.extension import Extension
setup(name='foobar',
      version='1.0',
      ext_modules=[Extension('foo', ['Hello.cpp'], 
                             include_dirs=[],
                             library_dirs=[],
                             libraries=['boost_python-mt', 'boost_thread-mt'])],
      )