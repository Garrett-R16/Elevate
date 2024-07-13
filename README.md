# X-Step

This repository contains most information pertaining to the development of X-Step, a thrust-vectored model rocket. It is important to note that NOT EVERYTHING is published into this repository. If you hope to create something similar yourself, please seek guidance and take the necessary safety precautions.

Some images of the rocket:

![Rocket Image 1](/Images/Rocket/RocketIm1.png)
![Rocket Image 2](/Images/Rocket/RocketIm3.png)

## EVA Flight Computer

### The PCB

I designed the PCB using Fusion Electronics, and I got it manufactured at JLC PCB. I routed it on 4 layers, which was definitely difficult given that the main IC was a BGA. For anyone thinking of creating their own PCB, I would highly reccomend staying away from BGAs in  the beginning because it will save much money and time for both building and designing the board. I'm currently in the process of getting the board assembled. Some features include:

- An Arm Cortex-M7 IC
- BNO055 9-axis IMU
- TE MS5611 BPU
- 2 Pyro Channels
- 2 Servo Outputs
- Outputs for Bluetoogh communication

The board is still not completely finished, so I will try to update this regularly with how it goes. Below are some renders of how the board looks:

![PCB Image 1](/Images/Avionics/AvPCBR1.png)
![PCB Image 2](/Images/Avionics/AvPCBR2.png)

### The flight software

The flight software uses a state system approach. As for TVC, the rocket is controlled using a direct quaternion PID controller. The IMU comes with a built-in filter, so I didn't create one myself. Currently I am choosing not to publish all of the software files to this repository, so currently you will only see the quaternion library I created. I also verified and tuned my controller using simulink (hoping to create a video showcasing it). I would highly reccomend anyone else to attempt to do the same.

## The TVC Mount

Although I have already designed my own mount, I wanted to try out something more simple, so lately I've been experimenting with a modified version of the [K-9 TVC Gimbal Gen 2](https://www.thingiverse.com/thing:4593287). See the images below.

## Testing

I have yet to test the physical system altogether, but I hope to do so as soon as I get the PCB up and running.
