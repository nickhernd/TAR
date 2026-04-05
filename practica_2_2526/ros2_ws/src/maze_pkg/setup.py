import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'maze_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'worlds'), glob('worlds/*.world')),
        (os.path.join('share', package_name, 'models', 'maze_1'), glob('models/maze_1/*.config') + glob('models/maze_1/*.sdf')),
        (os.path.join('share', package_name, 'models', 'maze_1', 'maze_1'), glob('models/maze_1/maze_1/*')),
        (os.path.join('share', package_name, 'models', 'maze_2'), glob('models/maze_2/*')),
        (os.path.join('share', package_name, 'models', 'maze_3'), glob('models/maze_3/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='nickhernd',
    maintainer_email='nickhernd@todo.todo',
    description='Maze solving with Turtlebot3 using LiDAR',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'res_maze = maze_pkg.res_maze:main',
            'pledge_maze = maze_pkg.pledge_maze:main',
        ],
    },
)
