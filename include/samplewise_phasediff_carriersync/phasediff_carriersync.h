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


#ifndef INCLUDED_SAMPLEWISE_PHASEDIFF_CARRIERSYNC_PHASEDIFF_CARRIERSYNC_H
#define INCLUDED_SAMPLEWISE_PHASEDIFF_CARRIERSYNC_PHASEDIFF_CARRIERSYNC_H

#include <samplewise_phasediff_carriersync/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace samplewise_phasediff_carriersync {

    /*!
     * \brief <+description of block+>
     * \ingroup samplewise_phasediff_carriersync
     *
     */
    class SAMPLEWISE_PHASEDIFF_CARRIERSYNC_API phasediff_carriersync : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<phasediff_carriersync> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of samplewise_phasediff_carriersync::phasediff_carriersync.
       *
       * To avoid accidental use of raw pointers, samplewise_phasediff_carriersync::phasediff_carriersync's
       * constructor is in a private implementation
       * class. samplewise_phasediff_carriersync::phasediff_carriersync::make is the public interface for
       * creating new instances.
       */
      static sptr make(float alpha, float initial_carrierfreq, float initial_phase);
    };

  } // namespace samplewise_phasediff_carriersync
} // namespace gr

#endif /* INCLUDED_SAMPLEWISE_PHASEDIFF_CARRIERSYNC_PHASEDIFF_CARRIERSYNC_H */

