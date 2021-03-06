/***************************************************************************
 *  Copyright 2017 Marcelo Y. Matuda                                       *
 *                                                                         *
 *  This program is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/

#ifndef VTM_DIFFERENCE_FILTER_H_
#define VTM_DIFFERENCE_FILTER_H_



namespace GS {
namespace VTM {

// Central difference.
template<typename FloatType>
class DifferenceFilter {
public:
	DifferenceFilter();
	~DifferenceFilter() {}

	void reset();
	FloatType filter(FloatType x);
private:
	DifferenceFilter(const DifferenceFilter&) = delete;
	DifferenceFilter& operator=(const DifferenceFilter&) = delete;

	FloatType x1_;
	FloatType x2_;
};



template<typename FloatType>
DifferenceFilter<FloatType>::DifferenceFilter() : x1_{}, x2_{}
{
}

template<typename FloatType>
void
DifferenceFilter<FloatType>::reset()
{
	x1_ = 0.0;
	x2_ = 0.0;
}

template<typename FloatType>
FloatType
DifferenceFilter<FloatType>::filter(FloatType x)
{
	const FloatType y = x - x2_;
	x2_ = x1_;
	x1_ = x;
	return y;
}

} /* namespace VTM */
} /* namespace GS */

#endif /* VTM_DIFFERENCE_FILTER_H_ */
