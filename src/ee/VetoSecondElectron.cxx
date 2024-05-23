#include "ROOT/RDataFrame.hxx"
#include "ROOT/RDFHelpers.hxx"
#include "RooTrace.h"
#include "TStopwatch.h"
#include <ROOT/RLogger.hxx>
#include "include/utility/Logger.hxx"
#include <TFile.h>
#include <TMap.h>
#include <filesystem>
#include <TObjString.h>
#include <TTree.h>
#include <TVector.h>
#include "onnxruntime_cxx_api.h"
#include <regex>
#include <string>
#include "include/utility/OnnxSessionManager.hxx"
#include "include/utility/CorrectionManager.hxx"
#include "include/genparticles.hxx"
#include "include/htxs.hxx"
#include "include/jets.hxx"
#include "include/lorentzvectors.hxx"
#include "include/met.hxx"
#include "include/ml.hxx"
#include "include/metfilter.hxx"
#include "include/pairselection.hxx"
#include "include/tripleselection.hxx"
#include "include/physicsobjects.hxx"
#include "include/quantities.hxx"
#include "include/reweighting.hxx"
#include "include/scalefactors.hxx"
#include "include/topreco.hxx"
#include "include/triggers.hxx"
#include "include/fakefactors.hxx"
ROOT::RDF::RNode VetoSecondElectron_ee (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::VetoCandInMask(df0, "veto_electrons_mask_2", "veto_electrons_mask", "dileptonpair", 0);
    auto df2 = physicsobject::VetoCandInMask(df1, "veto_electrons_mask_2__eleEsResoDown", "veto_electrons_mask__eleEsResoDown", "dileptonpair__eleEsResoDown", 0);
    auto df3 = physicsobject::VetoCandInMask(df2, "veto_electrons_mask_2__eleEsScaleUp", "veto_electrons_mask__eleEsScaleUp", "dileptonpair__eleEsScaleUp", 0);
    auto df4 = physicsobject::VetoCandInMask(df3, "veto_electrons_mask_2__eleEsResoUp", "veto_electrons_mask__eleEsResoUp", "dileptonpair__eleEsResoUp", 0);
    auto df5 = physicsobject::VetoCandInMask(df4, "veto_electrons_mask_2__eleEsScaleDown", "veto_electrons_mask__eleEsScaleDown", "dileptonpair__eleEsScaleDown", 0);
    return df5;

}
