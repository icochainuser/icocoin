
Debian
====================
This directory contains files used to package icocoind/icocoin-qt
for Debian-based Linux systems. If you compile icocoind/icocoin-qt yourself, there are some useful files here.

## icocoin: URI support ##


icocoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install icocoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your icocoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/icocoin128.png` to `/usr/share/pixmaps`

icocoin-qt.protocol (KDE)

