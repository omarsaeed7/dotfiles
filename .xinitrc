#!/bin/sh

# /etc/X11/xinit/xinitrc
#
# global xinitrc file, used by all X sessions started by xinit (startx)

# invoke global X session script

xrandr --output HDMI1 --primary --mode 1920x1080 --pos 0x0 --rotate normal --output eDP1 --mode 1920x1080 --pos 0x1080 --rotate normal &
while true; do
   xsetroot -name "$( date +"%F %R" ) افرد ظهرك عشان قلبك"
   sleep 1m    # Update time every minute
done &
setxkbmap -option grp:alt_shift_toggle us,ar &
sxhkd -c $HOME/.config/sxhkd/sxhkdrc &
~/.fehbg &
redshift &
exec dwm
