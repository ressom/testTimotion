#!/bin/bash

# load apps at startup by default
tmux has-session -t testAddonBoard
if [ $? != 0 ]; then

    tmux new-session -s testAddonBoard -n os -d
    tmux split-window -v -t testAddonBoard

    #run boot os for all device:
    tmux send-keys -t testAddonBoard:os.0 'cd /home/pi/testTimotion/deskApp/deskRep  && bash run.sh' C-m

    #run box control desk
    tmux send-keys -t testAddonBoard:os.1 'cd /home/pi/testTimotion/deskApp/upDownTest && bash run.sh' C-m

fi
