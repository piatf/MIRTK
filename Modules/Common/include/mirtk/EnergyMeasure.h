/*
 * Medical Image Registration ToolKit (MIRTK)
 *
 * Copyright 2013-2015 Imperial College London
 * Copyright 2013-2015 Andreas Schuh
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MIRTK_EnergyMeasure_H
#define MIRTK_EnergyMeasure_H

#include "mirtk/String.h"


namespace mirtk {


// -----------------------------------------------------------------------------
/// Enumeration of all available energy terms
enum EnergyMeasure
{
  EM_Unknown, ///< Unknown/invalid energy term
  // Add new enumeration values below
  // ---------------------------------------------------------------------------
  // Image (dis-)similarity measures (cf. ImageSimilarity subclasses)
  SIM_Begin,

    EM_JE,                      ///< Joint entropy
    EM_CC,                      ///< Cross-correlation
    EM_MI,                      ///< Mutual information
    EM_NMI,                     ///< Normalized mutual information
    EM_SSD,                     ///< Sum of squared differences
    EM_CR_XY,                   ///< Correlation ratio
    EM_CR_YX,                   ///< Correlation ratio
    EM_LC,
    EM_K,
    EM_ML,
    EM_NGF_COS,                 ///< Cosine of normalzed gradient field
    EM_LNCC,                    ///< Normalized/Local cross-correlation

  SIM_End,
  // ---------------------------------------------------------------------------
  // Point set distance measures (cf. PointSetDistance subclasses)
  PDM_Begin,

    EM_FRE,                     ///< Fiducial registration error (FRE) measure
    EM_CorrespondenceDistance,  ///< Point correspondence distance measure
    EM_CurrentsDistance,        ///< Distance measure based on currents representation
    EM_VarifoldDistance,        ///< Distance measure based on varifold representation

  PDM_End,
  // ---------------------------------------------------------------------------
  // External point set forces (cf. ExternalForce subclasses)
  EFT_Begin,

    EM_BalloonForce,               ///< Balloon/inflation force
    EM_ImageEdgeForce,             ///< Image edge force
    EM_ImplicitSurfaceDistance,    ///< Implicit surface distance force
    EM_ImplicitSurfaceSpringForce, ///< Implicit surface spring force

  EFT_End,
  // ---------------------------------------------------------------------------
  // Internal point set forces (cf. InternalForce subclasses)
  IFT_Begin,

    EM_MetricDistortion,        ///< Minimize metric distortion
    EM_Stretching,              ///< Stretching force (rest edge length)
    EM_Curvature,               ///< Minimize curvature of point set surface
    EM_QuadraticCurvature,      ///< Quadratic fit of neighor to tangent plane distance
    EM_NonSelfIntersection,     ///< Repels too close non-neighboring triangles
    EM_RepulsiveForce,          ///< Repels too close non-neighboring nodes
    EM_InflationForce,          ///< Inflate point set surface
    EM_SpringForce,             ///< Spring force

  IFT_End,
  // ---------------------------------------------------------------------------
  // Transformation regularization terms (cf. TransformationConstraint subclasses)
  CM_Begin,

    EM_VolumePreservation,      ///< Volume preservation constraint
    EM_TopologyPreservation,    ///< Topology preservation constraint
    EM_Sparsity,                ///< Default sparsity constraint
    EM_BendingEnergy,           ///< Thin-plate spline bending energy
    EM_L0Norm,                  ///< Sparsity constraint based on l0-norm
    EM_L1Norm,                  ///< Sparsity constraint based on l1-norm
    EM_L2Norm,                  ///< Sparsity constraint based on l2-norm
    EM_SqLogDetJac,             ///< Squared logarithm of the Jacobian determinant
    EM_MinDetJac,               ///< Constrain minimum Jacobian determinant

  CM_End,
  // ---------------------------------------------------------------------------
  // Add new enumeration values above
  EM_Last ///< Number of enumeration values + 1
};

// -----------------------------------------------------------------------------
/// Convert energy measure enumeration value to string
template <>
inline string ToString(const EnergyMeasure &value, int w, char c, bool left)
{
  const char *str;
  switch (value) {
    // ---------------------------------------------------------------------------
    // Image (dis-)similarity measures
    case EM_JE:      str = "JE"; break;
    case EM_CC:      str = "CC"; break;
    case EM_MI:      str = "MI"; break;
    case EM_NMI:     str = "NMI"; break;
    case EM_SSD:     str = "SSD"; break;
    case EM_CR_XY:   str = "CR_XY"; break;
    case EM_CR_YX:   str = "CR_YX"; break;
    case EM_LC:      str = "LC"; break;
    case EM_K:       str = "K"; break;
    case EM_ML:      str = "ML"; break;
    case EM_NGF_COS: str = "NGF_COS"; break;
    case EM_LNCC:    str = "LNCC"; break;

    // ---------------------------------------------------------------------------
    // Point set distance measures
    case EM_FRE:                    str = "FRE"; break;
    case EM_CorrespondenceDistance: str = "PCD"; break;
    case EM_CurrentsDistance:       str = "CurrentsDistance"; break;
    case EM_VarifoldDistance:       str = "VarifoldDistance"; break;

    // ---------------------------------------------------------------------------
    // External point set forces
    case EM_BalloonForce:               str = "BalloonForce"; break;
    case EM_ImageEdgeForce:             str = "ImageEdgeForce"; break;
    case EM_ImplicitSurfaceDistance:    str = "ImplicitSurfaceDistance"; break;
    case EM_ImplicitSurfaceSpringForce: str = "ImplicitSurfaceSpringForce"; break;

    // ---------------------------------------------------------------------------
    // Internal point set forces
    case EM_MetricDistortion:    str = "MetricDistortion"; break;
    case EM_Stretching:          str = "Stretching"; break;
    case EM_Curvature:           str = "Curvature"; break;
    case EM_QuadraticCurvature:  str = "QuadraticCurvature"; break;
    case EM_NonSelfIntersection: str = "NSI"; break;
    case EM_RepulsiveForce:      str = "Repulsion"; break;
    case EM_InflationForce:      str = "Inflation"; break;
    case EM_SpringForce:         str = "Spring"; break;

    // -------------------------------------------------------------------------
    // Transformation constraints
    case EM_BendingEnergy:        str = "BE"; break;
    case EM_VolumePreservation:   str = "VP"; break;
    case EM_TopologyPreservation: str = "TP"; break;
    case EM_Sparsity:             str = "Sparsity"; break;
    case EM_L0Norm:               str = "L0"; break;
    case EM_L1Norm:               str = "L1"; break;
    case EM_L2Norm:               str = "L2"; break;
    case EM_SqLogDetJac:          str = "SqLogDetJac"; break;
    case EM_MinDetJac:            str = "MinDetJac"; break;

    // ---------------------------------------------------------------------------
    // Unknown/invalid enumeration value
    default: str = "Unknown";
  }
  return ToString(str, w, c, left);
}

// -----------------------------------------------------------------------------
/// Convert energy measure string to enumeration value
template <>
inline bool FromString(const char *str, EnergyMeasure &value)
{
  value = EM_Unknown;

  // ---------------------------------------------------------------------------
  // Alternative names for image (dis-)similarity measures
  if (value == EM_Unknown) {
    if      (strcmp(str, "NCC") == 0) value = EM_LNCC;
    else if (strcmp(str, "LCC") == 0) value = EM_LNCC;
  }

  // ---------------------------------------------------------------------------
  // Alternative names for point set distance measures
  if (value == EM_Unknown) {
    if (strcmp(str, "Fiducial Registration Error") == 0 ||
        strcmp(str, "Fiducial registration error") == 0 ||
        strcmp(str, "Fiducial Error")              == 0 ||
        strcmp(str, "Fiducial error")              == 0 ||
        strcmp(str, "Landmark Registration Error") == 0 ||
        strcmp(str, "Landmark registration error") == 0 ||
        strcmp(str, "Landmark Error")              == 0 ||
        strcmp(str, "Landmark error")              == 0) {
      value = EM_FRE;
    } else if (strcmp(str, "Point Correspondence Distance") == 0 ||
               strcmp(str, "Point correspondence distance") == 0 ||
               strcmp(str, "Correspondence Distance")       == 0 ||
               strcmp(str, "Correspondence distance")       == 0) {
      value = EM_CorrespondenceDistance;
    } else if (strcmp(str, "Currents distance") == 0 ||
               strcmp(str, "Currents Distance") == 0) {
      value = EM_CurrentsDistance;
    } else if (strcmp(str, "Varifold distance") == 0 ||
               strcmp(str, "Varifold Distance") == 0) {
      value = EM_VarifoldDistance;
    }
  }

  // ---------------------------------------------------------------------------
  // Alternative names for external point set forces
  if (value == EM_Unknown) {
    if (strcmp(str, "EdgeForce") == 0) value = EM_ImageEdgeForce;
  }

  // ---------------------------------------------------------------------------
  // Alternative names for internal point set forces
  if (value == EM_Unknown) {
    if      (strcmp(str, "EdgeLength")          == 0) value = EM_Stretching;
    else if (strcmp(str, "MetricDistortion")    == 0) value = EM_MetricDistortion;
    else if (strcmp(str, "Bending")             == 0) value = EM_Curvature;
    else if (strcmp(str, "SurfaceBending")      == 0) value = EM_Curvature;
    else if (strcmp(str, "SurfaceCurvature")    == 0) value = EM_Curvature;
    else if (strcmp(str, "RepulsiveForce")      == 0) value = EM_RepulsiveForce;
    else if (strcmp(str, "NonSelfIntersection") == 0) value = EM_NonSelfIntersection;
    else if (strcmp(str, "InflationForce")      == 0) value = EM_InflationForce;
    else if (strcmp(str, "SurfaceInflation")    == 0) value = EM_InflationForce;
  }

  // ---------------------------------------------------------------------------
  // Alternative names for transformation regularization terms
  if (value == EM_Unknown) {
    if      (strcmp(str, "JAC")    == 0) value = EM_SqLogDetJac;
    else if (strcmp(str, "MinJac") == 0) value = EM_MinDetJac;
  }

  // ---------------------------------------------------------------------------
  // Convert default names of energy measures (cf. ToString(EnergyMeasure))
  if (value == EM_Unknown) {
    value = static_cast<EnergyMeasure>(EM_Last - 1);
    while (value != EM_Unknown) {
      if (ToString(value) == str) break;
      value = static_cast<EnergyMeasure>(value - 1);
    }
  }

  return (value != EM_Unknown);
}


} // namespace mirtk


namespace std {

/// Compute hash value from EnergyMeasure enumeration value
template<>
struct hash<mirtk::EnergyMeasure> {
    size_t operator()(const mirtk::EnergyMeasure &enum_value) const {
        return std::hash<int>()(enum_value);
    }
};


} // namespace std


#endif // MIRTK_EnergyMeasure_H
