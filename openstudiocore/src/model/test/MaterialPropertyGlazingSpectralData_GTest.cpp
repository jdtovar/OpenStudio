/***********************************************************************************************************************
*  OpenStudio(R), Copyright (c) 2008-2018, Alliance for Sustainable Energy, LLC. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
*  following conditions are met:
*
*  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
*  disclaimer.
*
*  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
*  disclaimer in the documentation and/or other materials provided with the distribution.
*
*  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote products
*  derived from this software without specific prior written permission from the respective party.
*
*  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative works
*  may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without specific prior
*  written permission from Alliance for Sustainable Energy, LLC.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND ANY CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
*  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER(S), ANY CONTRIBUTORS, THE UNITED STATES GOVERNMENT, OR THE UNITED
*  STATES DEPARTMENT OF ENERGY, NOR ANY OF THEIR EMPLOYEES, BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
*  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
*  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***********************************************************************************************************************/

#include <gtest/gtest.h>

#include "ModelFixture.hpp"

#include "../Model.hpp"
#include "../Model_Impl.hpp"

#include "../MaterialPropertyGlazingSpectralData.hpp"
#include "../MaterialPropertyGlazingSpectralData_Impl.hpp"

#include "../StandardGlazing.hpp"

using namespace openstudio;
using namespace openstudio::model;

TEST_F(ModelFixture, MaterialPropertyGlazingSpectralData)
{
  Model model;

  MaterialPropertyGlazingSpectralData mpgsd(model);

  EXPECT_EQ(0u, mpgsd.spectralDataFields().size());

  EXPECT_TRUE(mpgsd.addSpectralDataField(0.3, 0.0, 0.045, 0.045));
  EXPECT_EQ(1u, mpgsd.spectralDataFields().size());

  EXPECT_TRUE(mpgsd.addSpectralDataField(SpectralDataField(0.31, 0.0, 0.044, 0.044)));
  EXPECT_EQ(2u, mpgsd.spectralDataFields().size());

  std::vector<SpectralDataField> spectralDataFields = mpgsd.spectralDataFields();
  spectralDataFields.push_back(SpectralDataField(0.32, 0.0, 0.044, 0.044));

  EXPECT_TRUE(mpgsd.setSpectralDataFields(spectralDataFields));
  EXPECT_EQ(3u, mpgsd.spectralDataFields().size());

  StandardGlazing glazing(model);
  EXPECT_EQ("SpectralAverage", glazing.opticalDataType());
  EXPECT_FALSE(glazing.windowGlassSpectralDataSet());

  EXPECT_TRUE(glazing.setWindowGlassSpectralDataSet(mpgsd));
  EXPECT_TRUE(glazing.windowGlassSpectralDataSet());
  EXPECT_EQ("Spectral", glazing.opticalDataType());

  glazing.resetWindowGlassSpectralDataSet();
  EXPECT_EQ("SpectralAverage", glazing.opticalDataType());
  EXPECT_FALSE(glazing.windowGlassSpectralDataSet());

}
