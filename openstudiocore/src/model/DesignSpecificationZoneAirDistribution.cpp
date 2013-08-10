/**********************************************************************
 *  Copyright (c) 2008-2012, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include <model/DesignSpecificationZoneAirDistribution.hpp>
#include <model/DesignSpecificationZoneAirDistribution_Impl.hpp>
#include <model/Schedule.hpp>
#include <model/Schedule_Impl.hpp>
#include <model/ScheduleTypeLimits.hpp>
#include <model/ScheduleTypeRegistry.hpp>
#include <utilities/idd/OS_DesignSpecification_ZoneAirDistribution_FieldEnums.hxx>
#include <utilities/units/Unit.hpp>
#include <utilities/core/Assert.hpp>

namespace openstudio {
namespace model {

namespace detail {

  DesignSpecificationZoneAirDistribution_Impl::DesignSpecificationZoneAirDistribution_Impl(const IdfObject& idfObject,
                                                                                           Model_Impl* model,
                                                                                           bool keepHandle)
    : ModelObject_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == DesignSpecificationZoneAirDistribution::iddObjectType());
  }

  DesignSpecificationZoneAirDistribution_Impl::DesignSpecificationZoneAirDistribution_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                                                           Model_Impl* model,
                                                                                           bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == DesignSpecificationZoneAirDistribution::iddObjectType());
  }

  DesignSpecificationZoneAirDistribution_Impl::DesignSpecificationZoneAirDistribution_Impl(const DesignSpecificationZoneAirDistribution_Impl& other,
                                                                                           Model_Impl* model,
                                                                                           bool keepHandle)
    : ModelObject_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& DesignSpecificationZoneAirDistribution_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType DesignSpecificationZoneAirDistribution_Impl::iddObjectType() const {
    return DesignSpecificationZoneAirDistribution::iddObjectType();
  }

  std::vector<ScheduleTypeKey> DesignSpecificationZoneAirDistribution_Impl::getScheduleTypeKeys(const Schedule& schedule) const
  {
    std::vector<ScheduleTypeKey> result;
    UnsignedVector fieldIndices = getSourceIndices(schedule.handle());
    UnsignedVector::const_iterator b(fieldIndices.begin()), e(fieldIndices.end());
    if (std::find(b,e,OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessSchedule) != e)
    {
      result.push_back(ScheduleTypeKey("DesignSpecificationZoneAirDistribution","Zone Air Distribution Effectiveness Schedule"));
    }
    return result;
  }

  double DesignSpecificationZoneAirDistribution_Impl::zoneAirDistributionEffectivenessinCoolingMode() const {
    boost::optional<double> value = getDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinCoolingMode,true);
    OS_ASSERT(value);
    return value.get();
  }

  Quantity DesignSpecificationZoneAirDistribution_Impl::getZoneAirDistributionEffectivenessinCoolingMode(bool returnIP) const {
    OptionalDouble value = zoneAirDistributionEffectivenessinCoolingMode();
    OSOptionalQuantity result = getQuantityFromDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinCoolingMode, value, returnIP);
    OS_ASSERT(result.isSet());
    return result.get();
  }

  bool DesignSpecificationZoneAirDistribution_Impl::isZoneAirDistributionEffectivenessinCoolingModeDefaulted() const {
    return isEmpty(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinCoolingMode);
  }

  double DesignSpecificationZoneAirDistribution_Impl::zoneAirDistributionEffectivenessinHeatingMode() const {
    boost::optional<double> value = getDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinHeatingMode,true);
    OS_ASSERT(value);
    return value.get();
  }

  Quantity DesignSpecificationZoneAirDistribution_Impl::getZoneAirDistributionEffectivenessinHeatingMode(bool returnIP) const {
    OptionalDouble value = zoneAirDistributionEffectivenessinHeatingMode();
    OSOptionalQuantity result = getQuantityFromDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinHeatingMode, value, returnIP);
    OS_ASSERT(result.isSet());
    return result.get();
  }

  bool DesignSpecificationZoneAirDistribution_Impl::isZoneAirDistributionEffectivenessinHeatingModeDefaulted() const {
    return isEmpty(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinHeatingMode);
  }

  boost::optional<Schedule> DesignSpecificationZoneAirDistribution_Impl::zoneAirDistributionEffectivenessSchedule() const {
    return getObject<ModelObject>().getModelObjectTarget<Schedule>(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessSchedule);
  }

  double DesignSpecificationZoneAirDistribution_Impl::zoneSecondaryRecirculationFraction() const {
    boost::optional<double> value = getDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneSecondaryRecirculationFraction,true);
    OS_ASSERT(value);
    return value.get();
  }

  Quantity DesignSpecificationZoneAirDistribution_Impl::getZoneSecondaryRecirculationFraction(bool returnIP) const {
    OptionalDouble value = zoneSecondaryRecirculationFraction();
    OSOptionalQuantity result = getQuantityFromDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneSecondaryRecirculationFraction, value, returnIP);
    OS_ASSERT(result.isSet());
    return result.get();
  }

  bool DesignSpecificationZoneAirDistribution_Impl::isZoneSecondaryRecirculationFractionDefaulted() const {
    return isEmpty(OS_DesignSpecification_ZoneAirDistributionFields::ZoneSecondaryRecirculationFraction);
  }

  bool DesignSpecificationZoneAirDistribution_Impl::setZoneAirDistributionEffectivenessinCoolingMode(double zoneAirDistributionEffectivenessinCoolingMode) {
    bool result = setDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinCoolingMode, zoneAirDistributionEffectivenessinCoolingMode);
    return result;
  }

  bool DesignSpecificationZoneAirDistribution_Impl::setZoneAirDistributionEffectivenessinCoolingMode(const Quantity& zoneAirDistributionEffectivenessinCoolingMode) {
    OptionalDouble value = getDoubleFromQuantity(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinCoolingMode,zoneAirDistributionEffectivenessinCoolingMode);
    if (!value) {
      return false;
    }
    return setZoneAirDistributionEffectivenessinCoolingMode(value.get());
  }

  void DesignSpecificationZoneAirDistribution_Impl::resetZoneAirDistributionEffectivenessinCoolingMode() {
    bool result = setString(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinCoolingMode, "");
    OS_ASSERT(result);
  }

  bool DesignSpecificationZoneAirDistribution_Impl::setZoneAirDistributionEffectivenessinHeatingMode(double zoneAirDistributionEffectivenessinHeatingMode) {
    bool result = setDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinHeatingMode, zoneAirDistributionEffectivenessinHeatingMode);
    return result;
  }

  bool DesignSpecificationZoneAirDistribution_Impl::setZoneAirDistributionEffectivenessinHeatingMode(const Quantity& zoneAirDistributionEffectivenessinHeatingMode) {
    OptionalDouble value = getDoubleFromQuantity(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinHeatingMode,zoneAirDistributionEffectivenessinHeatingMode);
    if (!value) {
      return false;
    }
    return setZoneAirDistributionEffectivenessinHeatingMode(value.get());
  }

  void DesignSpecificationZoneAirDistribution_Impl::resetZoneAirDistributionEffectivenessinHeatingMode() {
    bool result = setString(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessinHeatingMode, "");
    OS_ASSERT(result);
  }

  bool DesignSpecificationZoneAirDistribution_Impl::setZoneAirDistributionEffectivenessSchedule(Schedule& schedule) {
    bool result = setSchedule(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessSchedule,
                              "DesignSpecificationZoneAirDistribution",
                              "Zone Air Distribution Effectiveness Schedule",
                              schedule);
    return result;
  }

  void DesignSpecificationZoneAirDistribution_Impl::resetZoneAirDistributionEffectivenessSchedule() {
    bool result = setString(OS_DesignSpecification_ZoneAirDistributionFields::ZoneAirDistributionEffectivenessSchedule, "");
    OS_ASSERT(result);
  }

  bool DesignSpecificationZoneAirDistribution_Impl::setZoneSecondaryRecirculationFraction(double zoneSecondaryRecirculationFraction) {
    bool result = setDouble(OS_DesignSpecification_ZoneAirDistributionFields::ZoneSecondaryRecirculationFraction, zoneSecondaryRecirculationFraction);
    return result;
  }

  bool DesignSpecificationZoneAirDistribution_Impl::setZoneSecondaryRecirculationFraction(const Quantity& zoneSecondaryRecirculationFraction) {
    OptionalDouble value = getDoubleFromQuantity(OS_DesignSpecification_ZoneAirDistributionFields::ZoneSecondaryRecirculationFraction,zoneSecondaryRecirculationFraction);
    if (!value) {
      return false;
    }
    return setZoneSecondaryRecirculationFraction(value.get());
  }

  void DesignSpecificationZoneAirDistribution_Impl::resetZoneSecondaryRecirculationFraction() {
    bool result = setString(OS_DesignSpecification_ZoneAirDistributionFields::ZoneSecondaryRecirculationFraction, "");
    OS_ASSERT(result);
  }

  openstudio::Quantity DesignSpecificationZoneAirDistribution_Impl::zoneAirDistributionEffectivenessinCoolingMode_SI() const {
    return getZoneAirDistributionEffectivenessinCoolingMode(false);
  }

  openstudio::Quantity DesignSpecificationZoneAirDistribution_Impl::zoneAirDistributionEffectivenessinCoolingMode_IP() const {
    return getZoneAirDistributionEffectivenessinCoolingMode(true);
  }

  openstudio::Quantity DesignSpecificationZoneAirDistribution_Impl::zoneAirDistributionEffectivenessinHeatingMode_SI() const {
    return getZoneAirDistributionEffectivenessinHeatingMode(false);
  }

  openstudio::Quantity DesignSpecificationZoneAirDistribution_Impl::zoneAirDistributionEffectivenessinHeatingMode_IP() const {
    return getZoneAirDistributionEffectivenessinHeatingMode(true);
  }

  openstudio::Quantity DesignSpecificationZoneAirDistribution_Impl::zoneSecondaryRecirculationFraction_SI() const {
    return getZoneSecondaryRecirculationFraction(false);
  }

  openstudio::Quantity DesignSpecificationZoneAirDistribution_Impl::zoneSecondaryRecirculationFraction_IP() const {
    return getZoneSecondaryRecirculationFraction(true);
  }

  boost::optional<ModelObject> DesignSpecificationZoneAirDistribution_Impl::zoneAirDistributionEffectivenessScheduleAsModelObject() const {
    OptionalModelObject result;
    OptionalSchedule intermediate = zoneAirDistributionEffectivenessSchedule();
    if (intermediate) {
      result = *intermediate;
    }
    return result;
  }

  bool DesignSpecificationZoneAirDistribution_Impl::setZoneAirDistributionEffectivenessScheduleAsModelObject(const boost::optional<ModelObject>& modelObject) {
    if (modelObject) {
      OptionalSchedule intermediate = modelObject->optionalCast<Schedule>();
      if (intermediate) {
        Schedule schedule(*intermediate);
        return setZoneAirDistributionEffectivenessSchedule(schedule);
      }
      else {
        return false;
      }
    }
    else {
      resetZoneAirDistributionEffectivenessSchedule();
    }
    return true;
  }

} // detail

DesignSpecificationZoneAirDistribution::DesignSpecificationZoneAirDistribution(const Model& model)
  : ModelObject(DesignSpecificationZoneAirDistribution::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>());

}

IddObjectType DesignSpecificationZoneAirDistribution::iddObjectType() {
  return IddObjectType(IddObjectType::OS_DesignSpecification_ZoneAirDistribution);
}

double DesignSpecificationZoneAirDistribution::zoneAirDistributionEffectivenessinCoolingMode() const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->zoneAirDistributionEffectivenessinCoolingMode();
}

Quantity DesignSpecificationZoneAirDistribution::getZoneAirDistributionEffectivenessinCoolingMode(bool returnIP) const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->getZoneAirDistributionEffectivenessinCoolingMode(returnIP);
}

bool DesignSpecificationZoneAirDistribution::isZoneAirDistributionEffectivenessinCoolingModeDefaulted() const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->isZoneAirDistributionEffectivenessinCoolingModeDefaulted();
}

double DesignSpecificationZoneAirDistribution::zoneAirDistributionEffectivenessinHeatingMode() const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->zoneAirDistributionEffectivenessinHeatingMode();
}

Quantity DesignSpecificationZoneAirDistribution::getZoneAirDistributionEffectivenessinHeatingMode(bool returnIP) const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->getZoneAirDistributionEffectivenessinHeatingMode(returnIP);
}

bool DesignSpecificationZoneAirDistribution::isZoneAirDistributionEffectivenessinHeatingModeDefaulted() const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->isZoneAirDistributionEffectivenessinHeatingModeDefaulted();
}

boost::optional<Schedule> DesignSpecificationZoneAirDistribution::zoneAirDistributionEffectivenessSchedule() const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->zoneAirDistributionEffectivenessSchedule();
}

double DesignSpecificationZoneAirDistribution::zoneSecondaryRecirculationFraction() const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->zoneSecondaryRecirculationFraction();
}

Quantity DesignSpecificationZoneAirDistribution::getZoneSecondaryRecirculationFraction(bool returnIP) const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->getZoneSecondaryRecirculationFraction(returnIP);
}

bool DesignSpecificationZoneAirDistribution::isZoneSecondaryRecirculationFractionDefaulted() const {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->isZoneSecondaryRecirculationFractionDefaulted();
}

bool DesignSpecificationZoneAirDistribution::setZoneAirDistributionEffectivenessinCoolingMode(double zoneAirDistributionEffectivenessinCoolingMode) {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->setZoneAirDistributionEffectivenessinCoolingMode(zoneAirDistributionEffectivenessinCoolingMode);
}

bool DesignSpecificationZoneAirDistribution::setZoneAirDistributionEffectivenessinCoolingMode(const Quantity& zoneAirDistributionEffectivenessinCoolingMode) {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->setZoneAirDistributionEffectivenessinCoolingMode(zoneAirDistributionEffectivenessinCoolingMode);
}

void DesignSpecificationZoneAirDistribution::resetZoneAirDistributionEffectivenessinCoolingMode() {
  getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->resetZoneAirDistributionEffectivenessinCoolingMode();
}

bool DesignSpecificationZoneAirDistribution::setZoneAirDistributionEffectivenessinHeatingMode(double zoneAirDistributionEffectivenessinHeatingMode) {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->setZoneAirDistributionEffectivenessinHeatingMode(zoneAirDistributionEffectivenessinHeatingMode);
}

bool DesignSpecificationZoneAirDistribution::setZoneAirDistributionEffectivenessinHeatingMode(const Quantity& zoneAirDistributionEffectivenessinHeatingMode) {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->setZoneAirDistributionEffectivenessinHeatingMode(zoneAirDistributionEffectivenessinHeatingMode);
}

void DesignSpecificationZoneAirDistribution::resetZoneAirDistributionEffectivenessinHeatingMode() {
  getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->resetZoneAirDistributionEffectivenessinHeatingMode();
}

bool DesignSpecificationZoneAirDistribution::setZoneAirDistributionEffectivenessSchedule(Schedule& schedule) {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->setZoneAirDistributionEffectivenessSchedule(schedule);
}

void DesignSpecificationZoneAirDistribution::resetZoneAirDistributionEffectivenessSchedule() {
  getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->resetZoneAirDistributionEffectivenessSchedule();
}

bool DesignSpecificationZoneAirDistribution::setZoneSecondaryRecirculationFraction(double zoneSecondaryRecirculationFraction) {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->setZoneSecondaryRecirculationFraction(zoneSecondaryRecirculationFraction);
}

bool DesignSpecificationZoneAirDistribution::setZoneSecondaryRecirculationFraction(const Quantity& zoneSecondaryRecirculationFraction) {
  return getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->setZoneSecondaryRecirculationFraction(zoneSecondaryRecirculationFraction);
}

void DesignSpecificationZoneAirDistribution::resetZoneSecondaryRecirculationFraction() {
  getImpl<detail::DesignSpecificationZoneAirDistribution_Impl>()->resetZoneSecondaryRecirculationFraction();
}

/// @cond
DesignSpecificationZoneAirDistribution::DesignSpecificationZoneAirDistribution(boost::shared_ptr<detail::DesignSpecificationZoneAirDistribution_Impl> impl)
  : ModelObject(impl)
{}
/// @endcond

} // model
} // openstudio

