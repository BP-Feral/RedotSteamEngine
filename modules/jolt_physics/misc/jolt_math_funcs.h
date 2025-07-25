/**************************************************************************/
/*  jolt_math_funcs.h                                                     */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             REDOT ENGINE                               */
/*                        https://redotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2024-present Redot Engine contributors                   */
/*                                          (see REDOT_AUTHORS.md)        */
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef JOLT_MATH_FUNCS_H
#define JOLT_MATH_FUNCS_H

#include "core/math/transform_3d.h"

class JoltMath {
public:
	// Note that `p_basis` is mutated to be right-handed orthonormal.
	static void decompose(Basis &p_basis, Vector3 &r_scale);

	// Note that `p_transform` is mutated to be right-handed orthonormal.
	static _FORCE_INLINE_ void decompose(Transform3D &p_transform, Vector3 &r_scale) {
		decompose(p_transform.basis, r_scale);
	}

	static _FORCE_INLINE_ void decomposed(const Basis &p_basis, Basis &r_new_basis, Vector3 &r_scale) {
		Basis new_basis = p_basis;
		decompose(new_basis, r_scale);
		r_new_basis = new_basis;
	}

	static _FORCE_INLINE_ void decomposed(const Transform3D &p_transform, Transform3D &r_new_transform, Vector3 &r_scale) {
		Transform3D new_transform;
		decompose(new_transform, r_scale);
		r_new_transform = new_transform;
	}
};

#endif // JOLT_MATH_FUNCS_H
