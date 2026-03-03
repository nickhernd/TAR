from setuptools import find_packages
from setuptools import setup

setup(
    name='interfaz_temp',
    version='0.0.0',
    packages=find_packages(
        include=('interfaz_temp', 'interfaz_temp.*')),
)
