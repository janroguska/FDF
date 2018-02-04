# FDF

A programme which takes a file containing an array of x, y, and z coordinates from the command line, and plots them as a wireframe model in 3D space.  The user can move, rotate, zoom in and out, and change the colour of the image from the keyboard.

# how it works

FDF takes a valid map from the command line, and projects the coordinates on the screen in 3D.  The file will look something like this:

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0

0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0

0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0

0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0

0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0

0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0

0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Once the image has been projected, the user can manipulate the projection by pressing the following keys:

* X-axis rotation: ◄ & ►
* Y-axis rotation: ▲ & ▼
* Z-axis rotation: 'w' & 's'
* Move around the screen: ↑, ↓, → & ←
* Zoom in & out: 'z' & 'x'
* Change wireframe colour: 'r', 'g' & 'b'
* Change background colour: 'p' & 'o'
