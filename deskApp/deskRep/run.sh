#!/usr/bin/env bash
#add current path to PATH
export PATH=$PATH:$PWD
# Detect Serial device files
# 
dataFile="data.dat"
os="none"
#Detect which board to run
if  uname -m  | grep x86_64  ; then
	if [ -e "/dev/ttyUSB0" ] ; then
        	sudo chmod 777 /dev/ttyUSB0
        	echo "detect /dev/ttyUSB0"
	fi
	os="x64"
	device="/dev/ttyUSB0"
	echo "use device $device"
	echo "Detected $os "
fi

if uname -m |grep arm ; then
	if [ -e "/dev/ttyS0" ] ; then
        	sudo chmod 777 /dev/ttyS0
        	sudo chmod a+rw /sys/class/backlight/rpi_backlight/bl_power
        	sudo chmod a+rw /sys/class/backlight/rpi_backlight/brightness
        	echo "Detected /dev/ttyS0"
	fi
	if [ -e "/dev/serial0" ] ; then
        	sudo chmod 777 /dev/serial0
        	echo "Detected /dev/serial0"
	fi
	os="RPI"
	device="/dev/ttyS0"
	echo "use device $device"
	echo "Detected Arm Board"
fi
# Check if the data.mat file is exist.
if [ -f "$dataFile" ] ; then
#Detct the Control Box type in data.mat	
	if  grep -q "Timotion" "data.dat" 
	#Timotion Control Box Detected
	then
		echo "Selected Timotion Box"
		if [ -f "TimotionV1/user/$os/deskrep" ] ; then
			sudo chmod +x  TimotionV1/user/$os/deskrep
			if  ps -ax |grep deskrep | grep -v grep  ; then
				echo "App is runnig"
			else
				./TimotionV1/user/$os/deskrep $device
			fi
		else
			echo "/TimotionV1/user/$os/deskrep not found "
		fi
	else
		if grep -q "Jiecang" "data.dat"
		#Jiecang Box control Box detected
		then
			echo "Selected Jiecang Box"
			if [ -f "Jiecang/user/$os/deskrep" ] ; then
				sudo chmod +x Jiecang/user/$os/deskrep
				if ps -ax |grep deskrep | grep -v grep  ; then
					echo "App is runnig"
				else
					./Jiecang/user/$os/deskrep $device
				fi
				
			else
				echo "/Jiecang/user/$os/deskrep not found"
			fi
		else
			if grep -q "AddonBoard" "data.dat"
			# AddonBoard Controller Detected
			then
				echo "selected AddonBoard"
				if [ -f "AddonBoard/user/$os/deskrep" ] ; then
					sudo chmod +x AddonBoard/user/$os/deskrep
					if ps -ax |grep deskrep | grep -v grep  ; then
						echo "App is runnig"
					else
						./AddonBoard/user/$os/deskrep $device
					fi
				else
					echo "/AddonBoard/user/$os/deskrep not found"
				fi
			fi
		fi
	fi
else
	echo "$dataFile not Found"
fi
