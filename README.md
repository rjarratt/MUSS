# MUSS
MUSS is the Manchester University Software System. It is an operating system that was designed and built at Manchester University
for MU5. It was designed to be portable, and was ported to MU6-G, PDP-11, VAX and MC68000. Some computer manufacturers of the time
also took an interest.

A tape of source code was recovered in April 2018, there is more about the story [here](https://robs-old-computers.com/2018/05/03/muss-source-code/).
The source code has now been published [here](https://rjarratt.files.wordpress.com/2018/07/muss-tar.zip).

The long term aim of this project is to get MUSS running once more. Since the recovered source code is from the post-MU5 era, the most
likely target is the PDP-11 or VAX. it is not clear how easy it will be to get it to run on the
[MU5 emulator](https://robs-old-computers.com/projects/mu5/).

The initial effort is to use Flex/Bison to build an implementation of FLIP. At first the intention was then to use this to translate the Flocoder
files into compilable MUSL source code, and to use Flex/Bison to build a MUSL to C compiler that can be used on the MUSL generated from
Flocoder to compile the MUSL source of Flocoder to C.

However I struggled to get MUSL to fit the Flex/Bison capabilities. So I have now changed tack. Instead I am going to add new sections to the
Flocoder for the MUSL compiler targetting C directly. In other words I am going to hand translate the MUSL compiler source to C and use my
implementation of FLIP to generate a MUSL compiler written in C.

The directories in this repository are:

* Flocoder. This is the Flex/Bison implementation of FLIP. It also contains the Flocoder sources for FLIP.
* MUSL. This is the aborted attempt to implement a MUSL compiler with Flex/Bison. It also contains the Flocoder sources for MUSL with the C implementation.
