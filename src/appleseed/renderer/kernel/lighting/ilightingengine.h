
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2012 Francois Beaune, Jupiter Jazz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_RENDERER_KERNEL_LIGHTING_ILIGHTINGENGINE_H
#define APPLESEED_RENDERER_KERNEL_LIGHTING_ILIGHTINGENGINE_H

// appleseed.renderer headers.
#include "renderer/global/global.h"

// Forward declarations.
namespace renderer      { class AOVCollection; }
namespace renderer      { class ShadingContext; }
namespace renderer      { class ShadingPoint; }

namespace renderer
{

//
// Lighting engine interface.
//

class RENDERERDLL ILightingEngine
  : public foundation::IUnknown
{
  public:
    // Compute the lighting at a given point of the scene.
    virtual void compute_lighting(
        SamplingContext&        sampling_context,
        const ShadingContext&   shading_context,
        const ShadingPoint&     shading_point,
        Spectrum&               radiance,           // output radiance, in W.sr^-1.m^-2
        AOVCollection&          aovs) = 0;
};


//
// Interface of a ILightingEngine factory that can cross DLL boundaries.
// This means that classes implementing the ILightingEngineFactory interface
// must themselves be instantiated by a factory.
//

class RENDERERDLL ILightingEngineFactory
  : public foundation::IUnknown
{
  public:
    // Return a new sample lighting engine instance.
    virtual ILightingEngine* create() = 0;
};

}       // namespace renderer

#endif  // !APPLESEED_RENDERER_KERNEL_LIGHTING_ILIGHTINGENGINE_H
