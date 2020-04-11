Where is GLib from and why does it exist? Who uses it, and for what? Would it have been better if they had given it a name less likely to be confused with glibc?

* GLib is a general purpose utility library for C developed by GNOME. It provides advanced data structures,  portability wrappers, and interfaces for such runtime functionality as an event loop, threads, dynamic loading, and an object system.

What are the most important pros and cons of using GLib, as opposed to another library, or just using core C features?

* GLib is a cross-platform library so applications using it to interface with the operating system are usually portable across different operating systems.
It ensures consistent behaviors, so people use it because of portability.

What do you have to do to compile and run a "Hello GLib" example?
```
cc hello.c `pkg-config --cflags --libs glib-2.0` -o hello
```
