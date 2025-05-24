/******************************************************************************
 *   Copyright (C) 2019 GSI Helmholtzzentrum für Schwerionenforschung GmbH    *
 *   Copyright (C) 2019-2025 Members of R3B Collaboration                     *
 *                                                                            *
 *             This software is distributed under the terms of the            *
 *                 GNU General Public Licence (GPL) version 3,                *
 *                    copied verbatim in the file "LICENSE".                  *
 *                                                                            *
 * In applying this license GSI does not waive the privileges and immunities  *
 * granted to it by virtue of its status as an Intergovernmental Organization *
 * or submit itself to any jurisdiction.                                      *
 ******************************************************************************/

// -----------------------------------------------------------------
// -----                  R3BDeadLGeometry                    -----
// -----       Created 07/10/2022 by J.L. Rodriguez Sanchez    -----
// -----------------------------------------------------------------

#ifndef R3BDeadLGeometry_H
#define R3BDeadLGeometry_H 1

#include "Rtypes.h"
#include "TObject.h"
#include <TFile.h>

class TVector3;
class TGeoNavigator;
class TRotation;

/**
 * Geometrical queries to ALPIDE device
 */

class R3BDeadLGeometry : public TObject
{
  public:
    /** Default constructor */
    R3BDeadLGeometry();

    /** Standard constructor.
     *@param version geometry version
     */
    R3BDeadLGeometry(Int_t version);

    /** Destructor **/
    virtual ~R3BDeadLGeometry();

    /**
     * Gets position in polar coordinates of sensor with given ID.
     * On error, the x, y and z components of the TVector3 are set to NAN.
     * @param iD sensor ID (depending on geometry version)
     */
    const TVector3& GetAngles(Int_t iD);

    /**
     * Gets rotation matrix of sensor with given ID.
     * In case of error, it returns the identity matrix
     * @param iD sensor ID (depending on geometry version)
     */
    const TRotation GetRotation(Int_t iD);

    /**
     * Gets position of sensor with given ID.
     * On error, the x, y and z components of the TVector3 are set to NAN.
     * @param iD sensor ID (depending on geometry version)
     */
    const TVector3& GetTranslation(Int_t iD);

    /**
     * Legacy: Gets position in polar coordinates of sensor with given ID.
     *
     * Before this comment, the last three parameters were untouched on error.
     * Now, they should be set to NAN;
     *
     * @param iD sensor ID (depending on geometry version)
     * @param polar [out] Will be filled with polar angle (radians) of sensor center
     * @param azimuthal [out] Will be filled with azimuthal angle (radians) of sensor center
     * @param rho [out] Will be filled with distance (cm) of sensor center to target position (0,0,0)
     */
    void GetAngles(Int_t iD, Double_t* polar, Double_t* azimuthal, Double_t* rho);

    /**
     * Gets volume path of crystal with given ID.
     *
     * @param iD sensor ID (depending on geometry version)
     * @return Volume path
     */
    const char* GetSensorVolumePath(Int_t iD);

    /**
     * Gets sensor ID for given volume path.
     *
     * @param volumePath Volume path
     * @return sensor ID
     */
    int GetBarrelId(const char* volumePath);

    /**
     * Gets sensor ID for given volume path.
     *
     * @param volumePath Volume path
     * @return sensor ID
     */
    int GetSensorId(const char* volumePath);

    /**
     * @return if we are running the simulation or data analysis
     */
    bool IsSimulation() const { return fIsSimulation; }

    /**
     * Returns singleton instance of R3BDeadLGeometry for given geometry version.
     * @return Instance of R3BDeadLGeometry
     */
    static R3BDeadLGeometry* Instance();

    bool Init(Int_t fGeo);

  private:
    Int_t fGeometryVersion;
    Int_t fNbSensor;
    Bool_t fIsSimulation;
    Bool_t IsInitialize;
    TFile* f;

    ClassDef(R3BDeadLGeometry, 0);
};

#endif /* R3BDeadLGeometry_H */
