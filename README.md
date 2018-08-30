# A badly hacked fork of the PX4 Pro Drone Autopilot Firmware

## See https://github.com/PX4/Firmware for the original

## Use case

This px4 fork is designed to work with the [mav_control_rw](https://github.com/ethz-asl/mav_control_rw) ros nodes in combination with our hacked [mavros version](https://github.com/ethz-asl/mavros)
## Changes

### Filtering
* The highrate IMU topic has a 10 Hz butterworth filter applied to it.

### Control
* In offboard mode desired yaw is ignored allowing the sending of roll, pitch yawrate commands.

### Safety
* The kill switch also disarms the system
* Arming also controls the aux ports

### IO
* Highres IMU is published at 100 Hz
* Most non-esential messages are broadcast at a much reduced rate
