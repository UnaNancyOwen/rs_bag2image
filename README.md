rs_bag2image
============

![Graphic Overview](header.png)

This is convert tool that works on cross-platform (Windows, Linux, MacOS) for RealSense.  
This tool converts all data of each stream types (Color, Depth, Infrared) that contained in bag file to image file.  

## Prerequisites
Before you begin, ensure you have met the following requirements:

* You have a **Linux/Mac/Windows** machine with a recent version of compatible OS.
* You have installed the following software:
  * RealSense SDK 2.x (librealsense v2.x) - [Installation Guide](https://github.com/IntelRealSense/librealsense/blob/master/doc/installation.md)
  * OpenCV 3.4.0 (or later) - [Installation Guide](https://docs.opencv.org/4.5.3/d7/d9f/tutorial_linux_install.html)
  * CMake 3.7.2 (or later) - You can install it using: `sudo apt install cmake`
  * GCC 5.3 (or later) - You can install it using `sudo apt install build-essential`

## Installing rs_bag2image

To install rs_bag2image, follow these steps:

1. Clone the repo: `git clone https://github.com/UnaNancyOwen/rs_bag2image`
2. Navigate to the cloned repository: `cd rs_bag2image`
3. Create a new directory for the build: `mkdir build && cd build`
4. Use CMake to generate the makefile: `cmake ..`
5. Build the project: `make`

## Using rs_bag2image

```bash
./rs_bag2image -b="/path/to/your/file.bag" -s=true -d=true
```
### Output
```
rs_bag2image.exe
file.bag
file
  |-Color
  |   |-000001.jpg
  |   |-000002.jpg
  |
  |-Depth
  |   |-000001.png
  |   |-000002.png
  |
  |-Infrared 1
  |   |-000001.jpg
  |   |-000002.jpg
```

Option
------
| option | description                                                                           |
|:------:|:--------------------------------------------------------------------------------------|
| -b     | input bag file path. (requered)                                                       |
| -s     | enable depth scaling for visualization. <code>false</code> is raw 16bit image. (bool) |
| -q     | jpeg encoding quality for color and infrared. [0-100]                                 |
| -d     | display each stream images on window. <code>false</code> is not display. (bool)       |

License
-------
Copyright &copy; 2018 Tsukasa SUGIURA  
Distributed under the [MIT License](http://www.opensource.org/licenses/mit-license.php "MIT License | Open Source Initiative").

Contact
-------
* Tsukasa Sugiura  
    * <t.sugiura0204@gmail.com>  
    * <http://unanancyowen.com>  