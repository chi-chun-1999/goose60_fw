#!/bin/bash

get_script_dir()
{
    local SOURCE_PATH="${BASH_SOURCE[0]}"
    local SYMLINK_DIR
    local SCRIPT_DIR
    # Resolve symlinks recursively
    while [ -L "$SOURCE_PATH" ]; do
        # Get symlink directory
        SYMLINK_DIR="$( cd -P "$( dirname "$SOURCE_PATH" )" >/dev/null 2>&1 && pwd )"
        # Resolve symlink target (relative or absolute)
        SOURCE_PATH="$(readlink "$SOURCE_PATH")"
        # Check if candidate path is relative or absolute
        if [[ $SOURCE_PATH != /* ]]; then
            # Candidate path is relative, resolve to full path
            SOURCE_PATH=$SYMLINK_DIR/$SOURCE_PATH
        fi
    done
    # Get final script directory path from fully resolved source path
    SCRIPT_DIR="$(cd -P "$( dirname "$SOURCE_PATH" )" >/dev/null 2>&1 && pwd)"
    echo "$SCRIPT_DIR"
}


# In the following python code, I build the python virtual environment and install hidapi library. 
# Here is hidapi library link: https://pypi.org/project/hidapi/
# In the following code, I use the python executable located at ~/project/keyboard/bin/python3. Please modify it to your own python executable path.
sudo ~/project/keyboard/bin/python3 $(get_script_dir)/script/pc2pico.py
sleep 1
picotool load -v -x $(get_script_dir)/build/goose60_fw.uf2 -f
