# X-Step

This repository contains most information pertaining to the development of X-Step, a thrust-vectored model rocket. It is important to note that NOT everything is published in this repository. If you hope to create something similar yourself, please seek additional guidance and take the necessary safety precautions.

**Some images of the rocket:**

![Rocket Image 1](/Images/Rocket/RocketIm2.png)
![Rocket Image 2](/Images/Rocket/RocketIm3.png)

## EVA Flight Computer

### The PCB

I designed the PCB using Fusion Electronics and had it manufactured by JLC PCB. It's a four layer board, which definitely made routing difficult given that the main IC is a BGA. For anyone thinking of creating their own PCB, I highly recommend staying away from BGAs in the beginning because it will save money and time for both building and designing the board. I'm currently in the process of getting the board assembled. Some features include:

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

The flight software uses a state system approach. When in the "powered flight" mode, the rocket is directly controlled using the IMU quaternion output and PID. I did not create a filter for this sensor data, as there's already one built in. I also verified and tuned my controller using simulink. I would highly reccomend anyone else to attempt to do the same.

Currently, if you take a look at the software files you will only see the quaternion library I created - that's because I'm not going to publish all software files to this repository. At least, not yet.

## The TVC Mount

Although I have already designed my own gimbaled mount, I wanted to try out something more simple, so lately I've been experimenting with a modified version of the [K-9 TVC Gimbal Gen 2](https://www.thingiverse.com/thing:4593287). See the image below.

![Gimbal Image 1](/Images/Gimbal/Gimbal1.png)

## Testing

I have yet to test the physical system altogether, but I hope to do so as soon as I get the PCB up and running.
