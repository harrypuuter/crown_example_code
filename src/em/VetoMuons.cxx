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
ROOT::RDF::RNode VetoMuons_em (ROOT::RDF::RNode df0, OnnxSessionManager &onnxSessionManager, CorrectionManager &correctionManager) {

        auto df1 = physicsobject::VetoCandInMask(df0, "veto_muons_mask", "base_muons_mask", "dileptonpair", 1);
    auto df2 = physicsobject::VetoCandInMask(df1, "veto_muons_mask__eleEsResoDown", "base_muons_mask", "dileptonpair__eleEsResoDown", 1);
    auto df3 = physicsobject::VetoCandInMask(df2, "veto_muons_mask__eleEsScaleUp", "base_muons_mask", "dileptonpair__eleEsScaleUp", 1);
    auto df4 = physicsobject::VetoCandInMask(df3, "veto_muons_mask__eleEsResoUp", "base_muons_mask", "dileptonpair__eleEsResoUp", 1);
    auto df5 = physicsobject::VetoCandInMask(df4, "veto_muons_mask__eleEsScaleDown", "base_muons_mask", "dileptonpair__eleEsScaleDown", 1);
    return df5;

}
