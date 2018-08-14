/* -*- c++ -*- */

#define SAMPLEWISE_PHASEDIFF_CARRIERSYNC_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "samplewise_phasediff_carriersync_swig_doc.i"

%{
#include "samplewise_phasediff_carriersync/phasediff_carriersync.h"
%}


%include "samplewise_phasediff_carriersync/phasediff_carriersync.h"
GR_SWIG_BLOCK_MAGIC2(samplewise_phasediff_carriersync, phasediff_carriersync);
