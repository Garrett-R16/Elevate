# Elevate

This repository contains most information pertaining to the development of Elevate, a thrust-vectored model rocket. It is important to note that NOT everything is published in this repository. If you hope to create something similar yourself, please seek additional guidance and take the necessary safety precautions.

**Some images of the rocket:**

![Rocket Image 1](/Images/Rocket/RocketIm2.png)
![Rocket Image 2](/Images/Rocket/RocketIm3.png)

## EVA Flight Computer

### The PCB

I designed the PCB using Fusion Electronics and had it manufactured by JLC PCB. It's a four layer board, which definitely made routing difficult given that the main IC is a BGA. For anyone thinking of creating their own PCB, I highly recommend staying away from BGAs in the beginning because it will save money and time for both building and designing the board. Some features include:

- Arm Cortex-M7 IC
- BNO055 9-axis IMU
- TE MS5611 BPU
- 2 Pyro Channels
- 2 Servo Outputs
- Outputs for Bluetooth communication
- 5V 3.5A Buck Converter

So far, testing has gone well. The board works as intended except for the lack of pull-up resistors on the SDA/SCL lines, which sometimes cause outliers in sensor data. If you want to learn more about the EVA, check out [the video I made detailing the design process.](https://www.youtube.com/watch?v=PTA0meSgiaA&t=280s) I'm currently also developing a new flight computer in Altium Designer that will fix this and incorporate additional functionality.

Below are some renders of the board:

![PCB Image 1](/Images/Avionics/AvPCBR1.png)
![PCB Image 2](/Images/Avionics/AvPCBR2.png)

### The flight software

The flight software uses a state system approach. When in the "powered flight" mode, the rocket is directly controlled using the IMU quaternion output and PID (technically according to the paper below, it's a non-linear P<sup>2</sup> + I controller, but they are quite similar). My initial approach to a direct-quaternion PID controller was quite similar to the one described by Emil Fresk and George Nikolakopoulos in their paper, ["Full Quaternion Based Attitude Control for a Quadrotor"](https://ieeexplore.ieee.org/document/6669617). However, I ran into some cases where the rocket wouldn't take the optimal path because it didn't have roll authority. After researching, I found another method which I detail in my video on ["Controlling a Rocket with IMAGINARY Numbers"](https://youtu.be/aRvSZJIa1yA). In this video, I also compare the two methods side by side using Simulink and a 6DoF Animation block.

I did not create a filter for this sensor data, as there's already one built into the IMU. I also verified and tuned my controller using simulink. I would highly reccomend anyone else to attempt to do the same.

Currently, if you take a look at the software files you will only see the quaternion library I created - that's because I'm not going to publish all software files to this repository. At least, not yet.

## The TVC Mount

Although I have already designed [my own gimbaled mount](https://github.com/Garrett-R16/TVC_Mount), I wanted to try out something more simple, so I first experimented with a modified version of the [K-9 TVC Gimbal Gen 2](https://www.thingiverse.com/thing:4593287). See the image below.

![Gimbal Image 1](/Images/Gimbal/Gimbal1.png)

After my first flight, I noticed many issues with the mount, so I decided to redesign it myself. I'm currently testing it and have high hopes for the next flight of Elevate. See below for a picture.

![Gimbal Image 2](/Images/Gimbal/gimbalV2.png)

## Testing

UPDATE: I recently launched the rocket! Twice, actually. For more information, check out [the video I created.](https://youtu.be/ULjHmWELAEA)
