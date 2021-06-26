#!/bin/sh

# ffmpeg -r 30 -i taf/frames/%06d.png video.mp4
ffmpeg -r 30 -s 1920x1080 -i taf/frames/%06d.png -vcodec libx264 -crf 25  -pix_fmt yuv420p video.mp4


