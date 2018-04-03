from distutils.core import setup
setup(name='ICOspendfrom',
      version='1.0',
      description='Command-line utility for icocoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@icocoinfoundation.org',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
