/**
 * Mandelbulber v2, a 3D fractal generator  _%}}i*<.         ______
 * Copyright (C) 2020 Mandelbulber Team   _>]|=||i=i<,      / ____/ __    __
 *                                        \><||i|=>>%)     / /   __/ /___/ /_
 * This file is part of Mandelbulber.     )<=i=]=|=i<>    / /__ /_  __/_  __/
 * The project is licensed under GPLv3,   -<>>=|><|||`    \____/ /_/   /_/
 * see also COPYING file in this folder.    ~+{i%+++
 *
 * Adds to z the spherical inversion of z
 */

#include "all_fractal_definitions.h"

cFractalTransfAddSphericalInvert::cFractalTransfAddSphericalInvert() : cAbstractFractal()
{
	nameInComboBox = "T>Add Spherical Invert";
	internalName = "transf_add_spherical_invert";
	internalID = fractal::transfAddSphericalInvert;
	DEType = analyticDEType;
	DEFunctionType = withoutDEFunction;
	cpixelAddition = cpixelDisabledByDefault;
	defaultBailout = 100.0;
	DEAnalyticFunction = analyticFunctionNone;
	coloringFunction = coloringFunctionDefault;
}

void cFractalTransfAddSphericalInvert::FormulaCode(
	CVector4 &z, const sFractal *fractal, sExtendedAux &aux)
{
	CVector4 t = z;
	aux.r = 1.0 / t.Dot(t);
	CVector4 g = fractal->transformCommon.scale3D111;
	t *= g * aux.r;
	aux.DE += 1.0 / aux.DE;
	z = (z + t) * fractal->transformCommon.scaleB1;
	aux.DE *= fractal->transformCommon.scaleB1;

	if (fractal->analyticDE.enabledFalse)
	{
		aux.DE = aux.DE * fractal->analyticDE.scale1 + fractal->analyticDE.offset0;
	}
}
