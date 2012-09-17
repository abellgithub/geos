/**********************************************************************
 * $Id$
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.refractions.net
 *
 * Copyright (C) 2009  Sandro Santilli <strk@keybit.net>
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation. 
 * See the COPYING file for more information.
 *
 ***********************************************************************
 *
 * Last port: operation/overlay/snap/SnapIfNeededOverlayOp.java rev 1.1
 * (JTS-1.10)
 *
 **********************************************************************/

#ifndef GEOS_OP_OVERLAY_SNAP_SNAPIFNEEDEDOVERLAYOP_H
#define GEOS_OP_OVERLAY_SNAP_SNAPIFNEEDEDOVERLAYOP_H

#include <geos/operation/overlay/OverlayOp.h> // for enums 

#include <memory> // for auto_ptr

// Forward declarations
namespace geos {
	namespace geom {
		class Geometry;
	}
}

namespace geos {
namespace operation { // geos::operation
namespace overlay { // geos::operation::overlay
namespace snap { // geos::operation::overlay::snap

/** \brief
 * Performs an overlay operation using snapping and enhanced precision
 * to improve the robustness of the result.
 *
 * This class only uses snapping
 * if an error is detected when running the standard JTS overlay code.
 * Errors detected include thrown exceptions
 * (in particular, {@link TopologyException})
 * and invalid overlay computations.
 *
 */
class SnapIfNeededOverlayOp
{

public:

	static std::auto_ptr<geom::Geometry>
	overlayOp(const geom::Geometry& g0, const geom::Geometry& g1,
	          OverlayOp::OpCode opCode)
	{
		SnapIfNeededOverlayOp op(g0, g1);
		return op.getResultGeometry(opCode);
	}

	static std::auto_ptr<geom::Geometry>
	intersection(const geom::Geometry& g0, const geom::Geometry& g1)
	{
		return overlayOp(g0, g1, OverlayOp::opINTERSECTION);
	}

	static std::auto_ptr<geom::Geometry>
	Union(const geom::Geometry& g0, const geom::Geometry& g1)
	{
		return overlayOp(g0, g1, OverlayOp::opUNION);
	}

	static std::auto_ptr<geom::Geometry>
	difference(const geom::Geometry& g0, const geom::Geometry& g1)
	{
		return overlayOp(g0, g1, OverlayOp::opDIFFERENCE);
	}

	static std::auto_ptr<geom::Geometry>
	symDifference(const geom::Geometry& g0, const geom::Geometry& g1)
	{
		return overlayOp(g0, g1, OverlayOp::opSYMDIFFERENCE);
	}

	SnapIfNeededOverlayOp(const geom::Geometry& g1, const geom::Geometry& g2)
		:
		geom0(g1),
		geom1(g2)
	{
	}

	
	typedef std::auto_ptr<geom::Geometry> GeomPtr;

	GeomPtr getResultGeometry(OverlayOp::OpCode opCode);

private:

	const geom::Geometry& geom0;
	const geom::Geometry& geom1;

    // Declare type as noncopyable
    SnapIfNeededOverlayOp(const SnapIfNeededOverlayOp& other);
    SnapIfNeededOverlayOp& operator=(const SnapIfNeededOverlayOp& rhs);
};
 

} // namespace geos::operation::overlay::snap
} // namespace geos::operation::overlay
} // namespace geos::operation
} // namespace geos

#endif // ndef GEOS_OP_OVERLAY_SNAP_SNAPIFNEEDEDOVERLAYOP_H

/**********************************************************************
 * $Log$
 **********************************************************************/
