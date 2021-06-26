#!/bin/sh

ffmpeg -r 30 -s 1920x1080 -i taf/frames/%06d.png -vcodec libx264 -crf 25  -pix_fmt yuv420p bounce.mp4
ffmpeg -i bounce.mp4 bounce.gif

