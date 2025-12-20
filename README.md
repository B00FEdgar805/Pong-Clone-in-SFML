# Pong clone using SFML

## Discription
This is a [Pong](https://en.wikipedia.org/wiki/Pong) clone implemented using [SFML 2.6.2](https://www.sfml-dev.org/download/sfml/2.6.2/) and C++. 
This Version uses only one olayer and you face a CPU. It can be easily changed to 2 players by sepreating the conterols in paddle movements and
and replacing the cpu logic with 2nd player movements in update. The controls are up arrow / W for up and down arrow / S for down. It also should be easy to run using CMake to build the project after cloning.  


## Screenshot

<img width="2560" height="1474" alt="image" src="https://github.com/user-attachments/assets/9363a9fb-e439-4d51-b76e-b2a93cd83314" />


## Video


https://github.com/user-attachments/assets/7a79c373-ba8f-4ad3-aa69-f4643ab5f384



## Requirements
 - C++ 11 compiler
 - SFML 2.6.2
 - CMake 3.16 or above

## How to Run

```
git clone https://github.com/B00FEdgar805/Pong-Clone-in-SFML
cd Pong-Clone-in-SFML
cd Pong
mkdir build
cd build
cmake ..
cmake --build . --config Release
./Pong
```
