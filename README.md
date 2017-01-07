This idea is to find Euler Bricks. Any Euler bricks that are primitive shall be a currency unit. The process will be difficult to manage, but it'll work eventually.
g++ -I /usr/local/openssl/include/ -std=c++14 BrickCoin.cpp EulerBrick.cpp EBVerify.cpp FNV.cpp main.cpp Multiplier.cpp Node.cpp Path.cpp PTriples.cpp SearchFunctions.cpp -lgmp -lgmpxx -o exe.out
