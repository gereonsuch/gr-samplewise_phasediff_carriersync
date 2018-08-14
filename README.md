# gr-samplewise_phasediff_carriersync

* Author:  Gereon Such
* Email:   gereonsuch@gmail.com
* Website: https://gereonsuch-sdr.com
* Project Name: Yeah, well.. you know, the good names were already taken

## Description

gr-samplewise_phasediff_carriersync is a GnuRadio Module with one block, which outputs the average carrier frequency of the input signal. This is mainly for research purpose

## Installation

If you found this you propably know how to install a GnuRadio OOT Module:

```console
$ git clone https://github.com/gereonsuch/gr-samplewise_phasediff_carriersync.git
$ cd gr-FDC
$ mkdir build
$ cd build
$ cmake .. && make && sudo make install && sudo ldconfig
```

## Usage

See the flowgraph in examples directory. alpha should be in range about [1e-2 .. 1e-5], otherwise the change might be too slow or malforming the signal itself. This is more or less trial and error, but alpha must not exceed 1. 

## Disclaimer

This is free software and no warranty whatsoever is given. Use and modify it responsibly. 
