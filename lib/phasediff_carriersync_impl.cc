/* -*- c++ -*- */
/* 
 * Copyright 2018 Gereon Such.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "phasediff_carriersync_impl.h"

namespace gr {
namespace samplewise_phasediff_carriersync {

phasediff_carriersync::sptr
phasediff_carriersync::make(float alpha, float initial_carrierfreq, float initial_phase)
{
    return gnuradio::get_initial_sptr
            (new phasediff_carriersync_impl(alpha, initial_carrierfreq, initial_phase));
}

/*
     * The private constructor
     */
phasediff_carriersync_impl::phasediff_carriersync_impl(float alpha, float initial_carrierfreq, float initial_phase)
    : gr::sync_block("phasediff_carriersync",
                     gr::io_signature::make(1, 1, sizeof(gr_complex)),
                     gr::io_signature::make(1, 1, sizeof(gr_complex)))
{
    set_alpha(alpha);
    set_carrierfreq(initial_carrierfreq);
    set_phase(initial_phase);

    d_lastval=gr_complex(1.0f, 0.0f);
}

/*
     * Our virtual destructor.
     */
phasediff_carriersync_impl::~phasediff_carriersync_impl()
{
}

void phasediff_carriersync_impl::set_alpha(float alpha){
    d_alpha=std::abs(alpha);
    d_alphadiff=1.0f-d_alpha;
}

void phasediff_carriersync_impl::set_carrierfreq(float carrierfreq){
    d_phasediff=gr_complex(1.0f, carrierfreq);
}

void phasediff_carriersync_impl::set_phase(float phase){
    d_phase=gr_complex(1.0f, phase);
}

void phasediff_carriersync_impl::acquire_phase(const gr_complex *current, const gr_complex *old){
    gr_complex curdiff=*current / *old;

    //get phasedifference from last sample and add to current phase.
    d_phasediff=d_alphadiff * d_phasediff + d_alpha * curdiff/std::abs(curdiff);
    d_phase*=d_phasediff;

    //normalization to minimize numerical fluctuation for subsequent iterations
    d_phasediff/=std::abs(d_phase);
    d_phase/=std::abs(d_phase);
}

int
phasediff_carriersync_impl::work(int noutput_items,
                                 gr_vector_const_void_star &input_items,
                                 gr_vector_void_star &output_items)
{
    //since history=1, in has always one item more than out
    const gr_complex *in = (const gr_complex *) input_items[0];
    gr_complex *out = (gr_complex *) output_items[0];

    //hard saving of history in a puffer to prevent runtime problems with asynchronity
    if(noutput_items==0)
        return 0;

    acquire_phase(in, &d_lastval);
    out[0]=std::conj(d_phase);

    for(int i=1;i<noutput_items;i++){
        acquire_phase(in+i, in+i-1);

        //output carriersynced input samples
        out[i]=std::conj(d_phase);
    }

    d_lastval=in[noutput_items-1]; //save last sample

    return noutput_items;
}

} /* namespace samplewise_phasediff_carriersync */
} /* namespace gr */

