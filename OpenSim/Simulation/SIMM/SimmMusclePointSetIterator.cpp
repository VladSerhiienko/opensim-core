// SimmMusclePointSetIterator.cpp
// Author: Peter Loan
/*
 * Copyright (c) 2006, Stanford University. All rights reserved. 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

//=============================================================================
// INCLUDES
//=============================================================================
#include "SimmMusclePointSetIterator.h"
#include "SimmMusclePoint.h"
#include "SimmMusclePointSet.h"

//=============================================================================
// STATICS
//=============================================================================
using namespace std;
using namespace OpenSim;

//=============================================================================
// CONSTRUCTOR(S) AND DESTRUCTOR
//=============================================================================
SimmMusclePointSetIterator::SimmMusclePointSetIterator(SimmMusclePointSet& aSimmMusclePointSet) :
	AttachmentPointIterator(),
	_simmMusclePointSet(aSimmMusclePointSet)
{
}

//_____________________________________________________________________________
/**
 * Destructor.
 */
SimmMusclePointSetIterator::~SimmMusclePointSetIterator()
{
}

//=============================================================================
// ITERATION
//=============================================================================
//_____________________________________________________________________________
/**
 * Determines if iterator is at the end.
 *
 * @return Whether or not iterator is finished.
 */
bool SimmMusclePointSetIterator::finished() const
{
	if (_counter >= _simmMusclePointSet.getSize())
		return true;

	return false;
}

//_____________________________________________________________________________
/**
 * Get current muscle point, without advancing the iterator.
 *
 * @return SimmMusclePoint that iterator currently points to.
 */
SimmMusclePoint* SimmMusclePointSetIterator::getCurrent()
{
	// TODO: what happens when wrap objects are added? Do wrap points get
	// inserted into the set, or are they stored elsewhere?
	if (_counter >= 0)
	{
		while (_counter < _simmMusclePointSet.getSize())
		{
			SimmMusclePoint* smp = _simmMusclePointSet.get(_counter);
			if (smp->isActive())
				return smp;
			_counter++;
		}
	}

	return NULL;
}

//_____________________________________________________________________________
/**
 * Get current muscle point and advance iterator to next one.
 *
 * @return SimmMusclePoint that iterator points to before being advanced.
 */
SimmMusclePoint* SimmMusclePointSetIterator::next()
{
	// TODO: what happens when wrap objects are added? Do wrap points get
	// inserted into the set, or are they stored elsewhere?
	if (_counter >= 0)
	{
		while (_counter < _simmMusclePointSet.getSize())
		{
			SimmMusclePoint* smp = _simmMusclePointSet.get(_counter++);
			if (smp->isActive())
				return smp;
		}
	}

	return NULL;
}

//_____________________________________________________________________________
/**
 * Reset iterator to first muscle point.
 */
void SimmMusclePointSetIterator::reset()
{
	_counter = 0;
}

//_____________________________________________________________________________
/**
 * Set iterator to the end (beyond the last muscle point).
 */
void SimmMusclePointSetIterator::end()
{
	_counter = _simmMusclePointSet.getSize();
}
