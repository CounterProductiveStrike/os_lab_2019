./server --port 3333 --tnum 2 &
./server --port 4444 --tnum 2 &
./server --port 5555 --tnum 2 &
./client --k 8 --mod 130 --servers servers.txt