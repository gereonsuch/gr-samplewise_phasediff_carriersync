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

#ifndef INCLUDED_SAMPLEWISE_PHASEDIFF_CARRIERSYNC_PHASEDIFF_CARRIERSYNC_IMPL_H
#define INCLUDED_SAMPLEWISE_PHASEDIFF_CARRIERSYNC_PHASEDIFF_CARRIERSYNC_IMPL_H

#include <samplewise_phasediff_carriersync/phasediff_carriersync.h>
#include <complex>

namespace gr {
namespace samplewise_phasediff_carriersync {

class phasediff_carriersync_impl : public phasediff_carriersync
{
private:
    float d_alpha;
    float d_alphadiff;

    gr_complex d_phasediff;
    gr_complex d_phase;

    gr_complex d_lastval;

    void acquire_phase(const gr_complex *first, const gr_complex *second);

public:
    phasediff_carriersync_impl(float alpha, float initial_carrierfreq, float initial_phase);
    ~phasediff_carriersync_impl();

    // Where all the action really happens
    int work(int noutput_items,
             gr_vector_const_void_star &input_items,
             gr_vector_void_star &output_items);

    void set_alpha(float alpha);
    void set_carrierfreq(float carrierfreq);
    void set_phase(float phase);
};

} // namespace samplewise_phasediff_carriersync
} // namespace gr

#endif /* INCLUDED_SAMPLEWISE_PHASEDIFF_CARRIERSYNC_PHASEDIFF_CARRIERSYNC_IMPL_H */

