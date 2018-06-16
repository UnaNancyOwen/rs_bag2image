rs_bag2image
============

This is convert tool that works on cross-platform (Windows, Linux, MacOS) for RealSense.  
This tool converts all data of each stream types (Color, Depth, Infrared) that contained in bag file to image file.  

Sample
------
### Command
```
rs_bag2image -b="./file.bag" -s=true -d=true
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

Environment
-----------
* Visual Studio 2015/2017 / GCC 5.3 / Clang (require <code>\<filesystem\></code> supported) 
* RealSense SDK 2.x (librealsense v2.x)
* OpenCV 3.4.0 (or later)
* CMake 3.7.2 (latest release is preferred)

License
-------
Copyright &copy; 2018 Tsukasa SUGIURA  
Distributed under the [MIT License](http://www.opensource.org/licenses/mit-license.php "MIT License | Open Source Initiative").

Contact
-------
* Tsukasa Sugiura  
    * <t.sugiura0204@gmail.com>  
    * <http://unanancyowen.com>  