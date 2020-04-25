Hints:-
-------------------------------------------------------------------
if you have already installed GStreamer 1.0 and libtool with apt-get.

these things you need to follow.

1.   gcc que3.c -o que3 `pkg-config --cflags --libs gstreamer-1.0`
2.  ./que3 home/shivam/Desktop/12.mp4

if it is showing gst/gst.h not found so, gst/gst.h is provided by libgstreamer1.0-dev.

Install it: sudo apt-get install libgstreamer1.0-dev

and if GStreamer is also not on the system, kindly run this command.

apt-get install libgstreamer1.0-0 gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-doc gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio

this will add all the necessary files for this code.