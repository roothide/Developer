#!/bin/bash

install_name_tool -delete_rpath /var/jb/usr/lib "$1"
install_name_tool -delete_rpath /var/jb/Library/Frameworks "$1"

install_name_tool -change @rpath/CydiaSubstrate.framework/CydiaSubstrate @loader_path/.jbroot/usr/lib/libsubstrate.dylib "$1"
install_name_tool -change /Library/Frameworks/CydiaSubstrate.framework/CydiaSubstrate @loader_path/.jbroot/usr/lib/libsubstrate.dylib "$1"

install_name_tool -change @rpath/libcolorpicker.dylib @loader_path/.jbroot/usr/lib/libcolorpicker.dylib "$1"
install_name_tool -change /usr/lib/libcolorpicker.dylib @loader_path/.jbroot/usr/lib/libcolorpicker.dylib "$1"

install_name_tool -change @rpath/Cephei.framework/Cephei @loader_path/.jbroot/usr/lib/Cephei.framework/Cephei "$1"
install_name_tool -change /Library/Frameworks/Cephei.framework/Cephei @loader_path/.jbroot/Library/Frameworks/Cephei.framework/Cephei "$1"

install_name_tool -change @rpath/CepheiPrefs.framework/CepheiPrefs @loader_path/.jbroot/usr/lib/CepheiPrefs.framework/CepheiPrefs "$1"
install_name_tool -change /Library/Frameworks/CepheiPrefs.framework/CepheiPrefs @loader_path/.jbroot/Library/Frameworks/CepheiPrefs.framework/CepheiPrefs "$1"

echo "dump entitlements"
ldid -e "$1" > /tmp/tmp.plist
echo "strating resign"
if [ ! -s /tmp/tmp.plist ]; then
    echo "no entitlements"
    ldid -S "$1"
else
    ldid -S/tmp/tmp.plist "$1"
    rm -f /tmp/tmp.plist
fi


