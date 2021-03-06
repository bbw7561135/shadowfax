/*******************************************************************************
 * This file is part of Shadowfax
 * Copyright (C) 2015 Bert Vandenbroucke (bert.vandenbroucke@gmail.com)
 *
 * Shadowfax is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Shadowfax is distributed in the hope that it will be useful,
 * but WITOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with Shadowfax. If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

/**
 * @file Output.hpp
 *
 * @brief Old interface for snapshot writers: header
 *
 * This interface is still used by ShadowfaxSnapshotWriter.
 *
 * @author Bert Vandenbroucke (bert.vandenbroucke@ugent.be)
 */
#ifndef OUTPUT_HPP
#define OUTPUT_HPP

class Block;
class Header;

/**
  * @brief Interface for data output
  *
  * Data is organized in blocks, which are a kind of tables with column names
  * and rows of data. Extra information is provided through a Header.
  */
class Output {
  public:
    /**
      * @brief Output a Block
      *
      * All information in the header of the Block and all actual data is
      * guaranteed to be outputted. Extra information (e.g. units) may or may
      * not be outputted depending on the implementation.
      *
      * @param block Block to write out
      */
    virtual void write(Block& block) = 0;

    /**
      * @brief Output a Header
      *
      * What information is outputted is implementation dependant.
      *
      * @param header Header to write out
      */
    virtual void write_header(Header& header) = 0;
};

#endif  // OUTPUT_HPP
