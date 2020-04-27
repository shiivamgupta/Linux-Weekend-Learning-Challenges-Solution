How can i access usb pen drive connected on your machine  inside qemu

Please reply to this email with your solution.

Solution:-

A. Using qemu-kvm command line
--------------------------------------------------------------------- 
Let us suppose the device you connect having bus 002 and device 003
so we will be using qemu-kvm command line
#/usr/bin/qemu-kvm -m 1024 -name f15 -drive file=/images/f15.img,if=virtio -usb -device usb-host,hostbus=2,hostaddr=3

now we can verify this in the guest
$ lspci
$ lsusb
now done.  

B. Using Virt-manager-
---------------------------------------------------------
Just right click on the virtual machine (virt-manager)
now click on the BULB symbol
Insert your pen drive in your laptop.
wait for detect
now click on add hardware.
click on USB HOST DEVICE
select your pendrive from the list and finish
now task done.
click on controller USB
click on default and changes it as USB 2
apply ok and finish.
now run machine and you can access the usb drive.
